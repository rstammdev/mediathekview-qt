/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef ABOUTPAGE_H
#define ABOUTPAGE_H

#include <QWidget>


class AboutPage : public QWidget
{
    Q_OBJECT

public:
    explicit AboutPage(QWidget* parent = nullptr);
    ~AboutPage() = default;
};

#endif // ABOUTPAGE_H
