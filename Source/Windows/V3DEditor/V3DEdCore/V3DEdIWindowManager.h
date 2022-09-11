/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdCore
{
	class V3DEdIWindowManager
    {
    public:
		V3DEdIWindowManager() = default;
		V3DEdIWindowManager(const V3DEdIWindowManager&) = delete;
		V3DEdIWindowManager(V3DEdIWindowManager&&) = delete;
        virtual ~V3DEdIWindowManager() = default;
		V3DEdIWindowManager& operator=(const V3DEdIWindowManager&) = delete;
		V3DEdIWindowManager& operator=(V3DEdIWindowManager&&) = delete;

		virtual void ShowSplashScreen() = 0;
		virtual void ShowMainWindow() = 0;
    };
}
