/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainController.h"

#include "V3DEditor/V3DEdService/V3DEdMainService.h"
#include "V3DEngine/V3DCore/V3DAction.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEditor::V3DEdService;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEditor::V3DEdController
{
	V3DEdMainController::V3DEdMainController(V3DEdMainService* mainService, V3DLogger* engineLogger) : mainService{ mainService }
	{
		engineLogger->SetLogTrigger(V3DAction1<const V3DString&>([this](const V3DString& log) { OnEngineLogTrigger(log); }));
	}

	void V3DEdMainController::OnToolBarSettings() const
	{
		mainService->Settings();
	}

	void V3DEdMainController::OnToolBarAboutEditor() const
	{
		mainService->AboutEditor();
	}

	void V3DEdMainController::OnToolBarAboutQt() const
	{
		mainService->AboutQt();
	}
	
	void V3DEdMainController::OnEngineLogTrigger(const V3DString& log) const
	{
		mainService->EngineLogWrite(log);
	}

	void V3DEdMainController::OnEngineLogDeleteAll() const
	{
		mainService->EngineLogClear();
	}

	void V3DEdMainController::OnOutputLogDeleteAll() const
	{
		mainService->OutputLogClear();
	}
}
