/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCryptographyTests.h"
#include "V3DCryptographyHelperTests.h"
#include "V3DCryptographyMethodTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	void V3DCryptographyTests::RunAllUnitTests()
	{
		V3DCryptographyHelperTests::RunAllUnitTests();
		V3DCryptographyMethodTests::RunAllUnitTests();
	}

	void V3DCryptographyTests::RegisterIntegrationTests()
	{
		V3DCryptographyHelperTests::RegisterIntegrationTests();
		V3DCryptographyMethodTests::RegisterIntegrationTests();
	}

	void V3DCryptographyTests::RegisterTimingTests()
	{
		V3DCryptographyHelperTests::RegisterTimingTests();
		V3DCryptographyMethodTests::RegisterTimingTests();
	}
}
