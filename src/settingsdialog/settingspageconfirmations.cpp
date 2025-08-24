/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageconfirmations.h"

#include <QLabel>
#include <QVBoxLayout>


SettingsPageConfirmations::SettingsPageConfirmations(QWidget* parent)
    : SettingsPage{parent}
{
    QLabel* title = new QLabel(tr("<strong style=\"font-size: large;\">%1</strong>").arg(tr("Confirmations")));
    QLabel* description = new QLabel(tr("Specify which confirmation dialogs should be shown."));



    QVBoxLayout* layout = new QVBoxLayout;
    layout->setContentsMargins(-1, -1, 0, 0);
    layout->addWidget(title);
    layout->addWidget(description);
    layout->addStretch();

    QWidget* widget = new QWidget(parent);
    widget->setLayout(layout);

    setWidget(widget);
    setWidgetResizable(true);
    setFrameShape(QFrame::NoFrame);

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Confirmations"));
    setPageDescription(tr("Specify which confirmation dialogs should be shown."));
}


void SettingsPageConfirmations::save()
{

}


void SettingsPageConfirmations::restoreDefaults(bool current)
{

}
