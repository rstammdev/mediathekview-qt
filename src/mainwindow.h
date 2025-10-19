/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QActionGroup>
#include <QCloseEvent>
#include <QMainWindow>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void applyZoomFactor(const qreal factor);
    void toggleFullScreen(const bool checked);

    void showLanguageSettingsDialog();
    void showShortcutSettingsDialog();
    void showPanelSettingsDialog();
    void showToolbarSettingsDialog();
    void showSettingsDialog();

    void showComponentsDialog();
    void showAboutDialog();

private:
    void setupUi();

    QActionGroup* m_actionsChannels;

    QAction* m_actionSchemeTheme;
    QAction* m_actionShowMenubar;
    QAction* m_actionShowStatusbar;

    void loadSettings();
    void saveSettings();
};

#endif // MAINWINDOW_H
