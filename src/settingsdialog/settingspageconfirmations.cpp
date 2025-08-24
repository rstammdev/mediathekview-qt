/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageconfirmations.h"


SettingsPageConfirmations::SettingsPageConfirmations(QWidget* parent)
    : SettingsPage{parent}
{

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Confirmations"));
    setPageDescription(tr("Specify which confirmation dialogs should be shown."));
}
