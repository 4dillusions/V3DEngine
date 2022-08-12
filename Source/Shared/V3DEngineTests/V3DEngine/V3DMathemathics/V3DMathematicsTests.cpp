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
	void V3DMathematicsTests::RunAllUnitTests()
	{
		V3DMathTests::RunAllUnitTests();
		V3DVector2DTests::RunAllUnitTests();
		V3DVector3DTests::RunAllUnitTests();
		V3DCircleTests::RunAllUnitTests();
		V3DRectangleTests::RunAllUnitTests();
		V3DVector4DTests::RunAllUnitTests();
		V3DMatrix3Tests::RunAllUnitTests();
		V3DMatrix4Tests::RunAllUnitTests();
		V3DQuaternionTests::RunAllUnitTests();
		V3DRandomTests::RunAllUnitTests();
		V3DRandomClassicTests::RunAllUnitTests();
	}

	void V3DMathematicsTests::RegisterIntegrationTests()
	{
		V3DMathTests::RegisterIntegrationTests();
		V3DVector2DTests::RegisterIntegrationTests();
		V3DVector3DTests::RegisterIntegrationTests();
		V3DCircleTests::RegisterIntegrationTests();
		V3DRectangleTests::RegisterIntegrationTests();
		V3DVector4DTests::RegisterIntegrationTests();
		V3DMatrix3Tests::RegisterIntegrationTests();
		V3DMatrix4Tests::RegisterIntegrationTests();
		V3DQuaternionTests::RegisterIntegrationTests();
		V3DRandomTests::RegisterIntegrationTests();
		V3DRandomClassicTests::RegisterIntegrationTests();
	}

	void V3DMathematicsTests::RegisterTimingTests()
	{
		V3DMathTests::RegisterTimingTests();
		V3DVector2DTests::RegisterTimingTests();
		V3DVector3DTests::RegisterTimingTests();
		V3DCircleTests::RegisterTimingTests();
		V3DRectangleTests::RegisterTimingTests();
		V3DVector4DTests::RegisterTimingTests();
		V3DMatrix3Tests::RegisterTimingTests();
		V3DMatrix4Tests::RegisterTimingTests();
		V3DQuaternionTests::RegisterTimingTests();
		V3DRandomTests::RegisterTimingTests();
		V3DRandomClassicTests::RegisterTimingTests();
	}
}
