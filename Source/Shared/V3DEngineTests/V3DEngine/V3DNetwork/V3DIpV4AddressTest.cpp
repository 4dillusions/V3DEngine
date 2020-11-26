/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIpV4AddressTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DNetwork/V3DIpV4Address.h"

using namespace V3D::V3DEngine::V3DNetwork;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	void V3DIpV4AddressTest::CreateAndConvertAddressTest()
	{
		const V3DIpV4Address ip(196, 168, 1, 2);
		V3DTest::AssertOk(ip.ToString() == V3DString("196.168.1.2"), V3DFILE_INFO);

		const V3DIpV4Address ip2(V3DString("10.5.12.3"));
		V3DTest::AssertOk(ip2.addr1 == 10, V3DFILE_INFO);
		V3DTest::AssertOk(ip2.addr2 == 5, V3DFILE_INFO);
		V3DTest::AssertOk(ip2.addr3 == 12, V3DFILE_INFO);
		V3DTest::AssertOk(ip2.addr4 == 3, V3DFILE_INFO);
	}
	
	void V3DIpV4AddressTest::RunAllTests()
	{	
		CreateAndConvertAddressTest();
	}
}
