/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEdIViewManager.h"

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdMainView;
}

namespace V3D::V3DEditor::V3DEdCore
{
	class V3DEdViewManager final : public V3DEdIViewManager
    {
	    V3DEdView::V3DEdMainView* mainView;

    public:
		explicit V3DEdViewManager(V3DEdView::V3DEdMainView* mainView);
		V3DEdViewManager(const V3DEdViewManager&) = delete;
		V3DEdViewManager(V3DEdViewManager&&) = delete;
        ~V3DEdViewManager() override = default;
		V3DEdViewManager& operator=(const V3DEdViewManager&) = delete;
		V3DEdViewManager& operator=(V3DEdViewManager&&) = delete;

		void ShowSplashView() override;
		void ShowMainView() override;

		void ShowAboutEditorView() override;
		void ShowAboutQtView() override;
    };
}
