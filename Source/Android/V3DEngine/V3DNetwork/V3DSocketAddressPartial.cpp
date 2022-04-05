/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DNetwork/V3DSocketAddress.h"
#include "V3DEngine/V3DCore/V3DString.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DNetwork
{
	V3DString V3DSocketAddress::GetLocalIp()
	{
		setenv("LANG", "C", 1);  // NOLINT(concurrency-mt-unsafe)

		FILE* fp = popen("ip -f inet addr show", "r"); //Android 10+ `ifconfig` only works in rooted devices, another solution: 'ip -f inet addr show'
		if (fp)
		{
			char* ip = nullptr, * delimiter;
			size_t count; //ambiguous symbol size_t
			while ((getline(&ip, &count, fp) > 0) && ip)
			{
				if ((ip = strstr(ip, "inet ")))
				{
					ip += 5;
					if ((delimiter = strchr(ip, '/')))
					{
						*delimiter = '\0';

						V3DString result(ip);
						if (result != V3DString("127.0.0.1"))
							return result;
					}
				}
			}
		}
		pclose(fp);

		return {};
	}
}
