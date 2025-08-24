/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspagecomponents.h"

#include <QLabel>
#include <QVBoxLayout>


SettingsPageComponents::SettingsPageComponents(QWidget* parent)
    : SettingsPage{parent}
{
    QLabel* title = new QLabel(tr("<strong style=\"font-size: large;\">%1</strong>").arg(tr("Components")));
    QLabel* description = new QLabel(tr("Specify which information in the components dialog is shown."));

    // Tabs

    const QList<SettingsPage*> pages{
        new SettingsPageComponentsTabEditor(this),
        new SettingsPageComponentsTabPlaceholders(this),
    };

    m_tabBox = new QTabWidget;

    for (const auto page : pages) {

        m_tabBox->addTab(page, page->pageTitle());

        connect(page, &SettingsPage::stateChanged, this, &SettingsPage::stateChanged);
        connect(this, &SettingsPage::saveRequested, page, &SettingsPage::save);
        connect(this, &SettingsPage::restoreDefaultsRequested, page, &SettingsPage::restoreDefaults);
    }

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addWidget(m_tabBox);

    QWidget* widget = new QWidget(parent);
    widget->setLayout(layout);

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Components"));
    setPageDescription(tr("Specify which information in the Components dialog is shown."));
}


void SettingsPageComponents::save()
{
    emit saveRequested();
}


void SettingsPageComponents::restoreDefaults(bool current)
{
    if (current && m_tabBox->currentWidget())
        qobject_cast<SettingsPage*>(m_tabBox->currentWidget())->restoreDefaults(current);
    else
        emit restoreDefaultsRequested(current);
}


//
// Editor

SettingsPageComponentsTabEditor::SettingsPageComponentsTabEditor(QWidget* parent)
    : SettingsPage{parent}
{

    setPageTitle(tr("Editor"));
    setPageDescription(tr("Edit the information in the components dialog."));
}


void SettingsPageComponentsTabEditor::save()
{

}


void SettingsPageComponentsTabEditor::restoreDefaults(bool current)
{

}


//
// Placeholders

SettingsPageComponentsTabPlaceholders::SettingsPageComponentsTabPlaceholders(QWidget* parent)
    : SettingsPage{parent}
{

    setPageTitle(tr("Placeholders"));
    setPageDescription(tr("List of all available placeholders."));
}


void SettingsPageComponentsTabPlaceholders::save()
{

}
