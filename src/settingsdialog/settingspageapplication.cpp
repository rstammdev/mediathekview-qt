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



    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();

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

}


void SettingsPageApplication::restoreDefaults(bool current)
{

}
