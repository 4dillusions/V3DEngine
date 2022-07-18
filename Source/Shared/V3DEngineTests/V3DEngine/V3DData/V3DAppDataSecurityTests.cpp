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
		V3DTest::AssertOk(V3DAppDataSecurity::GetIsAllAppDataValid(V3DString("secret key 123"), V3DString("7f52636c3b7c703aa4fd92361c181f6f1108ef317da8e7276c858eee9f9dfae2")), V3DFILE_INFO);
	}

	void V3DAppDataSecurityTests::RunAllTests()
	{
		AllAppDataValidTest();
	}
}
