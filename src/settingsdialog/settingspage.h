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
    Q_PROPERTY(QString pageTitle READ pageTitle WRITE setPageTitle NOTIFY pageTitleChanged)
    Q_PROPERTY(QString pageDescription READ pageDescription WRITE setPageDescription NOTIFY pageDescriptionChanged)

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
    QString pageTitle() const;
    QString pageDescription() const;

public slots:
    void setPageType(const SettingsPage::PageType type);
    void setPageTitle(const QString& title);
    void setPageDescription(const QString& description);

signals:
    void pageTypeChanged(const SettingsPage::PageType type);
    void pageTitleChanged(const QString& title);
    void pageDescriptionChanged(const QString& description);

    void stateChanged();

    void saveRequested();

private:
    PageType m_pageType;
    QString m_pageTitle;
    QString m_pageDescription;
};

#endif // SETTINGSPAGE_H
