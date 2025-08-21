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
    Q_PROPERTY(PageType pageType READ pageType WRITE setPageType NOTIFY pageTypeChanged)

public:
    enum PageType {
        NoPageType = 0,
        PageTypeRoot,
        PageTypeBranch,
        PageTypeLeaf,
    };
    Q_ENUM(PageType)

    explicit SettingsPage(QWidget* parent = nullptr);
    ~SettingsPage() = default;

    PageType pageType() const;

public slots:
    void setPageType(const SettingsPage::PageType type);

signals:
    void pageTypeChanged(const SettingsPage::PageType type);

private:
    PageType m_pageType;
};

#endif // SETTINGSPAGE_H
