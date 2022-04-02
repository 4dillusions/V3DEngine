/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DNetwork/V3DNetworkSystem.h"

namespace V3D::V3DEngine::V3DNetwork
{
	inline V3DCore::V3DString V3DSocketAddressGetLocalIp()
	{
		char host[256];
		gethostname(host, sizeof host);
		const hostent* host_entry = gethostbyname(host);  // NOLINT(concurrency-mt-unsafe)
		char* result = inet_ntoa(*reinterpret_cast<struct in_addr*>(host_entry->h_addr_list[1]));  // NOLINT(concurrency-mt-unsafe)

		return V3DCore::V3DString(result);
	}
}
