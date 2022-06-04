/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DCore/V3DIocManager.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DIO/V3DSQLiteContext.h"

using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DCore
{
	void V3DIocManager::Init()
	{
		V3DIocContainer::Init(10);

		V3DIoc<V3DISQLContext>::RegisterTransient<V3DSQLiteContext>(V3DFunc<V3DISQLContext*>([&] { return V3DMemory::New<V3DSQLiteContext>(V3DFILE_INFO, "test.db"); }));
	}

	void V3DIocManager::Clean()
	{
		V3DIocContainer::Clean();
	}
}
