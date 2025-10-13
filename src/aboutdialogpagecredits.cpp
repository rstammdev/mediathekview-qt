/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialogpagecredits.h"

#include <QLabel>
#include <QVBoxLayout>


AboutDialogPageCredits::AboutDialogPageCredits(QWidget* parent)
    : QWidget{parent}
{
    const QList<QStringList> items = {
        {
            tr("Bootstrap Icons project"),
            tr("Application logo made by <a href=\"https://icons.getbootstrap.com\" title=\"Visit project's homepage\">Bootstrap Icons</a> from <a href=\"https://getbootstrap.com\" title=\"Visit organization's homepage\">Bootstrap</a> is licensed under <a href=\"https://opensource.org/license/mit\" title=\"Visit license's homepage\">MIT</a>.")
        },
        {
            tr("Breeze Icons project"),
            tr("Application icons made by <a href=\"https://api.kde.org/frameworks/breeze-icons/html/\" title=\"Visit project's homepage\">Breeze Icons</a> from <a href=\"https://kde.org\" title=\"Visit organization's homepage\">KDE</a> are licensed under <a href=\"https://www.gnu.org/licenses/lgpl-3.0.en.html\" title=\"Visit license's homepage\">LGPLv3</a>.")
        }
    };

    QString text = tr("<dl>");
    for (QStringList item : items) {
        text += tr("<dt><strong>%1</strong></dt>").arg(item[0]);
        text += tr("<dd>%1</dd>").arg(item[1]);
    }
    text += tr("</dl>");

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
