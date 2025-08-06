/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include <QApplication>
#include <QCommandLineParser>
#include <QDebug>
#include <QLocale>
#include <QTranslator>

#include "mainwindow.h"

using namespace Qt::Literals::StringLiterals;


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setOrganizationName("Ralf Stamm"_L1);
    app.setOrganizationDomain("https://rstammdev.github.io"_L1);
    app.setApplicationName("MediathekView-Qt"_L1);
    app.setApplicationVersion("0.1.0"_L1);
    app.setApplicationDisplayName("MediathekView-Qt"_L1);
    app.setDesktopFileName("io.github.rstamm.mediathekview_qt"_L1);

    QTranslator translator;
    QStringList uiLanguages;
    uiLanguages << QLocale::system().uiLanguages();
    uiLanguages << "en_001"_L1;
    for (const QString& locale : std::as_const(uiLanguages)) {
        const QString baseName = "mediathekview-qt_"_L1 + QLocale(locale).name();
        if (translator.load(":/i18n/"_L1 + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QCommandLineParser parser;
    parser.setApplicationDescription(QCoreApplication::translate("main", "%1 - Frontend tool for the MediathekView database").arg(app.applicationName()));
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(app);

    MainWindow window;
    window.show();

    return app.exec();
}
