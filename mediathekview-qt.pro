#
# SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
#
# SPDX-FileCopyrightText: 2025 Ralf Stamm
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

TEMPLATE = app
TARGET = mediathekview-qt

!versionAtLeast(QT_VERSION, 6.5): error("Requires at least Qt 6.5")

QT += core gui widgets

CONFIG += c++23
CONFIG += lrelease
CONFIG += embed_translations

DEFINES += QT_DEPRECATED_WARNINGS

include(3rdparty/qtxt/qtxt.pri)

HEADERS += \
    src/aboutdialogpageauthors.h \
    src/aboutdialogpagecomponents.h \
    src/aboutdialogpagecredits.h \
    src/aboutdialogpagegeneral.h \
    src/aboutdialogpagelicense.h \
    src/mainwindow.h \
    src/settingsdialog/settingsdialog.h \
    src/settingsdialog/settingspage.h \
    src/settingsdialog/settingspageapplication.h \
    src/settingsdialog/settingspageapplicationappearance.h \
    src/settingsdialog/settingspagecomponents.h \
    src/settingsdialog/settingspageconfirmations.h

SOURCES += \
    src/aboutdialogpageauthors.cpp \
    src/aboutdialogpagecomponents.cpp \
    src/aboutdialogpagecredits.cpp \
    src/aboutdialogpagegeneral.cpp \
    src/aboutdialogpagelicense.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/settingsdialog/settingsdialog.cpp \
    src/settingsdialog/settingspage.cpp \
    src/settingsdialog/settingspageapplication.cpp \
    src/settingsdialog/settingspageapplicationappearance.cpp \
    src/settingsdialog/settingspagecomponents.cpp \
    src/settingsdialog/settingspageconfirmations.cpp

RESOURCES += \
    res/icons.qrc

TRANSLATIONS += \
    i18n/mediathekview-qt_en_001.ts

DISTFILES += \
    README.md

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
