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
	void V3DNetworkTests::RunAllUnitTests()
	{
		V3DNetTests::RunAllUnitTests();
		V3DIpV4AddressTests::RunAllUnitTests();
		V3DSocketAddressTests::RunAllUnitTests();
		V3DTCPSocketTests::RunAllUnitTests();
		V3DUDPSocketTests::RunAllUnitTests();
	}

	void V3DNetworkTests::RegisterIntegrationTests()
	{
		V3DNetTests::RegisterIntegrationTests();
		V3DIpV4AddressTests::RegisterIntegrationTests();
		V3DSocketAddressTests::RegisterIntegrationTests();
		V3DTCPSocketTests::RegisterIntegrationTests();
		V3DUDPSocketTests::RegisterIntegrationTests();
	}

	void V3DNetworkTests::RegisterTimingTests()
	{
		V3DNetTests::RegisterIntegrationTests();
		V3DIpV4AddressTests::RegisterIntegrationTests();
		V3DSocketAddressTests::RegisterIntegrationTests();
		V3DTCPSocketTests::RegisterIntegrationTests();
		V3DUDPSocketTests::RegisterIntegrationTests();
	}
}
