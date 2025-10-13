/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialogpagegeneral.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>


AboutDialogPageGeneral::AboutDialogPageGeneral(QWidget* parent)
    : QWidget{parent}
{
    const QStringList paragraphs = {
        tr("<a href=\"https://mediathekview.de\" title=\"Visit MediathekView's homepage\">MediathekView</a> is a free open-source software designed to manage the online multimedia libraries of several German public broadcasters as well as an Austrian, a Swiss and a Franco-German public broadcaster."),
        tr("<a href=\"https://rstammdev.github.io/mediathekview-qt\" title=\"Visit project's homepage\">MediathekView-Qt</a> is a free open-source frontend tool for this MediathekView database written in C++ using the Qt framework."),
        tr("Copyright &copy; 2025 <a href=\"%2\" title=\"Visit organization's homepage\">%1</a>.").arg(QApplication::organizationName(), QApplication::organizationDomain()),
        tr("This program is distributed under the terms of the <a href=\"https://www.gnu.org/licenses/gpl-3.0.en.html\" title=\"Visit license's homepage\">GNU General Public License</a>, either version 3 of the License, or any later version.")
    };

    QString text;
    for (const QString& paragraph : paragraphs) {
        text += tr("<p>%1</p>\n").arg(paragraph);
    }

    QLabel* content = new QLabel;
    content->setText(text);
    content->setTextFormat(Qt::RichText);
    content->setTextInteractionFlags(Qt::TextBrowserInteraction);
    content->setOpenExternalLinks(true);
    content->setWordWrap(true);
    content->setFrameShape(QFrame::StyledPanel);

    //

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);
}
