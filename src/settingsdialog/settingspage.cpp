/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingspage.h"


SettingsPage::SettingsPage(QWidget* parent)
    : QScrollArea{parent}
    , m_pageType{NoPageType}
{}


SettingsPage::PageType SettingsPage::pageType() const
{
    return m_pageType;
}

void SettingsPage::setPageType(const PageType type)
{
    if (type == m_pageType)
        return;

    m_pageType = type;
    emit pageTypeChanged(type);
}


QString SettingsPage::pageTitle() const
{
    return m_pageTitle;
}

void SettingsPage::setPageTitle(const QString& title)
{
    if (title == m_pageTitle)
        return;

    m_pageTitle = title;
    emit pageTitleChanged(title);
}


QString SettingsPage::pageDescription() const
{
    return m_pageDescription;
}

void SettingsPage::setPageDescription(const QString& description)
{
    if (description == m_pageDescription)
        return;

    m_pageDescription = description;
    emit pageDescriptionChanged(description);
}
