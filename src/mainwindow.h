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

#include "mediathekviewmodel.h"
#include "mediathekviewview.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum ChannelItemStyle {
        NoStyles = 0x00,
        Bold = 0x01,
        Italic = 0x02,
        StrikeOut = 0x04,
    };
    Q_ENUM(ChannelItemStyle)
    Q_DECLARE_FLAGS(ChannelItemStyles, ChannelItemStyle)
    Q_FLAG(ChannelItemStyles)

    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void updateActionsChannels();

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
    MediathekViewModel* m_mediathekViewModel;
    MediathekViewView* m_mediathekViewView;

    ChannelItemStyles m_channelItemStyles;

    void setupUi();

    QActionGroup* m_actionsChannels;

    QAction* m_actionInvertChannels;

    QAction* m_actionSchemeTheme;
    QAction* m_actionShowMenubar;
    QAction* m_actionShowStatusbar;

    void loadSettings();
    void saveSettings();
};

Q_DECLARE_OPERATORS_FOR_FLAGS(MainWindow::ChannelItemStyles)

#endif // MAINWINDOW_H
