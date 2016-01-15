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

#include "remotelinuxcustomrunconfiguration.h"

#include "remotelinuxenvironmentaspect.h"
#include "ui_remotelinuxcustomrunconfigurationwidget.h"

#include <projectexplorer/target.h>
#include <qtsupport/qtoutputformatter.h>
#include <utils/detailswidget.h>
#include <utils/qtcprocess.h>

namespace RemoteLinux {
namespace Internal {

class RemoteLinuxCustomRunConfigWidget : public ProjectExplorer::RunConfigWidget
{
    Q_OBJECT
public:
    RemoteLinuxCustomRunConfigWidget(RemoteLinuxCustomRunConfiguration *runConfig)
        : m_runConfig(runConfig)
    {
        QVBoxLayout * const mainLayout = new QVBoxLayout(this);
        mainLayout->setMargin(0);
        auto * const detailsContainer = new Utils::DetailsWidget(this);
        mainLayout->addWidget(detailsContainer);
        detailsContainer->setState(Utils::DetailsWidget::NoSummary);
        QWidget * const detailsWidget = new QWidget(this);
        detailsContainer->setWidget(detailsWidget);
        m_ui.setupUi(detailsWidget);
        m_ui.localExecutablePathChooser->setExpectedKind(Utils::PathChooser::File);
        m_ui.localExecutablePathChooser->setPath(m_runConfig->localExecutableFilePath());
        m_ui.remoteExeLineEdit->setText(m_runConfig->remoteExecutableFilePath());
        m_ui.argsLineEdit->setText(m_runConfig->arguments());
        m_ui.workingDirLineEdit->setText(m_runConfig->workingDirectory());
        connect(m_ui.localExecutablePathChooser, SIGNAL(pathChanged(QString)),
                SLOT(handleLocalExecutableChanged(QString)));
        connect(m_ui.remoteExeLineEdit, SIGNAL(textEdited(QString)),
                SLOT(handleRemoteExecutableChanged(QString)));
        connect(m_ui.argsLineEdit, SIGNAL(textEdited(QString)),
                SLOT(handleArgumentsChanged(QString)));
        connect(m_ui.workingDirLineEdit, SIGNAL(textEdited(QString)),
                SLOT(handleWorkingDirChanged(QString)));
    }

private slots:
    void handleLocalExecutableChanged(const QString &path) {
        m_runConfig->setLocalExecutableFilePath(path.trimmed());
    }

    void handleRemoteExecutableChanged(const QString &path) {
        m_runConfig->setRemoteExecutableFilePath(path.trimmed());
        emit displayNameChanged(displayName());
    }

    void handleArgumentsChanged(const QString &arguments) {
        m_runConfig->setArguments(arguments.trimmed());
    }

    void handleWorkingDirChanged(const QString &wd) {
        m_runConfig->setWorkingDirectory(wd.trimmed());
    }

private:
    QString displayName() const { return m_runConfig->displayName(); }

    RemoteLinuxCustomRunConfiguration * const m_runConfig;
    Ui::RemoteLinuxCustomRunConfigurationWidget m_ui;
};

RemoteLinuxCustomRunConfiguration::RemoteLinuxCustomRunConfiguration(ProjectExplorer::Target *parent)
    : AbstractRemoteLinuxRunConfiguration(parent, runConfigId())
{
    init();
}

RemoteLinuxCustomRunConfiguration::RemoteLinuxCustomRunConfiguration(ProjectExplorer::Target *parent,
        RemoteLinuxCustomRunConfiguration *source)
    : AbstractRemoteLinuxRunConfiguration(parent, source)
    , m_localExecutable(source->m_localExecutable)
    , m_remoteExecutable(source->m_remoteExecutable)
    , m_arguments(source->m_arguments)
    , m_workingDirectory(source->m_workingDirectory)
{
    init();
}

bool RemoteLinuxCustomRunConfiguration::isConfigured() const
{
    return !m_remoteExecutable.isEmpty();
}

ProjectExplorer::RunConfiguration::ConfigurationState
RemoteLinuxCustomRunConfiguration::ensureConfigured(QString *errorMessage)
{
    if (!isConfigured()) {
        if (errorMessage) {
            *errorMessage = tr("The remote executable must be set "
                               "in order to run a custom remote run configuration.");
        }
        return UnConfigured;
    }
    return Configured;
}

QWidget *RemoteLinuxCustomRunConfiguration::createConfigurationWidget()
{
    return new RemoteLinuxCustomRunConfigWidget(this);
}

Utils::OutputFormatter *RemoteLinuxCustomRunConfiguration::createOutputFormatter() const
{
    return new QtSupport::QtOutputFormatter(target()->project());
}

Utils::Environment RemoteLinuxCustomRunConfiguration::environment() const
{
    RemoteLinuxEnvironmentAspect *aspect = extraAspect<RemoteLinuxEnvironmentAspect>();
    QTC_ASSERT(aspect, return Utils::Environment());
    return aspect->environment();
}

void RemoteLinuxCustomRunConfiguration::setRemoteExecutableFilePath(const QString &executable)
{
    m_remoteExecutable = executable;
    setDisplayName(tr("Run \"%1\" on Linux Device").arg(executable));
}

Core::Id RemoteLinuxCustomRunConfiguration::runConfigId()
{
    return "RemoteLinux.CustomRunConfig";
}

QString RemoteLinuxCustomRunConfiguration::runConfigDefaultDisplayName()
{
    return tr("Custom Executable (on Remote Generic Linux Host)");
}

void RemoteLinuxCustomRunConfiguration::init()
{
    setDefaultDisplayName(runConfigDefaultDisplayName());
    addExtraAspect(new RemoteLinuxEnvironmentAspect(this));
}

static QString localExeKey()
{
    return QLatin1String("RemoteLinux.CustomRunConfig.LocalExecutable");
}

static QString remoteExeKey()
{
    return QLatin1String("RemoteLinux.CustomRunConfig.RemoteExecutable");
}

static QString argsKey()
{
    return QLatin1String("RemoteLinux.CustomRunConfig.Arguments");
}

static QString workingDirKey()
{
    return QLatin1String("RemoteLinux.CustomRunConfig.WorkingDirectory");
}

bool RemoteLinuxCustomRunConfiguration::fromMap(const QVariantMap &map)
{
    if (!AbstractRemoteLinuxRunConfiguration::fromMap(map))
        return false;
    setLocalExecutableFilePath(map.value(localExeKey()).toString());
    setRemoteExecutableFilePath(map.value(remoteExeKey()).toString());
    QVariant args = map.value(argsKey());
    if (args.type() == QVariant::StringList) // Until 3.7 a QStringList was stored.
        setArguments(Utils::QtcProcess::joinArgs(args.toStringList(), Utils::OsTypeLinux));
    else
        setArguments(args.toString());
    setWorkingDirectory(map.value(workingDirKey()).toString());
    return true;
}

QVariantMap RemoteLinuxCustomRunConfiguration::toMap() const
{
    QVariantMap map = AbstractRemoteLinuxRunConfiguration::toMap();
    map.insert(localExeKey(), m_localExecutable);
    map.insert(remoteExeKey(), m_remoteExecutable);
    map.insert(argsKey(), m_arguments);
    map.insert(workingDirKey(), m_workingDirectory);
    return map;
}

} // namespace Internal
} // namespace RemoteLinux

#include "remotelinuxcustomrunconfiguration.moc"
