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

#ifndef ENVIRONMENTITEMSWIDGET_H
#define ENVIRONMENTITEMSWIDGET_H

#include <QDialog>

namespace Utils { class EnvironmentItem; }

namespace ProjectExplorer {
class EnvironmentItemsWidgetPrivate;

class EnvironmentItemsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EnvironmentItemsWidget(QWidget *parent = 0);
    ~EnvironmentItemsWidget();

    void setEnvironmentItems(const QList<Utils::EnvironmentItem> &items);
    QList<Utils::EnvironmentItem> environmentItems() const;

private:
    EnvironmentItemsWidgetPrivate *d;
};


class EnvironmentItemsDialogPrivate;

class EnvironmentItemsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit EnvironmentItemsDialog(QWidget *parent = 0);
    ~EnvironmentItemsDialog();

    void setEnvironmentItems(const QList<Utils::EnvironmentItem> &items);
    QList<Utils::EnvironmentItem> environmentItems() const;

    static QList<Utils::EnvironmentItem> getEnvironmentItems(QWidget *parent,
                    const QList<Utils::EnvironmentItem> &initial, bool *ok = 0);

private:
    EnvironmentItemsDialogPrivate *d;
};

} // namespace ProjectExplorer

#endif // ENVIRONMENTITEMSWIDGET_H
