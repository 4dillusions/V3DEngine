/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAppDataSecurityTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DData/V3DAppDataSecurity.h"
#include "V3DEngine/V3DCore/V3DString.h"

using namespace V3D::V3DEngine::V3DData;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DData
{
	void V3DAppDataSecurityTests::AllAppDataValidTest()
	{
		//online tool: https://www.devglan.com/online-tools/hmac-sha256-online
		V3DTest::AssertOk(V3DAppDataSecurity::GetIsAllAppDataValid(V3DString("secret key 123"), V3DString("e9bd672aa4e99f7ab21e122bbd2c606aebd3fc66d40eb58ace8357c1d85b7f91")), V3DFILE_INFO);
	}

	void V3DAppDataSecurityTests::RunAllUnitTests()
	{
		AllAppDataValidTest();
	}

	void V3DAppDataSecurityTests::RegisterIntegrationTests()
	{
	}

	void V3DAppDataSecurityTests::RegisterTimingTests()
	{
	}
}
