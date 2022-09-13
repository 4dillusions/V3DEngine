/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DCore/V3DIocManager.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogMessageType.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEdView/V3DEdMainView.h"
#include "V3DEdCore/V3DEdViewManager.h"
#include "V3DEdService/V3DEdMainService.h"
#include "V3DEdController/V3DEdMainController.h"
#include "V3DEdClient.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEditor;
using namespace V3DEdCore;
using namespace V3DEdView;
using namespace V3DEdService;
using namespace V3DEdController;

namespace V3D::V3DEngine::V3DCore
{
	void V3DIocManager::Init()
	{
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToFile, true);
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Init IocManager: V3DEditor");

		V3DIocContainer::Init(10);

		V3DIoc<V3DEdMainView>::RegisterAndCreateSingleton<V3DEdMainView>();
		V3DIoc<V3DEdIViewManager>::RegisterAndCreateSingleton<V3DEdViewManager>(V3DFunc<V3DEdIViewManager*>([&] { return V3DMemory::New<V3DEdViewManager>(V3DFILE_INFO, V3DIoc<V3DEdMainView>::GetSingleton()); }));
		V3DIoc<V3DEdMainService>::RegisterAndCreateSingleton<V3DEdMainService>(V3DFunc<V3DEdMainService*>([&] { return V3DMemory::New<V3DEdMainService>(V3DFILE_INFO, V3DIoc<V3DEdIViewManager>::GetSingleton()); }));
		V3DIoc<V3DEdMainController>::RegisterTransient<V3DEdMainController>(V3DFunc<V3DEdMainController*>([&] { return V3DMemory::New<V3DEdMainController>(V3DFILE_INFO, V3DIoc<V3DEdMainService>::GetSingleton()); }));
		
		V3DIoc<V3DEdClient>::RegisterTransient<V3DEdClient>(V3DFunc<V3DEdClient*>([&] { return V3DMemory::New<V3DEdClient>(V3DFILE_INFO, V3DIoc<V3DEdIViewManager>::GetSingleton()); }));
	}

	void V3DIocManager::Clean()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Clean IocManager: V3DEditor");

		V3DIocContainer::Clean();
	}
}
