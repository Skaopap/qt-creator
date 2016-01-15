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

#ifndef DesignDocumentVIEW_H
#define DesignDocumentVIEW_H

#include <abstractview.h>
#include <modelmerger.h>

namespace QmlDesigner {

class DesignDocumentView : public AbstractView
{
        Q_OBJECT
public:
    DesignDocumentView(QObject *parent = 0);
    ~DesignDocumentView();

    ModelNode insertModel(const ModelNode &modelNode)
    { return m_modelMerger.insertModel(modelNode); }
    void replaceModel(const ModelNode &modelNode)
    { m_modelMerger.replaceModel(modelNode); }

    void toClipboard() const;
    void fromClipboard();

    QString toText() const;
    void fromText(QString text);

private:
    ModelMerger m_modelMerger;
};

}// namespace QmlDesigner

#endif // DesignDocumentVIEW_H
