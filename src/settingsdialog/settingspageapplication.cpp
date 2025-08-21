/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspageapplication.h"


SettingsPageApplication::SettingsPageApplication(QWidget* parent)
    : SettingsPage{parent}
{

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Application"));
    setPageDescription(tr("Configure the general settings of the application."));
}
