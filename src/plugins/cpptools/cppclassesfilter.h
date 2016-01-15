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

#ifndef CPPCLASSESFILTER_H
#define CPPCLASSESFILTER_H

#include "cpptools_global.h"
#include "cpplocatorfilter.h"


namespace CppTools {
class CppLocatorData;

// TODO: un-export this
class CPPTOOLS_EXPORT CppClassesFilter : public Internal::CppLocatorFilter
{
    Q_OBJECT

public:
    CppClassesFilter(CppLocatorData *locatorData);
    ~CppClassesFilter();

protected:
    IndexItem::ItemType matchTypes() const override { return IndexItem::Class; }
    Core::LocatorFilterEntry filterEntryFromIndexItem(IndexItem::Ptr info) override;
};

} // namespace CppTools

#endif // CPPCLASSESFILTER_H
