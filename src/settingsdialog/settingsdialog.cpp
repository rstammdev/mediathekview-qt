/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingsdialog.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "settingspage.h"


SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Pages

    const QList<SettingsPage*> pages{
    };

    QTreeWidget* treePages = new QTreeWidget;
    treePages->setHeaderHidden(true);
    treePages->setRootIsDecorated(false);

    QTreeWidgetItem* treeItemRoot = nullptr;
    QTreeWidgetItem* treeItemBranch = nullptr;

    m_stackedPages = new QStackedWidget;

    for (const auto page : pages) {

        QTreeWidgetItem* treeItem = nullptr;

        if (page->pageType() == SettingsPage::PageTypeRoot) {
            treeItem = treeItemRoot = new QTreeWidgetItem(treePages);
            treePages->expandItem(treeItem);
        }
        else if (page->pageType() == SettingsPage::PageTypeBranch) {
            treeItem = treeItemBranch = new QTreeWidgetItem(treeItemRoot);
        }
        else if (page->pageType() == SettingsPage::PageTypeLeaf) {
            treeItem = new QTreeWidgetItem(treeItemBranch);
        }

        if (treeItem) {
            treeItem->setText(0, page->pageTitle());
            treeItem->setToolTip(0, page->pageDescription());
            treeItem->setData(0, Qt::UserRole, m_stackedPages->addWidget(page));

            connect(this, &SettingsDialog::saveRequested, page, &SettingsPage::save);
            connect(this, &SettingsDialog::restoreDefaultsRequested, page, &SettingsPage::restoreDefaults);
        }
    }

    QHBoxLayout* layoutPages = new QHBoxLayout;
    layoutPages->addWidget(treePages, 1);
    layoutPages->addWidget(m_stackedPages, 3);

    connect(treePages, &QTreeWidget::currentItemChanged, this, &SettingsDialog::setCurrentPage);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutPages);
    setLayout(layout);

    setWindowTitle(tr("Configure %1").arg(QApplication::applicationName()));
    setMinimumSize(1024, 576);

    treePages->setCurrentItem(treePages->topLevelItem(0));
}


void SettingsDialog::setCurrentPage(QTreeWidgetItem* current)
{
    if (!current)
        return;

    m_stackedPages->setCurrentIndex(current->data(0, Qt::UserRole).toInt());
}
