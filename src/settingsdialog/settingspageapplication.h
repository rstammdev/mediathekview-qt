/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGEAPPLICATION_H
#define SETTINGSPAGEAPPLICATION_H

#include <QTabWidget>
#include <QWidget>

#include "settingspage.h"


class SettingsPageApplication : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplication(QWidget* parent = nullptr);
    ~SettingsPageApplication() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;

private:
    QTabWidget* m_tabBox;
};


//
// Behavior

class SettingsPageApplicationTabBehavior : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageApplicationTabBehavior(QWidget* parent = nullptr);
    ~SettingsPageApplicationTabBehavior() = default;
};

#endif // SETTINGSPAGEAPPLICATION_H
