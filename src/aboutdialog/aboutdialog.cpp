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
#include <QTabWidget>
#include <QVBoxLayout>

#include <qxdialogheaderbox.h>

using namespace Qt::Literals::StringLiterals;


AboutDialog::AboutDialog(QWidget* parent)
    : QDialog{parent}
{
    // Header

    QxDialogHeaderBox* headerBox = new QxDialogHeaderBox(this);
    headerBox->setTitle(QApplication::applicationName());
    headerBox->setSubTitle(tr("v%1").arg(QApplication::applicationVersion()));
    headerBox->setDescription(tr("Frontend tool for the MediathekView database."));
    headerBox->setIcon(QIcon::fromTheme("mediathekview-qt"_L1, QIcon(":/icons/apps/16/mediathekview-qt"_L1)));

    // Pages

    QTabWidget* tabBox = new QTabWidget;

    // Button

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::close);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(headerBox);
    layout->addWidget(tabBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));
    setMinimumSize(854, 480);
}
