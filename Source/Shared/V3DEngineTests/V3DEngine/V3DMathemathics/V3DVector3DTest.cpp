/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DVector3DTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DVector3D.h"

#include <cmath>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DVector3DTest::OperatorsTest()
	{
		const V3DVector3D vec{ 20, 30, 40 };
		const V3DVector3D vec2 = vec;
		const V3DVector3D vec3 = vec;

		const V3DVector3D vec4 = static_cast<V3DVector3D>(12);
		V3DVector3D vec5{ 20, 30, 40 };

		V3DTest::AssertOk(vec == vec2, V3DFILE_INFO);
		V3DTest::AssertOk(vec == vec3, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.x == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.y == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec != V3DVector3D(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector3D(1, 2, 3) + V3DVector3D(3, 4, 5)) == V3DVector3D(4, 6, 8), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) + 10) == V3DVector3D(11, 12, 13), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(3, 4, 5) - V3DVector3D(1, 2, 3)) == V3DVector3D(2, 2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) - 1) == V3DVector3D(0, 1, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) * V3DVector3D(3, 4, 5)) == V3DVector3D(3, 8, 15), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) * 10) == V3DVector3D(10, 20, 30), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(30, 20, 60) / V3DVector3D(15, 5, 10)) == V3DVector3D(2, 4, 6), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 314) / 10) == V3DVector3D(0.1f, 0.2f, 31.4f), V3DFILE_INFO);

		V3DTest::AssertOk(-V3DVector3D(1, 2, 3) == V3DVector3D(-1, -2, -3), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(21, 31, 41) == ++vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(22, 32, 42) == vec5++, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(21, 31, 41) == --vec5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(20, 30, 40) == --vec5, V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector3D(1, 2, 3) += V3DVector3D(3, 4, 5)) == V3DVector3D(4, 6, 8), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) += 10) == V3DVector3D(11, 12, 13), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(3, 4, 5) -= V3DVector3D(1, 2, 3)) == V3DVector3D(2, 2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) -= 1) == V3DVector3D(0, 1, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) *= V3DVector3D(3, 4, 5)) == V3DVector3D(3, 8, 15), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) *= 10) == V3DVector3D(10, 20, 30), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(30, 20, 60) /= V3DVector3D(15, 5, 10)) == V3DVector3D(2, 4, 6), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 314) /= 10) == V3DVector3D(0.1f, 0.2f, 31.4f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(1, 2, 3) < V3DVector3D(2, 3, 4), V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 3, 4) > V3DVector3D(1, 2, 3), V3DFILE_INFO);
	}
	
	void V3DVector3DTest::FunctionsTest()
	{
		V3DVector3D vec{ 20, 30, 40 };
		vec.Zero();
		V3DTest::AssertOk(vec == V3DVector3D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector3D(0, 0, 0), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Length() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Distance(V3DVector3D(4, 2, 4)) == 3, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(1, 2, 3).DotProduct(V3DVector3D(6, 7, 8)) == 44, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 3, 4).CrossProduct(V3DVector3D(5, 6, 7)) == V3DVector3D(-3, 6, -3), V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Normalise() == V3DVector3D(2, 1, 2).Length(), V3DFILE_INFO);

		vec = V3DVector3D{ 3, 1, 2 };
		vec.Normalizing();
		V3DTest::AssertOk(ceilf(vec.Length()) == 1, V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(2, 4, 6).MidPoint(V3DVector3D(1, 7, 9)) == V3DVector3D(1.5f, 5.5f, 7.5f), V3DFILE_INFO);
	}
	
	void V3DVector3DTest::RunAllTests()
	{	
		OperatorsTest();
		FunctionsTest();
	}
}
