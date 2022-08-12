/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCoreTests.h"
#include "V3DTupleTests.h"
#include "V3DStopperTests.h"
#include "V3DTimeHourTests.h"
#include "V3DWatchTests.h"
#include "V3DMemoryTests.h"
#include "V3DIocTests.h"
#include "V3DStringTests.h"
#include "V3DDateTimeTests.h"
#include "V3DComponentTests.h"
#include "V3DEventActionFuncTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DCoreTests::RunAllUnitTests()
	{
		V3DTupleTests::RunAllUnitTests();
		V3DStopperTests::RunAllUnitTests();
		V3DTimeHourTests::RunAllUnitTests();
		V3DWatchTests::RunAllUnitTests();
		V3DMemoryTests::RunAllUnitTests();
		V3DIocTests::RunAllUnitTests();
		V3DStringTests::RunAllUnitTests();
		V3DDateTimeTests::RunAllUnitTests();
		V3DComponentTests::RunAllUnitTests();
		V3DEventActionFuncTests::RunAllUnitTests();
	}

	void V3DCoreTests::RegisterIntegrationTests()
	{
		V3DTupleTests::RegisterIntegrationTests();
		V3DStopperTests::RegisterIntegrationTests();
		V3DTimeHourTests::RegisterIntegrationTests();
		V3DWatchTests::RegisterIntegrationTests();
		V3DMemoryTests::RegisterIntegrationTests();
		V3DIocTests::RegisterIntegrationTests();
		V3DStringTests::RegisterIntegrationTests();
		V3DDateTimeTests::RegisterIntegrationTests();
		V3DComponentTests::RegisterIntegrationTests();
		V3DEventActionFuncTests::RegisterIntegrationTests();
	}

	void V3DCoreTests::RegisterTimingTests()
	{
		V3DTupleTests::RegisterTimingTests();
		V3DStopperTests::RegisterTimingTests();
		V3DTimeHourTests::RegisterTimingTests();
		V3DWatchTests::RegisterTimingTests();
		V3DMemoryTests::RegisterTimingTests();
		V3DIocTests::RegisterTimingTests();
		V3DStringTests::RegisterTimingTests();
		V3DDateTimeTests::RegisterTimingTests();
		V3DComponentTests::RegisterTimingTests();
		V3DEventActionFuncTests::RegisterTimingTests();
	}
}
