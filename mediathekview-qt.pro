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

HEADERS += \
    src/aboutdialog/aboutdialog.h \
    src/aboutdialog/aboutpage.h \
    src/aboutdialog/aboutpagecontents.h \
    src/mainwindow.h \
    src/settingsdialog/settingsdialog.h

SOURCES += \
    src/aboutdialog/aboutdialog.cpp \
    src/aboutdialog/aboutpage.cpp \
    src/aboutdialog/aboutpagecontents.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/settingsdialog/settingsdialog.cpp

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
