/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSPAGE_H
#define SETTINGSPAGE_H

#include <QScrollArea>


class SettingsPage : public QScrollArea
{
    Q_OBJECT

public:
    explicit SettingsPage(QWidget* parent = nullptr);
    ~SettingsPage() = default;
};

#endif // SETTINGSPAGE_H
