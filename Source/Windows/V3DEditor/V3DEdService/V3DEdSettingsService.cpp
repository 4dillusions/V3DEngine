/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdSettingsService.h"
#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"
#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdSettingsModel.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdModel;

namespace V3D::V3DEditor::V3DEdService
{
	V3DEdSettingsService::V3DEdSettingsService(V3DEdIViewManager* viewManager, V3DEdSettingsModel* settingsModel) :
		viewManager{ viewManager }, settingsModel { settingsModel }
	{ }
	
	void V3DEdSettingsService::Save() const
	{
		//save settingsModel json dump text
	}
}
