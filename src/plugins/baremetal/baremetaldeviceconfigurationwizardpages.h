/****************************************************************************
**
** Copyright (C) 2016 Tim Sander <tim@krieglstein.org>
** Copyright (C) 2016 Denis Shienkov <denis.shienkov@gmail.com>
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

#ifndef BAREMETALDEVICECONFIGURATIONWIZARDPAGES_H
#define BAREMETALDEVICECONFIGURATIONWIZARDPAGES_H

#include <QWizardPage>

QT_BEGIN_NAMESPACE
class QLineEdit;
QT_END_NAMESPACE

namespace BareMetal {
namespace Internal {

class GdbServerProviderChooser;

class BareMetalDeviceConfigurationWizardSetupPage : public QWizardPage
{
    Q_OBJECT

public:
    explicit BareMetalDeviceConfigurationWizardSetupPage(QWidget *parent = 0);

    void initializePage();
    bool isComplete() const;
    QString configurationName() const;
    QString gdbServerProviderId() const;

    virtual QString defaultConfigurationName() const;

private:
    QLineEdit *m_nameLineEdit;
    GdbServerProviderChooser *m_gdbServerProviderChooser;
};

} // namespace Internal
} // namespace BareMetal

#endif // BAREMETALDEVICECONFIGURATIONWIZARDPAGES_H
