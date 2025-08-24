/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspagecomponents.h"


SettingsPageComponents::SettingsPageComponents(QWidget* parent)
    : SettingsPage{parent}
{

    setPageType(SettingsPage::PageTypeRoot);
    setPageTitle(tr("Components"));
    setPageDescription(tr("Specify which information in the Components dialog is shown."));
}
