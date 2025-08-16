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
    Q_PROPERTY(QString pageTitle READ pageTitle WRITE setPageTitle NOTIFY pageTitleChanged)

public:
    explicit AboutPage(QWidget* parent = nullptr);
    ~AboutPage() = default;

    QString pageTitle() const;

public slots:
    void setPageTitle(const QString& title);

signals:
    void pageTitleChanged(const QString& title);

private:
    QString m_pageTitle;
};

#endif // ABOUTPAGE_H
