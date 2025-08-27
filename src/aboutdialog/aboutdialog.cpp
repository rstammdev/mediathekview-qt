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

#include "aboutpage.h"
#include "aboutpagecontent.h"


AboutDialog::AboutDialog(QWidget* parent)
    : QDialog{parent}
{

    QTabWidget* tabBox = new QTabWidget;

    const QList<AboutPage*> pages{
        new AboutPageGeneral,
        new AboutPageComponents,
        new AboutPageAuthors,
        new AboutPageCredits,
        new AboutPageLicense
    };

    for (const auto page : pages)
        tabBox->addTab(page, page->pageTitle());

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Close);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(tabBox);
    layout->addWidget(buttonBox);
    setLayout(layout);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &AboutDialog::close);

    setWindowTitle(tr("About %1").arg(QApplication::applicationName()));
    setMinimumSize(854, 480);
}
