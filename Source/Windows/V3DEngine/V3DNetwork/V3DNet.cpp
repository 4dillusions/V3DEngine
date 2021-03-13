/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DNetwork/V3DNet.h"
#include "V3DEngine/V3DNetwork/V3DNetworkSystem.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DNetwork
{
	bool V3DNet::Init()
	{
		WSAData wsData{};

		if (WSAStartup(MAKEWORD(2, 2), &wsData) == NOERROR)
		{
			V3DLogger::Get().WriteOutput("OK - initialize network");
		}
		else
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "Can't initialize network!");
			return false;
		}

		return true;
	}

	void V3DNet::Cleanup()
	{
		V3DLogger::Get().WriteOutput("Close network");
		WSACleanup();
	}
}
