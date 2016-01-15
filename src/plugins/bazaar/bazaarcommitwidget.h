/****************************************************************************
**
** Copyright (C) 2016 Hugues Delorme
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

#ifndef BAZAARCOMMITWIDGET_H
#define BAZAARCOMMITWIDGET_H

#include "ui_bazaarcommitpanel.h"

#include <vcsbase/submiteditorwidget.h>

namespace Bazaar {
namespace Internal {

class BranchInfo;

/*submit editor widget based on git SubmitEditor
  Some extra fields have been added to the standard SubmitEditorWidget,
  to help to conform to the commit style that is used by both git and Bazaar*/

class BazaarCommitWidget : public VcsBase::SubmitEditorWidget
{
public:
    BazaarCommitWidget();

    void setFields(const BranchInfo &branch,
                   const QString &userName, const QString &email);

    QString committer() const;
    QStringList fixedBugs() const;
    bool isLocalOptionEnabled() const;

private:
    QWidget *m_bazaarCommitPanel;
    Ui::BazaarCommitPanel m_bazaarCommitPanelUi;
};

} // namespace Internal
} // namespace Bazaar

#endif // BAZAARCOMMITWIDGET_H
