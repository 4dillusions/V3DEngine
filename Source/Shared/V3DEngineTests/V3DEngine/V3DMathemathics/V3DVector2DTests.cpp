/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector2DTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DVector2D.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <cmath>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DVector2DTests::OperatorsTest()
	{
		const V3DVector2D Vec{ 20, 30 };
		const V3DVector2D Vec2 = Vec;
		const V3DVector2D Vec3 = Vec;

		const V3DVector2D Vec4 = static_cast<V3DVector2D>(12);
		V3DVector2D vec5{ 20, 30 };

		V3DTest::AssertOk(Vec == Vec2, V3DFILE_INFO);
		V3DTest::AssertOk(Vec == Vec3, V3DFILE_INFO);
		V3DTest::AssertOk(Vec4.x == 12.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Vec4.y == 12.0f, V3DFILE_INFO);
		V3DTest::AssertOk(Vec != V3DVector2D(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector2D(1, 2) + V3DVector2D(3, 4)) == V3DVector2D(4, 6), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) + 10) == V3DVector2D(11, 12), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(3, 4) - V3DVector2D(1, 2)) == V3DVector2D(2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) - 1) == V3DVector2D(0, 1), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) * V3DVector2D(3, 4)) == V3DVector2D(3, 8), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) * 10) == V3DVector2D(10, 20), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(30, 20) / V3DVector2D(15, 5)) == V3DVector2D(2, 4), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) / 10) == V3DVector2D(0.1f, 0.2f), V3DFILE_INFO);

		V3DTest::AssertOk(-V3DVector2D(1, 2) == V3DVector2D(-1, -2), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(21, 31) == ++vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(22, 32) == vec5++, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(21, 31) == --vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(20, 30) == --vec5, V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector2D(1, 2) += V3DVector2D(3, 4)) == V3DVector2D(4, 6), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) += 10) == V3DVector2D(11, 12), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(3, 4) -= V3DVector2D(1, 2)) == V3DVector2D(2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) -= 1) == V3DVector2D(0, 1), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) *= V3DVector2D(3, 4)) == V3DVector2D(3, 8), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) *= 10) == V3DVector2D(10, 20), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(30, 20) /= V3DVector2D(15, 5)) == V3DVector2D(2, 4), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) /= 10) == V3DVector2D(0.1f, 0.2f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(1, 2) < V3DVector2D(2, 3), V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(2, 3) > V3DVector2D(1, 2), V3DFILE_INFO);
	}
	
	void V3DVector2DTests::FunctionsTest()
	{
		V3DVector2D vec{ 20, 30 };
		vec.Zero();

		V3DVector2D vec2{ 1, 1 }, vec3{ 1, 1 };
		vec2.Rotate90DegreeForward();
		vec3.Rotate90DegreeBackward();

		V3DTest::AssertOk(vec == V3DVector2D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector2D(0, 0), V3DFILE_INFO);
		V3DTest::AssertOk(vec2 == V3DVector2D(1, -1), V3DFILE_INFO);
		V3DTest::AssertOk(vec3 == V3DVector2D(-1, 1), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(0, 8).Length() == 8.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-6, 8).Length() == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(5, 12).Length() == 13.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-3, 0.5f).Distance(V3DVector2D(5, 6.5)) == 10.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-6, 8).DotProduct(V3DVector2D(5, 12)) == 66.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(3, 1).CrossProduct(V3DVector2D(4, 8)) == 20.0f, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(3, 4).Normalise() == 5.0f, V3DFILE_INFO);

		vec = V3DVector2D(3, 1);
		vec.Normalizing();
		V3DTest::AssertOk(ceilf(vec.Length()) == 1, V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(-6, -6).MidPoint(V3DVector2D(10, 2)) == V3DVector2D(2, -2), V3DFILE_INFO);
	}

	void V3DVector2DTests::RunAllUnitTests()
	{
		OperatorsTest();
		FunctionsTest();
	}

	void V3DVector2DTests::RegisterIntegrationTests()
	{
	}

	void V3DVector2DTests::RegisterTimingTests()
	{
	}
}
