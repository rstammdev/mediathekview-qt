/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingsdialog.h"

#include <QApplication>


SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog{parent}
{

    setWindowTitle(tr("Configure %1").arg(QApplication::applicationName()));
    setMinimumSize(1024, 576);

}
