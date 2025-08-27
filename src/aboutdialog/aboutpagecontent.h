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

class AboutPageContentTabAuthors : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabAuthors(QWidget* parent = nullptr);
    ~AboutPageContentTabAuthors() = default;
};


//
// Components

class AboutPageContentTabComponents : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabComponents(QWidget* parent = nullptr);
    ~AboutPageContentTabComponents() = default;

private:
    QString prettyPlatformName() const;
};


//
// Credits

class AboutPageContentTabCredits : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabCredits(QWidget* parent = nullptr);
    ~AboutPageContentTabCredits() = default;
};


//
// General

class AboutPageContentTabGeneral : public AboutPage
{
    Q_OBJECT

public:
    explicit AboutPageContentTabGeneral(QWidget* parent = nullptr);
    ~AboutPageContentTabGeneral() = default;
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
