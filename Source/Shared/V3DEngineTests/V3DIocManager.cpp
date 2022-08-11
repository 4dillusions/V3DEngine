/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DCore/V3DIocManager.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"
#include "V3DEngine/V3DAsset/V3DAssetManager.h"
#include "V3DEngine/V3DAudio/V3DAudioSystem.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogMessageType.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DAsset;
using namespace V3D::V3DEngine::V3DAudio;

namespace V3D::V3DEngine::V3DCore
{
	void V3DIocManager::Init()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Init IocManager");

		V3DIocContainer::Init(10);

		V3DIoc<V3DISQLContext>::RegisterTransient<V3DSQLiteContext>(V3DFunc<V3DISQLContext*>([&] { return V3DMemory::New<V3DSQLiteContext>(V3DFILE_INFO, "test.db"); }));

		V3DIoc<V3DAssetManager>::RegisterAndCreateSingleton<V3DAssetManager>();
		V3DIoc<V3DIAudioSystem>::RegisterTransient<V3DAudioSystem>(V3DFunc<V3DIAudioSystem*>([&] { return V3DMemory::New<V3DAudioSystem>(V3DFILE_INFO, V3DIoc<V3DAssetManager>::GetSingleton()); }));
	}

	void V3DIocManager::Clean()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Clean IocManager");
		V3DIocContainer::Clean();
	}
}
