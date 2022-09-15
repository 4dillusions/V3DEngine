/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdModel
{
    struct V3DEdMainModel;
}

namespace V3D::V3DEditor::V3DEdLocator
{
	class V3DEdModelLocator final
	{
		V3DEdModel::V3DEdMainModel* mainModel{};

	public:
		V3DEdModel::V3DEdMainModel* CreateOrGetMainModel();
		void ReleaseMainModel();
	};
}
