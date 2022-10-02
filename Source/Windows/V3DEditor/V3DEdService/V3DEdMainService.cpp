/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainService.h"
#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"
#include "V3DEditor/V3DEdLocator/V3DEdModelLocator.h"
#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdMainModel.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdLocator;
using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEditor::V3DEdService
{
	V3DEdMainService::V3DEdMainService(V3DEdIViewManager* viewManager, V3DEdModelLocator* modelLocator, V3DLogger* outputLogger) :
		viewManager{ viewManager }, modelLocator{ modelLocator }, outputLogger{ outputLogger }
	{ }

	V3DEdMainModel* V3DEdMainService::GetMainModel() const
	{
		return modelLocator->CreateOrGetMainModel();
	}
	
	void V3DEdMainService::Settings() const
	{
		GetMainModel()->command = V3DEdCommands::ShowSettingsView;

		GetMainModel()->isSettingsViewActive = true;
		viewManager->UpdateMainView();

		viewManager->ShowSettingsView();

		GetMainModel()->isSettingsViewActive = false;
		viewManager->UpdateMainView();
	}

	void V3DEdMainService::AboutEditor() const
	{
		viewManager->ShowAboutEditorView();
	}

	void V3DEdMainService::AboutQt() const
	{
		viewManager->ShowAboutQtView();
	}

	void V3DEdMainService::EngineLogWrite(const V3DString& log) const
	{
		GetMainModel()->engineLog.Add(log);
		GetMainModel()->command = V3DEdCommands::AddEngineLogItem;
		viewManager->UpdateMainView();
	}

	void V3DEdMainService::EngineLogClear() const
	{
		GetMainModel()->engineLog.RemoveAll();
		GetMainModel()->command = V3DEdCommands::ClearEngineLogItem;
		viewManager->UpdateMainView();
	}

	void V3DEdMainService::OutputLogWrite(V3DLogMessageType messageType, const V3DString& log) const
	{
		outputLogger->GetBuffer()->Clear();
		outputLogger->WriteOutput(messageType, log);

		V3DString outLog = *outputLogger->GetBuffer();
		outLog.Remove('\n');

		GetMainModel()->outputLog.Add(outLog);
		GetMainModel()->command = V3DEdCommands::AddOutputLogItem;

		viewManager->UpdateMainView();
	}

	void V3DEdMainService::OutputLogClear() const
	{
		GetMainModel()->outputLog.RemoveAll();
		GetMainModel()->command = V3DEdCommands::ClearOutputLogItem;
		viewManager->UpdateMainView();
	}
}
