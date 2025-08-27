/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef ABOUTPAGECONTENT_H
#define ABOUTPAGECONTENT_H

#include <QWidget>

#include "aboutpage.h"


//
// Authors

class AboutPageAuthors : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageAuthors(QWidget* parent = nullptr);
    ~AboutPageAuthors() = default;
};


//
// Components

class AboutPageComponents : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageComponents(QWidget* parent = nullptr);
    ~AboutPageComponents() = default;

private:
    QString prettyPlatformName() const;
};


//
// Credits

class AboutPageCredits : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageCredits(QWidget* parent = nullptr);
    ~AboutPageCredits() = default;
};


//
// General

class AboutPageGeneral : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageGeneral(QWidget* parent = nullptr);
    ~AboutPageGeneral() = default;
};


//
// License

class AboutPageLicense : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageLicense(QWidget* parent = nullptr);
    ~AboutPageLicense() = default;
};

#endif // ABOUTPAGECONTENT_H
