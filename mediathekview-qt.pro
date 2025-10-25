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
    src/aboutdialog/aboutdialogpageauthors.h \
    src/aboutdialog/aboutdialogpagecomponents.h \
    src/aboutdialog/aboutdialogpagecredits.h \
    src/aboutdialog/aboutdialogpagegeneral.h \
    src/aboutdialog/aboutdialogpagelicense.h \
    src/mainwindow.h \
    src/mediathekview.h \
    src/mediathekviewmodel.h \
    src/mediathekviewview.h \
    src/settingsdialog/settingsdialog.h \
    src/settingsdialog/settingspage.h \
    src/settingsdialog/settingspageapplication.h \
    src/settingsdialog/settingspageapplicationappearance.h \
    src/settingsdialog/settingspagecomponents.h \
    src/settingsdialog/settingspageconfirmations.h

SOURCES += \
    src/aboutdialog/aboutdialogpageauthors.cpp \
    src/aboutdialog/aboutdialogpagecomponents.cpp \
    src/aboutdialog/aboutdialogpagecredits.cpp \
    src/aboutdialog/aboutdialogpagegeneral.cpp \
    src/aboutdialog/aboutdialogpagelicense.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/mediathekview.cpp \
    src/mediathekviewmodel.cpp \
    src/mediathekviewview.cpp \
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
