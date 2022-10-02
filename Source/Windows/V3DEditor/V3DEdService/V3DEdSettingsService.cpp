/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdSettingsService.h"
#include "V3DEditor/V3DEdCore/V3DEdITextFileManager.h"
#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"
#include "V3DEditor/V3DEdLocator/V3DEdModelLocator.h"
#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdSettingsModel.h"
#include "V3DEngine/V3DCore/V3DEnvironment.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdLocator;
using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEditor::V3DEdService
{
	V3DEdSettingsService::V3DEdSettingsService(V3DEdIViewManager* viewManager, V3DEdITextFileManager* textFileManager, V3DEdModelLocator* modelLocator) :
		viewManager{ viewManager }, textFileManager{ textFileManager }, modelLocator{ modelLocator }
	{ }

	V3DEdSettingsModel* V3DEdSettingsService::GetSettingsModel() const
	{
		return modelLocator->CreateOrGetSettingsModel();
	}

	void V3DEdSettingsService::Load() const
	{
		GetSettingsModel()->editorStyleJsonText = textFileManager->ReadEditorStyle(); //delete sting pointer in model locator
		GetSettingsModel()->gameSettingsJsonText = textFileManager->ReadOptions(V3DEnvironment::GetGameOptionsName()); //delete sting pointer in model locator
		GetSettingsModel()->command = V3DEdCommands::LoadSettingsViewData;

		viewManager->LoadSettingsViewData();
		viewManager->UpdateSettingsView();
	}

	void V3DEdSettingsService::Save() const
	{
		//save settingsModel json dump text
		GetSettingsModel()->command = V3DEdCommands::SaveSettingsViewData;
		viewManager->UpdateSettingsView();
		
	}
}
