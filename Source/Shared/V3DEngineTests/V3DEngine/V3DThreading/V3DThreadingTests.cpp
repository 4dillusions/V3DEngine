/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DThreadingTests.h"
#include "V3DTaskPoolTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DThreading
{
	void V3DThreadingTests::RunAllUnitTests()
	{
		V3DTaskPoolTests::RunAllUnitTests();
	}

	void V3DThreadingTests::RegisterIntegrationTests()
	{
		V3DTaskPoolTests::RegisterIntegrationTests();
	}

	void V3DThreadingTests::RegisterTimingTests()
	{
		V3DTaskPoolTests::RegisterTimingTests();
	}
}
