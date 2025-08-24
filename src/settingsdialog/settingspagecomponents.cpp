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
    setPageTitle(tr("Components"));
    setPageDescription(tr("Specify which information in the Components dialog is shown."));
}
