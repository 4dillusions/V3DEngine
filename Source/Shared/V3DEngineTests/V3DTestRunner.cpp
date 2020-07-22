/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestRunner.h"
#include "V3DTest.h"
#include "V3DEngine/V3DTypesTests.h"
#include "V3DEngine/V3DMathemathics/V3DMathematicsTests.h"
#include "V3DEngine/V3DCore/V3DCoreTests.h"
#include "V3DEngine/V3DIO/V3DIOTests.h"
#include "V3DEngine/V3DCollections/V3DCollectionsTests.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine
{	
	void V3DTestRunner::RunAllTests()
	{
		V3DEnvironment::SetUnitTestMode();
		
		V3DTypesTests::RunAllTests();
		V3DMathematics::V3DMathematicsTests::RunAllTests();
		V3DCore::V3DCoreTests::RunAllTests();
		V3DIO::V3DIOTests::RunAllTests();
		V3DCollections::V3DCollectionsTests::RunAllTests();

		V3DTest::WriteStatistics();
		V3DTest::RunTimingTests();
	}
}
