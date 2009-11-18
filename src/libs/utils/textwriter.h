/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef TEXTWRITER_H
#define TEXTWRITER_H

#include "utils_global.h"

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtGui/QTextCursor>

namespace Utils {

class QTCREATOR_UTILS_EXPORT TextWriter
{
    QString *string;
    QTextCursor *cursor;

    struct Replace {
            int pos;
            int length;
            QString replacement;
    };

    QList<Replace> replaceList;

    struct Move {
            int pos;
            int length;
            int to;
    };

    QList<Move> moveList;

    bool hasOverlap(int pos, int length);
    bool hasMoveInto(int pos, int length);

    void doReplace(const Replace &replace);
    void doMove(const Move &move);

    void write_helper();

public:
    TextWriter();

    void replace(int pos, int length, const QString &replacement);
    void move(int pos, int length, int to);

    void write(QString *s);
    void write(QTextCursor *textCursor);
};

} // namespace Utils

#endif // TEXTWRITER_H
