/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEdIWindowManager.h"

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdMainView;
}

namespace V3D::V3DEditor::V3DEdCore
{
	class V3DEdWindowManager final : public V3DEdIWindowManager
    {
	    V3DEdView::V3DEdMainView* mainView;

    public:
		explicit V3DEdWindowManager(V3DEdView::V3DEdMainView* mainView);
		V3DEdWindowManager(const V3DEdWindowManager&) = delete;
		V3DEdWindowManager(V3DEdWindowManager&&) = delete;
        ~V3DEdWindowManager() override = default;
		V3DEdWindowManager& operator=(const V3DEdWindowManager&) = delete;
		V3DEdWindowManager& operator=(V3DEdWindowManager&&) = delete;

		void ShowSplashScreen() override;
		void ShowMainWindow() override;
    };
}
