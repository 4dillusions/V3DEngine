/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DNetwork/V3DNet.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DNetwork
{
	bool V3DNet::Init()
	{
		V3DLogger::Get().WriteOutput("OK - initialize network");
		
		return true;
	}

	void V3DNet::Cleanup()
	{
		V3DLogger::Get().WriteOutput("Close network");
	}
}
