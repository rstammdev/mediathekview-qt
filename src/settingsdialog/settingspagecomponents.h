/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGECOMPONENTS_H
#define SETTINGSPAGECOMPONENTS_H

#include <QTabWidget>
#include <QWidget>

#include "settingspage.h"


class SettingsPageComponents : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageComponents(QWidget* parent = nullptr);
    ~SettingsPageComponents() = default;

private:
    QTabWidget* m_tabBox;
};

#endif // SETTINGSPAGECOMPONENTS_H
