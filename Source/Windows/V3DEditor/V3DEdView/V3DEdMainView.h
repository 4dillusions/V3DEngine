/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_V3DEdMainView.h"
#include "V3DEngine/V3DCore/V3DAction.h"

#include <QtWidgets/QMainWindow>

namespace V3D::V3DEditor::V3DEdModel
{
    struct V3DEdMainModel;
}

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdViewBindings;

	class V3DEdMainView final : public QMainWindow
    {
        Q_OBJECT

    	Ui::V3DEdMainViewClass ui{};
        V3DEdModel::V3DEdMainModel* mainModel;
        V3DEdViewBindings* viewBindings;
        
    public:
        explicit V3DEdMainView(V3DEdModel::V3DEdMainModel* mainModel, V3DEdViewBindings* viewBindings, QWidget* parent = nullptr);
        V3DEdMainView(const V3DEdMainView&) = delete;
        V3DEdMainView(V3DEdMainView&&) = delete;
        ~V3DEdMainView() override;
        V3DEdMainView& operator=(const V3DEdMainView&) = delete;
        V3DEdMainView& operator=(V3DEdMainView&&) = delete;

		V3DEngine::V3DCore::V3DAction ToolBarActionAboutEditor;
        V3DEngine::V3DCore::V3DAction ToolBarActionAboutQt;

        V3DEngine::V3DCore::V3DAction EngineLogDeleteAllAction;
        V3DEngine::V3DCore::V3DAction OutputLogDeleteAllAction;

        V3DEngine::V3DCore::V3DAction ViewActionRelease;

    private:
        void InitUI();
        void InitBindings();

    public:
        void Update() const;

    public slots:
        void OnToolBarAction(QAction* action) const;

        void OnEngineLogDeleteAllClicked() const;
        void OnOutputLogDeleteAllClicked() const;
    };
}
