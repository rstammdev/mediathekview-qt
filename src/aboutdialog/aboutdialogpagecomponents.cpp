/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutdialogpagecomponents.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

#include <qxsysinfo.h>

using namespace Qt::Literals::StringLiterals;


AboutDialogPageComponents::AboutDialogPageComponents(QWidget* parent)
    : QWidget{parent}
{
    const QList<QStringList> items = {
        {
            tr("Application"),
            tr("%1").arg(QApplication::applicationVersion())
        },
        {
            tr("Qt for C++"),
            tr("Using %1 and built against %2").arg(QxSysInfo::currentQtVersion(), QxSysInfo::buildQtVersion())
        },
        {
            tr("Operation System"),
            tr("%1 (%2)<br>Running on %3 and compiled for %4<br>Kernel %5 %6").arg(QxSysInfo::prettyProductName(), QxSysInfo::prettyPlatformName(), QxSysInfo::currentCpuArchitecture(), QxSysInfo::buildAbi(), QxSysInfo::kernelType(), QxSysInfo::kernelVersion())
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
