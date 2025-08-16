/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef ABOUTPAGECONTENTS_H
#define ABOUTPAGECONTENTS_H

#include <QWidget>

#include "aboutpage.h"


class AboutPageGeneral : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageGeneral(QWidget* parent = nullptr);
    ~AboutPageGeneral() = default;
};

#endif // ABOUTPAGECONTENTS_H
