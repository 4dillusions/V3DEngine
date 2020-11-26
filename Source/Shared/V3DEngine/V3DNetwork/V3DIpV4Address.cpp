/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIpV4Address.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DNetwork
{
	V3DIpV4Address::V3DIpV4Address(int addr1, int addr2, int addr3, int addr4) : addr1{ addr1 }, addr2{ addr2 }, addr3{ addr3 }, addr4{ addr4 }
	{ }
	
	V3DIpV4Address::V3DIpV4Address(const V3DString& ipAddress)
	{
		auto address = ipAddress.Split('.');
		addr1 = addr2 = addr3 = addr4 = 0;

		if (address.GetLength() == 4)
		{
			addr1 = address[0]->ToInt();
			addr2 = address[1]->ToInt();
			addr3 = address[2]->ToInt();
			addr4 = address[3]->ToInt();
		}
	}
	
	V3DString V3DIpV4Address::ToString() const
	{
		V3DString result;
		
		result += V3DString(addr1) + ".";
		result += V3DString(addr2) + ".";
		result += V3DString(addr3) + ".";
		result += V3DString(addr4);
		
		return result;
	}
}
