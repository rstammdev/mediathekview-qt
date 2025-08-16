/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "aboutpagecontents.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

using namespace Qt::Literals::StringLiterals;


AboutPageGeneral::AboutPageGeneral(QWidget* parent)
    : AboutPage{parent}
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

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);

    setPageTitle(tr("General"));
}


AboutPageComponents::AboutPageComponents(QWidget* parent)
    : AboutPage{parent}
{
    const QList<QStringList> items = {
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

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(content);
    layout->addStretch();
    setLayout(layout);

    setPageTitle(tr("Components"));
}


QString AboutPageComponents::prettyPlatformName() const
{
    const QString& platformName = QApplication::platformName();
    if (platformName == "wayland"_L1) {
        return tr("Wayland");
    } else if (platformName == "xcb"_L1) {
        return tr("X11");
    }

    return tr("Unknown (%1)").arg(platformName);
}


AboutPageAuthors::AboutPageAuthors(QWidget* parent)
    : AboutPage{parent}
{

    setPageTitle(tr("Authors"));
}
