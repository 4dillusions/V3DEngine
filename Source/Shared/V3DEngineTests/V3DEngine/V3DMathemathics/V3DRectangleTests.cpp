/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRectangleTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DRectangle.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DRectangleTests::RectangleTest()
	{
		const V3DRectangle Rectangle{ 0, 0, 20, 30 };
		const V3DRectangle Rectangle2 = Rectangle;
		const V3DRectangle Rectangle3 = Rectangle;
		const V3DRectangle Rectangle4{ 100, 100, 100, 100 };

		V3DTest::AssertOk(Rectangle == Rectangle2, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle == Rectangle3, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle != V3DRectangle(), V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.GetLeft() == 0.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.GetRight() == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.GetTop() == 0.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.GetBottom() == 30.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.Contains(10, 29), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.Contains(V3DRectangle(0, 0, 5, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle.Contains(V3DRectangle(0, 0, 30, 40)), V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle.Intersects(V3DRectangle(0, 0, 30, 40)), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle.Intersects(V3DRectangle(20, 30, 10, 10)), V3DFILE_INFO);

		V3DTest::AssertOk(Rectangle4.Contains(134, 137), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle4.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle4.Contains(V3DRectangle(120, 140, 5, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle4.Contains(V3DRectangle(0, 0, 300, 400)), V3DFILE_INFO);
		V3DTest::AssertOk(Rectangle4.Intersects(V3DRectangle(0, 0, 300, 400)), V3DFILE_INFO);
		V3DTest::AssertOk(!Rectangle4.Intersects(V3DRectangle(202, 203, 10, 10)), V3DFILE_INFO);
	}
	
	void V3DRectangleTests::RunAllTests()
	{	
		RectangleTest();
	}
}
