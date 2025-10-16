/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialogpagelicense.h"

#include <QLabel>
#include <QVBoxLayout>


AboutDialogPageLicense::AboutDialogPageLicense(QWidget* parent)
    : QWidget{parent}
{
    const QStringList paragraphs = {
        tr("This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version."),
        tr("This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details."),
        tr("You should have received a copy of the GNU General Public License along with this program. If not, see <a href=\"https://www.gnu.org/licenses/\" title=\"Visit license's homepage\">https://www.gnu.org/licenses/</a>.")
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
