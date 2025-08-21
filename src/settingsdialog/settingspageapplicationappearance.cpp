/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageapplicationappearance.h"


SettingsPageApplicationAppearance::SettingsPageApplicationAppearance(QWidget* parent)
    : SettingsPage{parent}
{

    setPageType(SettingsPage::PageTypeBranch);
    setPageTitle(tr("Appearance"));
    setPageDescription(tr("Configure the appearance of the application."));
}
