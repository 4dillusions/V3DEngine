/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMathematicsTests.h"
#include "V3DMathTests.h"
#include "V3DVector2DTests.h"
#include "V3DVector3DTests.h"
#include "V3DCircleTests.h"
#include "V3DRectangleTests.h"
#include "V3DVector4DTests.h"
#include "V3DMatrix3Tests.h"
#include "V3DMatrix4Tests.h"
#include "V3DQuaternionTests.h"
#include "V3DRandomTests.h"
#include "V3DRandomClassicTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMathematicsTests::RunAllTests()
	{
		V3DMathTests::RunAllTests();
		V3DVector2DTests::RunAllTests();
		V3DVector3DTests::RunAllTests();
		V3DCircleTests::RunAllTests();
		V3DRectangleTests::RunAllTests();
		V3DVector4DTests::RunAllTests();
		V3DMatrix3Tests::RunAllTests();
		V3DMatrix4Tests::RunAllTests();
		V3DQuaternionTests::RunAllTests();
		V3DRandomTests::RunAllTests();
		V3DRandomClassicTests::RunAllTests();
	}
}
