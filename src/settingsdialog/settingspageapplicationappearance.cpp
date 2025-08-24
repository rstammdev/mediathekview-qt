/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageapplicationappearance.h"

#include <QLabel>
#include <QVBoxLayout>


SettingsPageApplicationAppearance::SettingsPageApplicationAppearance(QWidget* parent)
    : SettingsPage{parent}
{
    QLabel* title = new QLabel(tr("<strong style=\"font-size: large;\">%1</strong>").arg(tr("Appearance")));
    QLabel* description = new QLabel(tr("Configure the appearance of the application."));

    // Tabs

    const QList<SettingsPage*> pages{
        new SettingsPageApplicationAppearanceTabZoomButton(this),
    };

    m_tabBox = new QTabWidget;

    for (const auto page : pages) {

        m_tabBox->addTab(page, page->pageTitle());
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

    setPageType(SettingsPage::PageTypeBranch);
    setPageTitle(tr("Appearance"));
    setPageDescription(tr("Configure the appearance of the application."));
}


void SettingsPageApplicationAppearance::save()
{

}


void SettingsPageApplicationAppearance::restoreDefaults(bool current)
{

}


//
// Zoom Button

SettingsPageApplicationAppearanceTabZoomButton::SettingsPageApplicationAppearanceTabZoomButton(QWidget* parent)
    : SettingsPage{parent}
{

    setPageTitle(tr("Zoom Button"));
    setPageDescription(tr("Configure the zoom button."));
}
