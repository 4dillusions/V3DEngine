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
	void V3DCoreTests::RunAllTests()
	{
		V3DTupleTests::RunAllTests();
		V3DStopperTests::RunAllTests();
		V3DTimeHourTests::RunAllTests();
		V3DWatchTests::RunAllTests();
		V3DMemoryTests::RunAllTests();
		V3DIocTests::RunAllTests();
		V3DStringTests::RunAllTests();
		V3DDateTimeTests::RunAllTests();
		V3DComponentTests::RunAllTests();
		V3DEventActionFuncTests::RunAllTests();
	}
}
