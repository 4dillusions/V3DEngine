/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTest.h"
#include "V3DEngine/V3DTypesTests.h"
#include "V3DEngine/V3DMathemathics/V3DMathematicsTests.h"

namespace V3D::V3DEngineTests::V3DEngine
{
	inline void RunAllTests()
	{
		V3DTypesTests::RunAllTests();
		V3DMathematics::V3DMathematicsTests::RunAllTests();
		
		V3DTest::WriteStatistics();
	}
}
