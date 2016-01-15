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

#ifndef BEAUTIFIER_CLANGFORMATSETTINGS_H
#define BEAUTIFIER_CLANGFORMATSETTINGS_H

#include "../abstractsettings.h"


namespace Beautifier {
namespace Internal {
namespace ClangFormat {

class ClangFormatSettings : public AbstractSettings
{
    Q_DECLARE_TR_FUNCTIONS(ClangFormatSettings)

public:
    explicit ClangFormatSettings();

    QString documentationFilePath() const override;
    void createDocumentationFile() const override;
    QStringList completerWords() override;

    bool usePredefinedStyle() const;
    void setUsePredefinedStyle(bool usePredefinedStyle);

    QString predefinedStyle() const;
    void setPredefinedStyle(const QString &predefinedStyle);

    QString customStyle() const;
    void setCustomStyle(const QString &customStyle);

    bool formatEntireFileFallback() const;
    void setFormatEntireFileFallback(bool formatEntireFileFallback);

    QStringList predefinedStyles() const;
};

} // namespace ClangFormat
} // namespace Internal
} // namespace Beautifier

#endif // BEAUTIFIER_CLANGFORMATSETTINGS_H
