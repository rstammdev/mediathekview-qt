/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialog.h"

#include <QApplication>


AboutDialog::AboutDialog(QWidget* parent)
    : QDialog{parent}
{

    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));
    setMinimumSize(640, 480);
}
