/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdCore
{
	class V3DEdIViewManager
    {
    public:
		V3DEdIViewManager() = default;
		V3DEdIViewManager(const V3DEdIViewManager&) = delete;
		V3DEdIViewManager(V3DEdIViewManager&&) = delete;
        virtual ~V3DEdIViewManager() = default;
		V3DEdIViewManager& operator=(const V3DEdIViewManager&) = delete;
		V3DEdIViewManager& operator=(V3DEdIViewManager&&) = delete;

		virtual void ShowSplashView() = 0;
		virtual void ShowMainView() = 0;

		virtual void ShowSettingsView() = 0;
		virtual void ShowAboutEditorView() = 0;
		virtual void ShowAboutQtView() = 0;

		virtual void UpdateMainView() = 0;
    };
}
