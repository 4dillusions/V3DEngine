/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector4DTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DVector4D.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DVector4DTests::OperatorsTest()
	{
		const V3DVector4D Vec(20, 30, 40, 50);
		const V3DVector4D Vec2 = Vec;
		const V3DVector4D Vec3 = Vec;

		const V3DVector4D Vec4 = static_cast<V3DVector4D>(12);
		V3DVector4D vec5(20, 30, 40, 50);

		V3DTest::AssertOk(Vec == Vec2, V3DFILE_INFO);
		V3DTest::AssertOk(Vec == Vec3, V3DFILE_INFO);
		V3DTest::AssertOk(Vec4.x == 12, V3DFILE_INFO);
		V3DTest::AssertOk(Vec4.y == 12, V3DFILE_INFO);
		V3DTest::AssertOk(Vec != V3DVector4D(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) + V3DVector4D(3, 4, 5, 6)) == V3DVector4D(4, 6, 8, 10), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) + 10) == V3DVector4D(11, 12, 13, 14), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(3, 4, 5, 6) - V3DVector4D(1, 2, 3, 4)) == V3DVector4D(2, 2, 2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) - 1) == V3DVector4D(0, 1, 2, 3), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) * V3DVector4D(3, 4, 5, 6)) == V3DVector4D(3, 8, 15, 24), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) * 10) == V3DVector4D(10, 20, 30, 40), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(30, 20, 60, 100) / V3DVector4D(15, 5, 10, 20)) == V3DVector4D(2, 4, 6, 5), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 314, 234) / 10) == V3DVector4D(0.1f, 0.2f, 31.4f, 23.4f), V3DFILE_INFO);

		V3DTest::AssertOk(-V3DVector4D(1, 2, 3, 4) == V3DVector4D(-1, -2, -3, -4), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector4D(21, 31, 41, 51) == ++vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(22, 32, 42, 52) == vec5++, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(21, 31, 41, 51) == --vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(20, 30, 40, 50) == --vec5, V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) += V3DVector4D(3, 4, 5, 6)) == V3DVector4D(4, 6, 8, 10), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) += 10) == V3DVector4D(11, 12, 13, 14), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(3, 4, 5, 6) -= V3DVector4D(1, 2, 3, 4)) == V3DVector4D(2, 2, 2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) -= 1) == V3DVector4D(0, 1, 2, 3), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) *= V3DVector4D(3, 4, 5, 6)) == V3DVector4D(3, 8, 15, 24), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) *= 10) == V3DVector4D(10, 20, 30, 40), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(30, 20, 60, 100) /= V3DVector4D(15, 5, 10, 20)) == V3DVector4D(2, 4, 6, 5), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 314, 234) /= 10) == V3DVector4D(0.1f, 0.2f, 31.4f, 23.4f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector4D(1, 2, 3, 4) < V3DVector4D(2, 3, 4, 5), V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(2, 3, 4, 5) > V3DVector4D(1, 2, 3, 4), V3DFILE_INFO);
	}
	
	void V3DVector4DTests::FunctionsTest()
	{
		V3DVector4D vec(20, 30, 40, 50);
		vec.Zero();
		V3DTest::AssertOk(vec == V3DVector4D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector4D(0, 0, 0, 0), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector4D(1, 2, 3, 4).DotProduct(V3DVector4D(6, 7, 8, 9)) == 80, V3DFILE_INFO);
	}
	
	void V3DVector4DTests::RunAllTests()
	{	
		OperatorsTest();
		FunctionsTest();
	}
}
