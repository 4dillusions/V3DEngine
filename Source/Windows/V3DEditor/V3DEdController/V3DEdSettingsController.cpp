/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdSettingsController.h"
#include "V3DEditor/V3DEdService/V3DEdSettingsService.h"
#include "V3DEngine/V3DCore/V3DAction.h"

using namespace V3D::V3DEditor::V3DEdService;

namespace V3D::V3DEditor::V3DEdController
{
	V3DEdSettingsController::V3DEdSettingsController(V3DEdSettingsService* settingsService) : settingsService{ settingsService }
	{ }

	void V3DEdSettingsController::OnSettingsSave() const
	{
		settingsService->Save();
	}
}
