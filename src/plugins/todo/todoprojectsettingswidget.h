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

#ifndef TODO_INTERNAL_TODOPROJECTSETTINGSWIDGET_H
#define TODO_INTERNAL_TODOPROJECTSETTINGSWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QListWidgetItem;
QT_END_NAMESPACE

namespace ProjectExplorer {
class Project;
}

namespace Todo {
namespace Internal {

namespace Ui {
class TodoProjectSettingsWidget;
}

class TodoProjectSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TodoProjectSettingsWidget(ProjectExplorer::Project *project);
    ~TodoProjectSettingsWidget();

signals:
    void projectSettingsChanged();

private slots:
    void addExcludedPatternButtonClicked();
    void removeExcludedPatternButtonClicked();
    void setExcludedPatternsButtonsEnabled();
    void excludedPatternChanged(QListWidgetItem *item);

private:
    QListWidgetItem *addToExcludedPatternsList(const QString &pattern);
    void loadSettings();
    void saveSettings();
    void prepareItem(QListWidgetItem *item) const;

    Ui::TodoProjectSettingsWidget *ui;
    ProjectExplorer::Project *m_project;
};


} // namespace Internal
} // namespace Todo
#endif // TODO_INTERNAL_TODOPROJECTSETTINGSWIDGET_H
