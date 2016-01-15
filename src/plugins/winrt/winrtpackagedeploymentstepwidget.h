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

#ifndef WINRTPACKAGEDEPLOYMENTSTEPWIDGET_H
#define WINRTPACKAGEDEPLOYMENTSTEPWIDGET_H

#include "winrtpackagedeploymentstep.h"

#include <projectexplorer/buildstep.h>

namespace WinRt {
namespace Internal {

namespace Ui { class WinRtPackageDeploymentStepWidget; }

class WinRtPackageDeploymentStepWidget : public ProjectExplorer::BuildStepConfigWidget
{
    Q_OBJECT
public:
    WinRtPackageDeploymentStepWidget(WinRtPackageDeploymentStep *step);
    ~WinRtPackageDeploymentStepWidget();

    virtual QString summaryText() const;
    virtual QString displayName() const;

private slots:
    void on_btnRestoreDefaultArgs_clicked();
    void on_leArguments_textChanged(QString str);

private:
    Ui::WinRtPackageDeploymentStepWidget *m_ui;
    WinRtPackageDeploymentStep *m_step;
};

} // namespace Internal
} // namespace WinRt

#endif // WINRTPACKAGEDEPLOYMENTSTEPWIDGET_H
