/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCircleTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DCircle.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DCircleTests::CircleTest()
	{
		const V3DCircle Circle{ 0, 0, 20 };
		const V3DCircle Circle2 = Circle;
		const V3DCircle Circle3 = Circle;

		V3DTest::AssertOk(Circle == Circle2, V3DFILE_INFO);
		V3DTest::AssertOk(Circle == Circle3, V3DFILE_INFO);
		V3DTest::AssertOk(Circle != V3DCircle(), V3DFILE_INFO);
		V3DTest::AssertOk(Circle.Contains(0, 19), V3DFILE_INFO);
		V3DTest::AssertOk(!Circle.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(Circle.Contains(V3DCircle(0, 0, 5)), V3DFILE_INFO);
		V3DTest::AssertOk(!Circle.Contains(V3DCircle(0, 40, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(Circle.Intersects(V3DCircle(0, 0, 30)), V3DFILE_INFO);
		V3DTest::AssertOk(!Circle.Intersects(V3DCircle(20, 30, 10)), V3DFILE_INFO);
	}
	
	void V3DCircleTests::RunAllTests()
	{	
		CircleTest();
	}
}
