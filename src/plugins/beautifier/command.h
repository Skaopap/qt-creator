/****************************************************************************
**
** Copyright (C) 2016 Lorenz Haas
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

#ifndef BEAUTIFIER_COMMAND_H
#define BEAUTIFIER_COMMAND_H

#include <QString>
#include <QStringList>

namespace Beautifier {
namespace Internal {

class Command
{
public:
    enum Processing {
        FileProcessing,
        PipeProcessing
    };

    Command();

    QString executable() const;
    void setExecutable(const QString &executable);

    QStringList options() const;
    void addOption(const QString &option);

    Processing processing() const;
    void setProcessing(const Processing &processing);

    bool pipeAddsNewline() const;
    void setPipeAddsNewline(bool pipeAddsNewline);

    bool returnsCRLF() const;
    void setReturnsCRLF(bool returnsCRLF);

private:
    QString m_executable;
    QStringList m_options;
    Processing m_processing;
    bool m_pipeAddsNewline;
    bool m_returnsCRLF;
};

} // namespace Internal
} // namespace Beautifier

#endif // BEAUTIFIER_COMMAND_H
