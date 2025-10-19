/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef CHANNELS_H
#define CHANNELS_H

#include <QList>
#include <QObject>
#include <QStringList>


class Channels : public QObject
{
    Q_OBJECT

public:
    static const QList<QStringList> channels();
};

#endif // CHANNELS_H
