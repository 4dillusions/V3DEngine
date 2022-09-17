/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdModel
{
    struct V3DEdMainModel;
	struct V3DEdSettingsModel;
}

namespace V3D::V3DEditor::V3DEdLocator
{
	class V3DEdModelLocator final
	{
		V3DEdModel::V3DEdMainModel* mainModel{};
		V3DEdModel::V3DEdSettingsModel* settingsModel{};

	public:
		V3DEdModel::V3DEdMainModel* CreateOrGetMainModel();
		void ReleaseMainModel();

		V3DEdModel::V3DEdSettingsModel* CreateOrGetSettingsModel();
		void ReleaseSettingsModel();
	};
}
