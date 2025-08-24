/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "settingsdialog.h"

#include <QActionGroup>
#include <QApplication>
#include <QDialogButtonBox>
#include <QHBoxLayout>
#include <QMenu>
#include <QTreeWidget>
#include <QVBoxLayout>

#include "settingspage.h"
#include "settingspageapplication.h"
#include "settingspageapplicationappearance.h"

using namespace Qt::Literals::StringLiterals;


SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog{parent}
{
    // Pages

    const QList<SettingsPage*> pages{
        new SettingsPageApplication(this),
        new SettingsPageApplicationAppearance(this),
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

            connect(page, &SettingsPage::stateChanged, this, &SettingsDialog::enableButtonApply);
            connect(this, &SettingsDialog::saveRequested, page, &SettingsPage::save);
            connect(this, &SettingsDialog::restoreDefaultsRequested, page, &SettingsPage::restoreDefaults);
        }
    }

    QHBoxLayout* layoutPages = new QHBoxLayout;
    layoutPages->addWidget(treePages, 1);
    layoutPages->addWidget(m_stackedPages, 3);

    connect(treePages, &QTreeWidget::currentItemChanged, this, &SettingsDialog::setCurrentPage);

    // Buttons

    m_buttonRestoreDefaults = new QToolButton;
    m_buttonRestoreDefaults->setText(tr("Defaults"));
    m_buttonRestoreDefaults->setIcon(QIcon::fromTheme("document-revert"_L1, QIcon(":/icons/actions/16/document-revert"_L1)));
    m_buttonRestoreDefaults->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QActionGroup* actionsRestoreDefaults = new QActionGroup(m_buttonRestoreDefaults);

    m_actionRestoreDefaultsCurrent = new QAction(tr("Restore this page only"), actionsRestoreDefaults);
    m_actionRestoreDefaultsCurrent->setCheckable(true);
    actionsRestoreDefaults->addAction(m_actionRestoreDefaultsCurrent);

    m_actionRestoreDefaultsAll = new QAction(tr("Restore all settings"), actionsRestoreDefaults);
    m_actionRestoreDefaultsAll->setCheckable(true);
    actionsRestoreDefaults->addAction(m_actionRestoreDefaultsAll);

    QMenu* menuRestoreDefaults = new QMenu(m_buttonRestoreDefaults);
    menuRestoreDefaults->addActions(actionsRestoreDefaults->actions());

    m_buttonRestoreDefaults->setMenu(menuRestoreDefaults);
    m_buttonRestoreDefaults->setPopupMode(QToolButton::MenuButtonPopup);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    m_buttonApply = buttonBox->addButton(QDialogButtonBox::Apply);
    buttonBox->addButton(m_buttonRestoreDefaults, QDialogButtonBox::ResetRole);

    connect(buttonBox, &QDialogButtonBox::rejected, this, &SettingsDialog::close);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &SettingsDialog::saveAndClose);
    connect(m_buttonApply, &QPushButton::clicked, this, &SettingsDialog::saveAndContinue);
    connect(m_buttonRestoreDefaults, &QToolButton::clicked, this, &SettingsDialog::restoreDefaults);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addLayout(layoutPages);
    layout->addWidget(buttonBox);
    setLayout(layout);

    setWindowTitle(tr("Configure %1").arg(QApplication::applicationName()));
    setMinimumSize(1024, 576);

    treePages->setCurrentItem(treePages->topLevelItem(0));

    m_buttonApply->setEnabled(false);

    m_actionRestoreDefaultsCurrent->setChecked(true);
}


void SettingsDialog::setCurrentPage(QTreeWidgetItem* current)
{
    if (!current)
        return;

    m_stackedPages->setCurrentIndex(current->data(0, Qt::UserRole).toInt());
}


void SettingsDialog::enableButtonApply()
{
    m_buttonApply->setEnabled(true);
}


void SettingsDialog::saveAndClose()
{
    emit saveRequested();

    accept();
}


void SettingsDialog::saveAndContinue()
{
    emit saveRequested();

    m_buttonApply->setEnabled(false);
}


void SettingsDialog::restoreDefaults()
{
    if (m_actionRestoreDefaultsCurrent->isChecked() && m_stackedPages->currentWidget())
        qobject_cast<SettingsPage*>(m_stackedPages->currentWidget())->restoreDefaults(true);
    else
        emit restoreDefaultsRequested(false);

    m_actionRestoreDefaultsCurrent->setChecked(true);
}
