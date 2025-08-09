/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mainwindow.h"

#include <QSettings>

using namespace Qt::Literals::StringLiterals;


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{

    loadSettings();

    setWindowIcon(QIcon::fromTheme("mediathekview-qt"_L1, QIcon(":/icons/apps/16/mediathekview-qt"_L1)));
    setMinimumSize(854, 480);

}

MainWindow::~MainWindow() {}


void MainWindow::closeEvent(QCloseEvent *event)
{

    event->accept();

}


void MainWindow::loadSettings()
{
    QSettings settings;

    const QByteArray geometry = settings.value("Application/Geometry"_L1).toByteArray();
    if (!geometry.isEmpty())
        restoreGeometry(geometry);
    else
        resize(1280, 720);

}
