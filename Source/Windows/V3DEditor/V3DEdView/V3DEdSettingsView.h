/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_V3DEdSettingsView.h"
#include "V3DEngine/V3DCore/V3DAction.h"

#include <QtWidgets/QDialog>

namespace V3D::V3DEditor::V3DEdModel
{
    struct V3DEdSettingsModel;
}

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdViewBindings;

	class V3DEdSettingsView final : public QDialog
    {
        Q_OBJECT

    	Ui::V3DEdSettingsViewClass ui{};
        V3DEdModel::V3DEdSettingsModel* settingsModel;
        V3DEdViewBindings* viewBindings;
        
    public:
        V3DEdSettingsView(V3DEdModel::V3DEdSettingsModel* settingsModel,V3DEdViewBindings* viewBindings, QWidget* parent = nullptr);
        V3DEdSettingsView(const V3DEdSettingsView&) = delete;
        V3DEdSettingsView(V3DEdSettingsView&&) = delete;
        ~V3DEdSettingsView() override;
        V3DEdSettingsView& operator=(const V3DEdSettingsView&) = delete;
        V3DEdSettingsView& operator=(V3DEdSettingsView&&) = delete;

        V3DEngine::V3DCore::V3DAction SaveAction;

        V3DEngine::V3DCore::V3DAction ViewActionRelease;

    private:
        void InitUI();
        void InitBindings() const;
        
    public:
        void Update() const;

    public slots:
        void OnSaveClicked() const;
    };
}
