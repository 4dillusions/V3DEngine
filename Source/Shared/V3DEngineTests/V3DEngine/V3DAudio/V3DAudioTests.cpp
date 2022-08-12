/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAudioTests.h"

#include "V3DAudioIntegrationTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	void V3DAudioTests::RunAllUnitTests()
	{
		V3DAudioIntegrationTests::RunAllUnitTests();
	}

	void V3DAudioTests::RegisterIntegrationTests()
	{
		V3DAudioIntegrationTests::RegisterIntegrationTests();
	}

	void V3DAudioTests::RegisterTimingTests()
	{
		V3DAudioIntegrationTests::RegisterTimingTests();
	}
}
