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
		V3DTest::AssertOk(V3DAppDataSecurity::GetIsAllAppDataValid(V3DString("secret key 123"), V3DString("f6c5a0093e3958c85919f6216c97082dd69b91e9c28434f4e3a64060a6c5798c")), V3DFILE_INFO);
	}

	void V3DAppDataSecurityTests::RunAllTests()
	{
		AllAppDataValidTest();
	}
}
