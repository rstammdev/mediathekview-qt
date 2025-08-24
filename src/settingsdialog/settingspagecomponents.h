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

public slots:
    void save() override;
    void restoreDefaults(bool current) override;

private:
    QTabWidget* m_tabBox;
};


//
// Editor

class SettingsPageComponentsTabEditor : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageComponentsTabEditor(QWidget* parent = nullptr);
    ~SettingsPageComponentsTabEditor() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;
};


//
// Placeholders

class SettingsPageComponentsTabPlaceholders : public SettingsPage
{
    Q_OBJECT

public:
    explicit SettingsPageComponentsTabPlaceholders(QWidget* parent = nullptr);
    ~SettingsPageComponentsTabPlaceholders() = default;

public slots:
    void save() override;
    void restoreDefaults(bool current) override;
};

#endif // SETTINGSPAGECOMPONENTS_H
