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

#include "cppcodemodelsettingspage.h"
#include "cppmodelmanager.h"
#include "cpptoolsconstants.h"
#include "ui_cppcodemodelsettingspage.h"

#include <coreplugin/icore.h>
#include <utils/algorithm.h>

#include <QTextStream>

using namespace CppTools;
using namespace CppTools::Internal;

CppCodeModelSettingsWidget::CppCodeModelSettingsWidget(QWidget *parent)
    : QWidget(parent)
    , m_ui(new Ui::CppCodeModelSettingsPage)
{
    m_ui->setupUi(this);

    m_ui->clangSettingsGroupBox->setVisible(true);
    connect(m_ui->clangOptionsResetButton, &QPushButton::clicked, [this]() {
        const QString options = m_settings->defaultExtraClangOptions().join(QLatin1Char('\n'));
        m_ui->clangOptionsToAppendTextEdit->document()->setPlainText(options);
    });
}

CppCodeModelSettingsWidget::~CppCodeModelSettingsWidget()
{
    delete m_ui;
}

void CppCodeModelSettingsWidget::setSettings(const QSharedPointer<CppCodeModelSettings> &s)
{
    m_settings = s;

    setupClangCodeModelWidgets();
    setupPchCheckBox();
}

void CppCodeModelSettingsWidget::applyToSettings() const
{
    bool changed = false;

    changed |= applyClangCodeModelWidgetsToSettings();
    changed |= applyPchCheckBoxToSettings();

    if (changed)
        m_settings->toSettings(Core::ICore::settings());
}

void CppCodeModelSettingsWidget::setupClangCodeModelWidgets() const
{
    const bool isClangActive = CppModelManager::instance()->isClangCodeModelActive();

    m_ui->activateClangCodeModelPluginHint->setVisible(!isClangActive);
    m_ui->clangSettingsGroupBox->setEnabled(isClangActive);

    const QString extraClangOptions = m_settings->extraClangOptions().join(QLatin1Char('\n'));
    m_ui->clangOptionsToAppendTextEdit->document()->setPlainText(extraClangOptions);
}

void CppCodeModelSettingsWidget::setupPchCheckBox() const
{
    const bool ignorePch = m_settings->pchUsage() == CppCodeModelSettings::PchUse_None;
    m_ui->ignorePCHCheckBox->setChecked(ignorePch);
}

bool CppCodeModelSettingsWidget::applyClangCodeModelWidgetsToSettings() const
{
    bool settingsChanged = false;

    const QStringList previousOptions = m_settings->extraClangOptions();
    const QString newOptionsAsString = m_ui->clangOptionsToAppendTextEdit->document()->toPlainText();
    const QStringList newOptions = newOptionsAsString.split(QLatin1Char('\n'),
                                                            QString::SkipEmptyParts);
    if (newOptions != previousOptions) {
        m_settings->setExtraClangOptions(newOptions);
        settingsChanged = true;
    }

    return settingsChanged;
}

bool CppCodeModelSettingsWidget::applyPchCheckBoxToSettings() const
{
    const bool newIgnorePch = m_ui->ignorePCHCheckBox->isChecked();
    const bool previousIgnorePch = m_settings->pchUsage() == CppCodeModelSettings::PchUse_None;

    if (newIgnorePch != previousIgnorePch) {
        const CppCodeModelSettings::PCHUsage pchUsage = m_ui->ignorePCHCheckBox->isChecked()
                ? CppCodeModelSettings::PchUse_None
                : CppCodeModelSettings::PchUse_BuildSystem;
        m_settings->setPCHUsage(pchUsage);

        return true;
    }

    return false;
}

CppCodeModelSettingsPage::CppCodeModelSettingsPage(QSharedPointer<CppCodeModelSettings> &settings,
                                                   QObject *parent)
    : Core::IOptionsPage(parent)
    , m_settings(settings)
{
    setId(Constants::CPP_CODE_MODEL_SETTINGS_ID);
    setDisplayName(QCoreApplication::translate("CppTools",Constants::CPP_CODE_MODEL_SETTINGS_NAME));
    setCategory(Constants::CPP_SETTINGS_CATEGORY);
    setDisplayCategory(QCoreApplication::translate("CppTools",Constants::CPP_SETTINGS_TR_CATEGORY));
    setCategoryIcon(QLatin1String(Constants::SETTINGS_CATEGORY_CPP_ICON));
}

QWidget *CppCodeModelSettingsPage::widget()
{
    if (!m_widget) {
        m_widget = new CppCodeModelSettingsWidget;
        m_widget->setSettings(m_settings);
    }
    return m_widget;
}

void CppCodeModelSettingsPage::apply()
{
    if (m_widget)
        m_widget->applyToSettings();
}

void CppCodeModelSettingsPage::finish()
{
    delete m_widget;
}
