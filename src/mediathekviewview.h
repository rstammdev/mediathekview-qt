/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef MEDIATHEKVIEWVIEW_H
#define MEDIATHEKVIEWVIEW_H

#include <QTableView>


class MediathekViewView : public QTableView
{
    Q_OBJECT

public:
    explicit MediathekViewView(QWidget* parent = nullptr);
};

#endif // MEDIATHEKVIEWVIEW_H
