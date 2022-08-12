/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDataTests.h"
#include "V3DAppDataSecurityTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DData
{	
	void V3DDataTests::RunAllUnitTests()
	{
		V3DAppDataSecurityTests::RunAllUnitTests();
	}

	void V3DDataTests::RegisterIntegrationTests()
	{
		V3DAppDataSecurityTests::RegisterIntegrationTests();
	}

	void V3DDataTests::RegisterTimingTests()
	{
		V3DAppDataSecurityTests::RegisterTimingTests();
	}
}
