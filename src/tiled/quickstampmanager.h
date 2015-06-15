/*
 * quickstampmanager.h
 * Copyright 2010-2011, Stefan Beller <stefanbeller@googlemail.com>
 * Copyright 2014-2015, Thorbjørn Lindeijer <bjorn@lindeijer.nl>
 *
 * This file is part of Tiled.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef QUICKSTAMPMANAGER_H
#define QUICKSTAMPMANAGER_H

#include <QObject>
#include <QVector>

namespace Tiled {

class Map;
class TileLayer;

namespace Internal {

class AbstractTool;
class MapDocument;
class TileStamp;
class TileStampModel;

/**
 * Implements a manager which handles lots of copy&paste slots.
 * Ctrl + <1..9> will store tile layers, and just <1..9> will recall these
 * tile layers.
 */
class QuickStampManager: public QObject
{
    Q_OBJECT

public:
    QuickStampManager(QObject *parent = 0);
    ~QuickStampManager();

    /**
     * Return the keys which should be used.
     * Note: To store a tile layer <Ctrl> is added. The given keys will work
     * for recalling the stored values
     */
    static QList<Qt::Key> keys() {
        QList<Qt::Key> keys;
        keys << Qt::Key_1
             << Qt::Key_2
             << Qt::Key_3
             << Qt::Key_4
             << Qt::Key_5
             << Qt::Key_6
             << Qt::Key_7
             << Qt::Key_8
             << Qt::Key_9;
        return keys;
    }

    TileStampModel *tileStampModel() const;

public slots:
    void selectQuickStamp(int index);
    void saveQuickStamp(int index, AbstractTool *selectedTool);
    void extendQuickStamp(int index, AbstractTool *selectedTool);

signals:
    void setStamp(const TileStamp &stamp);

private:
    Q_DISABLE_COPY(QuickStampManager)

    void eraseQuickStamp(int index);
    void saveQuickStamp(int index, TileStamp stamp);

    QVector<TileStamp> mQuickStamps;
    TileStampModel *mTileStampModel;
};

} // namespace Tiled::Internal
} // namespace Tiled

#endif // QUICKSTAMPMANAGER_H
