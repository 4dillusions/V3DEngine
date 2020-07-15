/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCoreTests.h"

#include "V3DTupleTest.h"
#include "V3DStopperTest.h"
#include "V3DTimeHourTest.h"
#include "V3DWatchTest.h"
#include "V3DMemoryTest.h"
#include "V3DIocTest.h"
#include "V3DStringTest.h"
#include "V3DDateTimeTest.h"
#include "V3DGameComponentTest.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DCoreTests::RunAllTests()
	{
		V3DTupleTest::RunAllTests();
		V3DStopperTest::RunAllTests();
		V3DTimeHourTest::RunAllTests();
		V3DWatchTest::RunAllTests();
		V3DMemoryTest::RunAllTests();
		V3DIocTest::RunAllTests();
		V3DStringTest::RunAllTests();
		V3DDateTimeTest::RunAllTests();
		V3DGameComponentTest::RunAllTests();
	}
}
