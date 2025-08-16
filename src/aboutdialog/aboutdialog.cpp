/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialog.h"

#include <QApplication>
#include <QDialogButtonBox>
#include <QVBoxLayout>


AboutDialog::AboutDialog(QWidget* parent)
    : QDialog{parent}
{

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(buttonBox);
    setLayout(layout);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::close);

    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));
    setMinimumSize(640, 480);
}
