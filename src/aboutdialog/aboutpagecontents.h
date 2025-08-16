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


class AboutPageComponents : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageComponents(QWidget* parent = nullptr);
    ~AboutPageComponents() = default;

private:
    QString prettyPlatformName() const;
};


class AboutPageAuthors : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageAuthors(QWidget* parent = nullptr);
    ~AboutPageAuthors() = default;
};


class AboutPageCredits : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageCredits(QWidget* parent = nullptr);
    ~AboutPageCredits() = default;
};


class AboutPageLicense : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageLicense(QWidget* parent = nullptr);
    ~AboutPageLicense() = default;
};

#endif // ABOUTPAGECONTENTS_H
