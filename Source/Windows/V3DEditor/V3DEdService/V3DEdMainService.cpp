/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainService.h"
#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"
#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdMainModel.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEditor::V3DEdCore;
using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEditor::V3DEdService
{
	V3DEdMainService::V3DEdMainService(V3DEdIViewManager* viewManager, V3DEdMainModel* mainModel, V3DLogger* outputLogger) :
		viewManager{ viewManager }, mainModel { mainModel }, outputLogger{ outputLogger }
	{ }
	
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
		mainModel->engineLog.Add(log);
		mainModel->command = V3DEdCommands::AddEngineLogItem;
		viewManager->UpdateMainView();
	}

	void V3DEdMainService::EngineLogClear() const
	{
		mainModel->engineLog.RemoveAll();
		mainModel->command = V3DEdCommands::ClearEngineLogItem;
		viewManager->UpdateMainView();
	}

	void V3DEdMainService::OutputLogWrite(V3DLogMessageType messageType, const V3DString& log) const
	{
		outputLogger->GetBuffer()->Clear();
		outputLogger->WriteOutput(messageType, log);

		V3DString outLog = *outputLogger->GetBuffer();
		outLog.Remove('\n');

		mainModel->outputLog.Add(outLog);
		mainModel->command = V3DEdCommands::AddOutputLogItem;

		viewManager->UpdateMainView();
	}

	void V3DEdMainService::OutputLogClear() const
	{
		mainModel->outputLog.RemoveAll();
		mainModel->command = V3DEdCommands::ClearOutputLogItem;
		viewManager->UpdateMainView();
	}
}
