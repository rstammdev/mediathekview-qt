/**
 * SPDX-FileComment: Project Homepage: https://github.com/rstammdev/mediathekview-qt
 *
 * SPDX-FileCopyrightText: 2025 Ralf Stamm
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "mediathekviewmodel.h"


MediathekViewModel::MediathekViewModel(QObject* parent)
    : QAbstractItemModel{parent}
{

}


QModelIndex MediathekViewModel::index(int row, int column, const QModelIndex& parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    return createIndex(row, column, nullptr);
}


QModelIndex MediathekViewModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);

    return QModelIndex();
}


int MediathekViewModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 100;
}


int MediathekViewModel::columnCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return 100;
}


QVariant MediathekViewModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role == Qt::DisplayRole)
        return QVariant();

    return QVariant();
}
