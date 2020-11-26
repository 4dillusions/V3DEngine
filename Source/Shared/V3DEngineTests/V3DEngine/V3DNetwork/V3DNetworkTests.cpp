/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DNetworkTests.h"

#include "V3DNetTest.h"
#include "V3DIpV4AddressTest.h"
#include "V3DSocketAddressTest.h"
#include "V3DTCPSocketTest.h"
#include "V3DUDPSocketTest.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DNetworkTests::RunAllTests()
	{
		V3DNetTest::RunAllTests();
		V3DIpV4AddressTest::RunAllTests();
		V3DSocketAddressTest::RunAllTests();
		V3DTCPSocketTest::RunAllTests();
		V3DUDPSocketTest::RunAllTests();
	}
}
