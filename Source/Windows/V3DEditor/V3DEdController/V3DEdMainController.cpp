/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainController.h"

#include "V3DEditor/V3DEdService/V3DEdMainService.h"

using namespace V3D::V3DEditor::V3DEdService;

namespace V3D::V3DEditor::V3DEdController
{
	V3DEdMainController::V3DEdMainController(V3DEdMainService* mainService) : mainService{ mainService }
	{ }

	void V3DEdMainController::OnToolBarAboutEditor() const
	{
		mainService->AboutEditor();
	}

	void V3DEdMainController::OnToolBarAboutQt() const
	{
		mainService->AboutQt();
	}
}
