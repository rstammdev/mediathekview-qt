/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGEAPPLICATIONAPPEARANCE_H
#define SETTINGSPAGEAPPLICATIONAPPEARANCE_H

#include <QWidget>

#include "settingspage.h"


class SettingsPageApplicationAppearance : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationAppearance(QWidget* parent = nullptr);
    ~SettingsPageApplicationAppearance() = default;

public slots:
    void save() override;
};

#endif // SETTINGSPAGEAPPLICATIONAPPEARANCE_H
