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

#ifndef WINRTRUNCONFIGURATIONFACTORY_H
#define WINRTRUNCONFIGURATIONFACTORY_H

#include <projectexplorer/runconfiguration.h>
#include <projectexplorer/devicesupport/idevicefactory.h>
#include <projectexplorer/deployconfiguration.h>

namespace WinRt {
namespace Internal {

class WinRtRunConfigurationFactory  : public ProjectExplorer::IRunConfigurationFactory
{
    Q_OBJECT
public:
    WinRtRunConfigurationFactory();

    QList<Core::Id> availableCreationIds(ProjectExplorer::Target *parent, CreationMode mode) const;
    QString displayNameForId(Core::Id id) const;
    bool canCreate(ProjectExplorer::Target *parent, Core::Id id) const;
    bool canRestore(ProjectExplorer::Target *parent, const QVariantMap &map) const;
    bool canClone(ProjectExplorer::Target *parent, ProjectExplorer::RunConfiguration *product) const;
    ProjectExplorer::RunConfiguration *clone(ProjectExplorer::Target *parent,
                                             ProjectExplorer::RunConfiguration *product);

private:
    bool canHandle(ProjectExplorer::Target *parent) const;
    virtual ProjectExplorer::RunConfiguration *doCreate(ProjectExplorer::Target *parent, Core::Id id);
    virtual ProjectExplorer::RunConfiguration *doRestore(ProjectExplorer::Target *parent, const QVariantMap &map);
};

class WinRtRunControlFactory : public ProjectExplorer::IRunControlFactory
{
    Q_OBJECT
public:
    WinRtRunControlFactory();
    bool canRun(ProjectExplorer::RunConfiguration *runConfiguration,
                Core::Id mode) const;
    ProjectExplorer::RunControl *create(ProjectExplorer::RunConfiguration *runConfiguration,
                       Core::Id mode, QString *errorMessage);
    QString displayName() const;
};

} // namespace Internal
} // namespace WinRt

#endif // WINRTRUNCONFIGURATIONFACTORY_H
