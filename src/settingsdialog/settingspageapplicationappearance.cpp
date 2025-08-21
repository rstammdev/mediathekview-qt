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



    QWidget* widget = new QWidget(parent);
    QVBoxLayout* layout = new QVBoxLayout(widget);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageType(SettingsPage::PageTypeBranch);
    setPageTitle(tr("Appearance"));
    setPageDescription(tr("Configure the appearance of the application."));
}
