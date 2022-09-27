/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"

namespace V3D::V3DEditor::V3DEdLocator
{
	class V3DEdModelLocator;
	class V3DEdControllerLocator;
}

namespace V3D::V3DEditor::V3DEdView
{
	class V3DEdMainView;
	class V3DEdSettingsView;

	class V3DEdViewManager final : public V3DEdCore::V3DEdIViewManager
	{
		V3DEdLocator::V3DEdControllerLocator* controllerLocator;

		V3DEdMainView* mainView;
		V3DEdSettingsView* settingsView{};

	public:
		V3DEdViewManager(V3DEdLocator::V3DEdControllerLocator* controllerLocator, V3DEdMainView* mainView);
		V3DEdViewManager(const V3DEdViewManager&) = delete;
		V3DEdViewManager(V3DEdViewManager&&) = delete;
		~V3DEdViewManager() override = default;
		V3DEdViewManager& operator=(const V3DEdViewManager&) = delete;
		V3DEdViewManager& operator=(V3DEdViewManager&&) = delete;

		void ShowSplashView() override;
		void ShowMainView() override;

		void ShowSettingsView() override;
		void ShowAboutEditorView() override;
		void ShowAboutQtView() override;

		void UpdateMainView() override;
		void UpdateSettingsView() override;
	};
}
