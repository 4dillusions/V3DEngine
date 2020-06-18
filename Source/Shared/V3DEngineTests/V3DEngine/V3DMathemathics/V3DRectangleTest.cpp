/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRectangleTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DRectangle.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DRectangleTest::RectangleTest()
	{
		const V3DRectangle rectangle{ 0, 0, 20, 30 };
		const V3DRectangle rectangle2 = rectangle;
		const V3DRectangle rectangle3 = rectangle;
		const V3DRectangle rectangle4{ 100, 100, 100, 100 };

		V3DTest::AssertOk(rectangle == rectangle2, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle == rectangle3, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle != V3DRectangle(), V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.GetLeft() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.GetRight() == 20, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.GetTop() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.GetBottom() == 30, V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.Contains(10, 29), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.Contains(V3DRectangle(0, 0, 5, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle.Contains(V3DRectangle(0, 0, 30, 40)), V3DFILE_INFO);
		V3DTest::AssertOk(rectangle.Intersects(V3DRectangle(0, 0, 30, 40)), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle.Intersects(V3DRectangle(20, 30, 10, 10)), V3DFILE_INFO);

		V3DTest::AssertOk(rectangle4.Contains(134, 137), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle4.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(rectangle4.Contains(V3DRectangle(120, 140, 5, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle4.Contains(V3DRectangle(0, 0, 300, 400)), V3DFILE_INFO);
		V3DTest::AssertOk(rectangle4.Intersects(V3DRectangle(0, 0, 300, 400)), V3DFILE_INFO);
		V3DTest::AssertOk(!rectangle4.Intersects(V3DRectangle(202, 203, 10, 10)), V3DFILE_INFO);
	}
	
	void V3DRectangleTest::RunAllTests()
	{	
		RectangleTest();
	}
}
