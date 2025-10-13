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

using namespace Qt::Literals::StringLiterals;


AboutDialogPageComponents::AboutDialogPageComponents(QWidget* parent)
    : QWidget{parent}
{    const QList<QStringList> items = {
        {
            tr("Application"),
            tr("%1").arg(QApplication::applicationVersion())
        },
        {
            tr("Qt for C++"),
            tr("Using %1 and built against %2").arg(qVersion(), QT_VERSION_STR)
        },
        {
            tr("Operation System"),
            tr("%4 (%5)<br>Running on %6 and compiled for %7<br>Kernel %8 %9").arg(QSysInfo::prettyProductName(), prettyPlatformName(), QSysInfo::currentCpuArchitecture(), QSysInfo::buildAbi(), QSysInfo::kernelType(), QSysInfo::kernelVersion())
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


QString AboutDialogPageComponents::prettyPlatformName() const
{
    const QString& platformName = QApplication::platformName();
    if (platformName == "wayland"_L1) {
        return tr("Wayland");
    } else if (platformName == "xcb"_L1) {
        return tr("X11");
    }

    return tr("Unknown (%1)").arg(platformName);
}
