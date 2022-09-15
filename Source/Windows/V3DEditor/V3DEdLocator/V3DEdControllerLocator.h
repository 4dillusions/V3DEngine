/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdController
{
	class V3DEdMainController;
}

namespace V3D::V3DEditor::V3DEdLocator
{
	class V3DEdControllerLocator final
    {
		V3DEdController::V3DEdMainController* mainController{};

	public:
		V3DEdController::V3DEdMainController* CreateOrGetMainController();
		void ReleaseMainController();
    };
}
