/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DNetworkTests.h"

#include "V3DNetTests.h"
#include "V3DIpV4AddressTests.h"
#include "V3DSocketAddressTests.h"
#include "V3DTCPSocketTests.h"
#include "V3DUDPSocketTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DNetworkTests::RunAllTests()
	{
		V3DNetTests::RunAllTests();
		V3DIpV4AddressTests::RunAllTests();
		V3DSocketAddressTests::RunAllTests();
		V3DTCPSocketTests::RunAllTests();
		V3DUDPSocketTests::RunAllTests();
	}
}
