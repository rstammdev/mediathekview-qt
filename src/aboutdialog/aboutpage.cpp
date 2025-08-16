/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutpage.h"


AboutPage::AboutPage(QWidget* parent)
    : QWidget{parent}
{}


QString AboutPage::pageTitle() const
{
    return m_pageTitle;
}

void AboutPage::setPageTitle(const QString& title)
{
    if (title == m_pageTitle)
        return;

    m_pageTitle = title;
    emit pageTitleChanged(title);
}
