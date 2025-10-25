/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MEDIATHEKVIEW_H
#define MEDIATHEKVIEW_H

#include <QList>
#include <QObject>
#include <QStringList>


class MediathekView : public QObject
{
    Q_OBJECT

public:
    static const QList<QStringList> channels();
};

#endif // MEDIATHEKVIEW_H
