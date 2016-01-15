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

#ifndef GITSUBMITEDITOR_H
#define GITSUBMITEDITOR_H

#include "gitsettings.h" // CommitType

#include <vcsbase/vcsbasesubmiteditor.h>

#include <QStringList>

namespace VcsBase { class SubmitFileModel; }

namespace Git {
namespace Internal {

class GitClient;
class GitSubmitEditorWidget;
class CommitData;
class CommitDataFetcher;
struct GitSubmitEditorPanelData;

class GitSubmitEditor : public VcsBase::VcsBaseSubmitEditor
{
    Q_OBJECT
public:
    explicit GitSubmitEditor(const VcsBase::VcsBaseSubmitEditorParameters *parameters);
    ~GitSubmitEditor() override;

    void setCommitData(const CommitData &);
    GitSubmitEditorPanelData panelData() const;
    CommitType commitType() const { return m_commitType; }
    QString amendSHA1() const;

protected:
    QByteArray fileContents() const override;
    void updateFileModel() override;
    void forceUpdateFileModel();

private:
    void slotDiffSelected(const QList<int> &rows);
    void showCommit(const QString &commit);
    void commitDataRetrieved(bool success);

    inline GitSubmitEditorWidget *submitEditorWidget();
    inline const GitSubmitEditorWidget *submitEditorWidget() const;
    void resetCommitDataFetcher();

    VcsBase::SubmitFileModel *m_model;
    QTextCodec *m_commitEncoding;
    CommitType m_commitType;
    QString m_amendSHA1;
    QString m_workingDirectory;
    bool m_firstUpdate;
    CommitDataFetcher *m_commitDataFetcher;
    GitClient *m_gitClient;
};

} // namespace Internal
} // namespace Git

#endif // GITSUBMITEDITOR_H
