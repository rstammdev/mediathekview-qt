/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageapplication.h"

#include <QLabel>
#include <QVBoxLayout>


SettingsPageApplication::SettingsPageApplication(QWidget* parent)
    : SettingsPage{parent}
{
    QLabel* title = new QLabel(tr("<strong style=\"font-size: large;\">%1</strong>").arg(tr("Application")));
    QLabel* description = new QLabel(tr("Configure the general settings of the application."));

    // Tabs

    const QList<SettingsPage*> pages{
        new SettingsPageApplicationTabBehavior(this),
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
    setPageTitle(tr("Application"));
    setPageDescription(tr("Configure the general settings of the application."));
}


void SettingsPageApplication::save()
{
    emit saveRequested();
}


void SettingsPageApplication::restoreDefaults(bool current)
{
    if (current && m_tabBox->currentWidget())
        qobject_cast<SettingsPage*>(m_tabBox->currentWidget())->restoreDefaults(current);
    else
        emit restoreDefaultsRequested(current);
}


//
// Behavior

SettingsPageApplicationTabBehavior::SettingsPageApplicationTabBehavior(QWidget* parent)
    : SettingsPage{parent}
{

    setPageTitle(tr("Behavior"));
    setPageDescription(tr("Configure the behavior of the application."));
}


void SettingsPageApplicationTabBehavior::save()
{

}


void SettingsPageApplicationTabBehavior::restoreDefaults(bool current)
{

}
