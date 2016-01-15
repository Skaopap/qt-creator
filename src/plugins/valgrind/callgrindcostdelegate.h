/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#ifndef CALLGRINDCOSTDELEGATE_H
#define CALLGRINDCOSTDELEGATE_H

#include <QStyledItemDelegate>

namespace Valgrind {
namespace Internal {

class CostDelegate : public QStyledItemDelegate
{
public:
    explicit CostDelegate(QObject *parent = 0);
    virtual ~CostDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setModel(QAbstractItemModel *model);

    enum CostFormat {
        /// show absolute numbers
        FormatAbsolute,
        /// show percentages relative to the total inclusive cost
        FormatRelative,
        /// show percentages relative to the parent cost
        FormatRelativeToParent
    };

    void setFormat(CostFormat format);
    CostFormat format() const;

private:
    class Private;
    Private *d;
};

} // namespace Internal
} // namespace Valgrind

Q_DECLARE_METATYPE(Valgrind::Internal::CostDelegate::CostFormat)

#endif // CALLGRINDCOSTDELEGATE_H
