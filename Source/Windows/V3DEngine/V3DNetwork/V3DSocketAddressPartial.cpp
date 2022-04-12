/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DNetwork/V3DSocketAddress.h"
#include "V3DEngine/V3DNetwork/V3DNetworkSystem.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

#include <cassert>

namespace V3D::V3DEngine::V3DNetwork
{
	V3DString V3DSocketAddress::GetLocalIp()
	{
		char hostName[256];
		gethostname(hostName, sizeof hostName);

		const struct hostent* host = gethostbyname(hostName);  // NOLINT(concurrency-mt-unsafe)
		if (host == nullptr)
		{
			assert(false, "host_entry == nullptr");
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "V3DNetwork::V3DSocketAddressGetLocalIp() - host_entry == nullptr");
			return V3DCore::V3DString();
		}

		auto dwError = WSAGetLastError();
		if (dwError == WSAHOST_NOT_FOUND)
		{
			assert(false, "Host not found");
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "V3DNetwork::V3DSocketAddressGetLocalIp() - Host not found");
			return V3DCore::V3DString();
		}
		if (dwError == WSANO_DATA)
		{
			assert(false, "No data record found");
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "V3DNetwork::V3DSocketAddressGetLocalIp() - No data record found");
			return V3DCore::V3DString();
		}
		if (dwError != 0)
		{
			assert(false, "Function failed with error");
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, "V3DNetwork::V3DSocketAddressGetLocalIp() - Function failed with error");
			return V3DCore::V3DString();
		}

		auto addrList = (host->h_addr_list[1] != nullptr) ? host->h_addr_list[1] : host->h_addr_list[0];
		char* result = inet_ntoa(*reinterpret_cast<struct in_addr*>(addrList));
		
		return V3DString(result);
	}
}
