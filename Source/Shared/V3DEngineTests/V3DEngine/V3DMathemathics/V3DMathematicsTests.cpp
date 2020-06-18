/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMathematicsTests.h"

#include "V3DMathTest.h"
#include "V3DVector2DTest.h"
#include "V3DVector3DTest.h"
#include "V3DCircleTest.h"
#include "V3DRectangleTest.h"
#include "V3DVector4DTest.h"
#include "V3DMatrix3Test.h"
#include "V3DMatrix4Test.h"
#include "V3DRandomTest.h"
#include "V3DRandomClassicTest.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMathematicsTests::RunAllTests()
	{
		V3DMathTest::RunAllTests();
		V3DVector2DTest::RunAllTests();
		V3DVector3DTest::RunAllTests();
		V3DCircleTest::RunAllTests();
		V3DRectangleTest::RunAllTests();
		V3DVector4DTest::RunAllTests();
		V3DMatrix3Test::RunAllTests();
		V3DMatrix4Test::RunAllTests();
		V3DRandomTest::RunAllTests();
		V3DRandomClassicTest::RunAllTests();
	}
}
