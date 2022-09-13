/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ui_V3DEdMainView.h"
#include "V3DEngine/V3DCore/V3DAction.h"

#include <QtWidgets/QMainWindow>

namespace V3D::V3DEditor::V3DEdView
{
    class V3DEdMainView final : public QMainWindow
    {
        Q_OBJECT

    	Ui::V3DEdMainViewClass ui{};

    public:
        explicit V3DEdMainView(QWidget* parent = nullptr);
        V3DEdMainView(const V3DEdMainView&) = delete;
        V3DEdMainView(V3DEdMainView&&) = delete;
        ~V3DEdMainView() override;
        V3DEdMainView& operator=(const V3DEdMainView&) = delete;
        V3DEdMainView& operator=(V3DEdMainView&&) = delete;

		V3DEngine::V3DCore::V3DAction ToolBarActionAboutEditor;
        V3DEngine::V3DCore::V3DAction ToolBarActionAboutQt;

        V3DEngine::V3DCore::V3DAction ViewActionRelease;

    public slots:
        void OnToolBarAction(QAction* action) const;
    };
}