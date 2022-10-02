/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_V3DEdMainView.h"
#include "V3DEngine/V3DCore/V3DAction.h"

#include <QtWidgets/QMainWindow>

namespace V3D::V3DEditor
{
    namespace V3DEdLocator
    {
        class V3DEdModelLocator;
    }

    namespace V3DEdModel
    {
        struct V3DEdMainModel;
    }
}

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdViewBindings;
    class V3DPropertyTreeBuilder;

	class V3DEdMainView final : public QMainWindow
    {
        Q_OBJECT

    	Ui::V3DEdMainViewClass ui{};
        V3DEdLocator::V3DEdModelLocator* modelLocator;
        V3DEdViewBindings* viewBindings;
        V3DPropertyTreeBuilder* propertyTreeBuilder;
        
    public:
        V3DEdMainView(V3DEdLocator::V3DEdModelLocator* modelLocator, V3DEdViewBindings* viewBindings, V3DPropertyTreeBuilder* propertyTreeBuilder, QWidget* parent = nullptr);
        V3DEdMainView(const V3DEdMainView&) = delete;
        V3DEdMainView(V3DEdMainView&&) = delete;
        ~V3DEdMainView() override;
        V3DEdMainView& operator=(const V3DEdMainView&) = delete;
        V3DEdMainView& operator=(V3DEdMainView&&) = delete;

        V3DEdModel::V3DEdMainModel* GetMainModel() const;

        V3DEngine::V3DCore::V3DAction ToolBarActionSettings;
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
