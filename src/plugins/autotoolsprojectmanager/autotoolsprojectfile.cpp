/****************************************************************************
**
** Copyright (C) 2016 Openismus GmbH.
** Author: Peter Penz (ppenz@openismus.com)
** Author: Patricia Santana Cruz (patriciasantanacruz@gmail.com)
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

#include "autotoolsprojectfile.h"
#include "autotoolsproject.h"
#include "autotoolsprojectconstants.h"

using namespace AutotoolsProjectManager;
using namespace AutotoolsProjectManager::Internal;

AutotoolsProjectFile::AutotoolsProjectFile(const QString &fileName)
{
    setId("Autotools.ProjectFile");
    setMimeType(QLatin1String(Constants::MAKEFILE_MIMETYPE));
    setFilePath(Utils::FileName::fromString(fileName));
}

bool AutotoolsProjectFile::save(QString *errorString, const QString &fileName, bool autoSave)
{
    Q_UNUSED(errorString);
    Q_UNUSED(fileName);
    Q_UNUSED(autoSave);

    return false;
}

bool AutotoolsProjectFile::isModified() const
{
    return false;
}

bool AutotoolsProjectFile::isSaveAsAllowed() const
{
    return false;
}

bool AutotoolsProjectFile::reload(QString *errorString, ReloadFlag flag, ChangeType type)
{
    Q_UNUSED(errorString);
    Q_UNUSED(flag);
    Q_UNUSED(type);

    return false;
}
