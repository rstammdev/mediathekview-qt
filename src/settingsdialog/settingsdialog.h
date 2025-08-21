/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QAction>
#include <QDialog>
#include <QPushButton>
#include <QStackedWidget>
#include <QToolButton>
#include <QTreeWidgetItem>


class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget* parent = nullptr);
    ~SettingsDialog() = default;

signals:
    void saveRequested();
    void restoreDefaultsRequested(bool current);

private slots:
    void setCurrentPage(QTreeWidgetItem* current);

    void enableButtonApply();

    void saveAndClose();
    void saveAndContinue();
    void restoreDefaults();

private:
    QStackedWidget* m_stackedPages;

    QPushButton* m_buttonApply;

    QAction* m_actionRestoreDefaultsCurrent;
    QAction* m_actionRestoreDefaultsAll;

    QToolButton* m_buttonRestoreDefaults;
};

#endif // SETTINGSDIALOG_H
