/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMathematicsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"
#include "V3DEngine/V3DMathematics/V3DVector2D.h"
#include "V3DEngine/V3DMathematics/V3DVector3D.h"
#include "V3DEngine/V3DMathematics/V3DCircle.h"
#include "V3DEngine/V3DMathematics/V3DRectangle.h"
#include "V3DEngine/V3DMathematics/V3DVector4D.h"
#include "V3DEngine/V3DMathematics/V3DMatrix3.h"
#include "V3DEngine/V3DMathematics/V3DMatrix4.h"
#include "V3DEngine/V3DMathematics/V3DRandom.h"

#include <cmath>

using namespace std;

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMathematicsTests::V3DMathTest()
	{
		V3DTest::AssertOk(V3DMath::Min(10, 23) == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Max(10, 23) == 23, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Lerp(10, 20, 0.5) == 15, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Abs(-3.12) == 3.12, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Abs(3.12) == 3.12, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Clamp(12, -10, 10) == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Clamp(-15, -10, 10) == -10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Distance(10.5f, 12.5f) == 2, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Log(3, 9) == 2, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Log(10, 1000) == 3, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Pow(3, 2) == 9, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Pow(10, 3) == 1000, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsPowerOfTwo(1024), V3DFILE_INFO);
		V3DTest::AssertOk(!V3DMath::IsPowerOfTwo(127), V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DVector2DTest()
	{
		V3DVector2D vec{ 20, 30 };
		const V3DVector2D vec2 = vec;
		const V3DVector2D vec3 = vec;

		const V3DVector2D vec4 = static_cast<V3DVector2D>(12);
		V3DVector2D vec7{ 20, 30 };

		V3DTest::AssertOk(vec == vec2, V3DFILE_INFO);
		V3DTest::AssertOk(vec == vec3, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.x == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.y == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec != V3DVector2D(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector2D(1, 2) + V3DVector2D(3, 4)) == V3DVector2D(4, 6), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) + 10) == V3DVector2D(11, 12), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(3, 4) - V3DVector2D(1, 2)) == V3DVector2D(2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) - 1) == V3DVector2D(0, 1), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) * V3DVector2D(3, 4)) == V3DVector2D(3, 8), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) * 10) == V3DVector2D(10, 20), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(30, 20) / V3DVector2D(15, 5)) == V3DVector2D(2, 4), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector2D(1, 2) / 10) == V3DVector2D(0.1f, 0.2f), V3DFILE_INFO);

		V3DTest::AssertOk(-V3DVector2D(1, 2) == V3DVector2D(-1, -2), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(21, 31) == ++vec7, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(22, 32) == vec7++, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(21, 31) == --vec7, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(20, 30) == --vec7, V3DFILE_INFO);

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

		vec.Zero();

		V3DVector2D vec5{ 1, 1 }, vec6{ 1, 1 };
		vec5.Rotate90DegreeForward();
		vec6.Rotate90DegreeBackward();

		V3DTest::AssertOk(vec == V3DVector2D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector2D(0, 0), V3DFILE_INFO);
		V3DTest::AssertOk(vec5 == V3DVector2D(1, -1), V3DFILE_INFO);
		V3DTest::AssertOk(vec6 == V3DVector2D(-1, 1), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(0, 8).Length() == 8, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-6, 8).Length() == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(5, 12).Length() == 13, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-3, 0.5f).Distance(V3DVector2D(5, 6.5)) == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(-6, 8).DotProduct(V3DVector2D(5, 12)) == 66, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(3, 1).CrossProduct(V3DVector2D(4, 8)) == 20, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector2D(3, 4).Normalise() == 5, V3DFILE_INFO);

		vec = V3DVector2D(3, 1);
		vec.Normalizing();
		V3DTest::AssertOk(ceilf(vec.Length()) == 1, V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector2D(-6, -6).MidPoint(V3DVector2D(10, 2)) == V3DVector2D(2, -2), V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DVector3DTest()
	{
		V3DVector3D vec{ 20, 30, 40 };
		const V3DVector3D vec2 = vec;
		const V3DVector3D vec3 = vec;

		const V3DVector3D vec4 = static_cast<V3DVector3D>(12);
		V3DVector3D vec7{ 20, 30, 40 };

		V3DTest::AssertOk(vec == vec2,V3DFILE_INFO);
		V3DTest::AssertOk(vec == vec3,V3DFILE_INFO);
		V3DTest::AssertOk(vec4.x == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.y == 12,V3DFILE_INFO);
		V3DTest::AssertOk(vec != V3DVector3D(),V3DFILE_INFO);
		
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) + V3DVector3D(3, 4, 5)) == V3DVector3D(4, 6, 8),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) + 10) == V3DVector3D(11, 12, 13),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(3, 4, 5) - V3DVector3D(1, 2, 3)) == V3DVector3D(2, 2, 2),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) - 1) == V3DVector3D(0, 1, 2),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) * V3DVector3D(3, 4, 5)) == V3DVector3D(3, 8, 15),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) * 10) == V3DVector3D(10, 20, 30),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(30, 20, 60) / V3DVector3D(15, 5, 10)) == V3DVector3D(2, 4, 6),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 314) / 10) == V3DVector3D(0.1f, 0.2f, 31.4f),V3DFILE_INFO);
		
		V3DTest::AssertOk(-V3DVector3D(1, 2, 3) == V3DVector3D(-1, -2, -3),V3DFILE_INFO);
		
		V3DTest::AssertOk(V3DVector3D(21, 31, 41) == ++vec7,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(22, 32, 42) == vec7++,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(21, 31, 41) == --vec7,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(20, 30, 40) == --vec7,V3DFILE_INFO);
		
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) += V3DVector3D(3, 4, 5)) == V3DVector3D(4, 6, 8),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) += 10) == V3DVector3D(11, 12, 13),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(3, 4, 5) -= V3DVector3D(1, 2, 3)) == V3DVector3D(2, 2, 2),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) -= 1) == V3DVector3D(0, 1, 2),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) *= V3DVector3D(3, 4, 5)) == V3DVector3D(3, 8, 15),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 3) *= 10) == V3DVector3D(10, 20, 30),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(30, 20, 60) /= V3DVector3D(15, 5, 10)) == V3DVector3D(2, 4, 6),V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector3D(1, 2, 314) /= 10) == V3DVector3D(0.1f, 0.2f, 31.4f),V3DFILE_INFO);
		
		V3DTest::AssertOk(V3DVector3D(1, 2, 3) < V3DVector3D(2, 3, 4),V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 3, 4) > V3DVector3D(1, 2, 3),V3DFILE_INFO);
		
		vec.Zero();
		V3DTest::AssertOk(vec == V3DVector3D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector3D(0, 0, 0),V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Length() == 3,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Distance(V3DVector3D(4, 2, 4)) == 3,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(1, 2, 3).DotProduct(V3DVector3D(6, 7, 8)) == 44,V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 3, 4).CrossProduct(V3DVector3D(5, 6, 7)) == V3DVector3D(-3, 6, -3),V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector3D(2, 1, 2).Normalise() == V3DVector3D(2, 1, 2).Length(),V3DFILE_INFO);
		
		vec = V3DVector3D{ 3, 1, 2 };
		vec.Normalizing();
		V3DTest::AssertOk(ceilf(vec.Length()) == 1,V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector3D(2, 4, 6).MidPoint(V3DVector3D(1, 7, 9)) == V3DVector3D(1.5f, 5.5f, 7.5f),V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DCircleTest()
	{
		const V3DCircle circle{ 0, 0, 20 };
		const V3DCircle circle2 = circle;
		const V3DCircle circle3 = circle;

		V3DTest::AssertOk(circle == circle2, V3DFILE_INFO);
		V3DTest::AssertOk(circle == circle3, V3DFILE_INFO);
		V3DTest::AssertOk(circle != V3DCircle(), V3DFILE_INFO);
		V3DTest::AssertOk(circle.Contains(0, 19), V3DFILE_INFO);
		V3DTest::AssertOk(!circle.Contains(20, 30), V3DFILE_INFO);
		V3DTest::AssertOk(circle.Contains(V3DCircle(0, 0, 5)), V3DFILE_INFO);
		V3DTest::AssertOk(!circle.Contains(V3DCircle(0, 40, 10)), V3DFILE_INFO);
		V3DTest::AssertOk(circle.Intersects(V3DCircle(0, 0, 30)), V3DFILE_INFO);
		V3DTest::AssertOk(!circle.Intersects(V3DCircle(20, 30, 10)), V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DRectangleTest()
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

	void V3DMathematicsTests::V3DVector4DTest()
	{
		V3DVector4D vec(20, 30, 40, 50);
		const V3DVector4D vec2 = vec;
		const V3DVector4D vec3 = vec;

		const V3DVector4D vec4 = static_cast<V3DVector4D>(12);
		V3DVector4D vec7(20, 30, 40, 50);

		V3DTest::AssertOk(vec == vec2, V3DFILE_INFO);
		V3DTest::AssertOk(vec == vec3, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.x == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec4.y == 12, V3DFILE_INFO);
		V3DTest::AssertOk(vec != V3DVector4D(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) + V3DVector4D(3, 4, 5, 6)) == V3DVector4D(4, 6, 8, 10), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) + 10) == V3DVector4D(11, 12, 13, 14), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(3, 4, 5, 6) - V3DVector4D(1, 2, 3, 4)) == V3DVector4D(2, 2, 2, 2), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) - 1) == V3DVector4D(0, 1, 2, 3), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) * V3DVector4D(3, 4, 5, 6)) == V3DVector4D(3, 8, 15, 24), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 3, 4) * 10) == V3DVector4D(10, 20, 30, 40), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(30, 20, 60, 100) / V3DVector4D(15, 5, 10, 20)) == V3DVector4D(2, 4, 6, 5), V3DFILE_INFO);
		V3DTest::AssertOk((V3DVector4D(1, 2, 314, 234) / 10) == V3DVector4D(0.1f, 0.2f, 31.4f, 23.4f), V3DFILE_INFO);

		V3DTest::AssertOk(-V3DVector4D(1, 2, 3, 4) == V3DVector4D(-1, -2, -3, -4), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector4D(21, 31, 41, 51) == ++vec7, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(22, 32, 42, 52) == vec7++, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(21, 31, 41, 51) == --vec7, V3DFILE_INFO);
		V3DTest::AssertOk(V3DVector4D(20, 30, 40, 50) == --vec7, V3DFILE_INFO);

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

		vec.Zero();
		V3DTest::AssertOk(vec == V3DVector4D(), V3DFILE_INFO);
		V3DTest::AssertOk(vec == V3DVector4D(0, 0, 0, 0), V3DFILE_INFO);

		V3DTest::AssertOk(V3DVector4D(1, 2, 3, 4).DotProduct(V3DVector4D(6, 7, 8, 9)) == 80, V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DMatrix3Test()
	{
		const V3DMatrix3 mat
		(1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f,
			7.0f, 8.0f, 9.0f);

		const V3DMatrix3 mat2 = mat;
		const V3DMatrix3 mat3 = mat;

		V3DTest::AssertOk(mat == mat2, V3DFILE_INFO);
		V3DTest::AssertOk(mat == mat3, V3DFILE_INFO);
		V3DTest::AssertOk(mat != V3DMatrix3(), V3DFILE_INFO);

		V3DTest::AssertOk((mat + mat2) == V3DMatrix3
		(2.0f, 4.0f, 6.0f,
			8.0f, 10.0f, 12.0f,
			14.0f, 16.0f, 18.0f), V3DFILE_INFO);

		auto mat4 = mat3;
		mat4.Zero();
		V3DTest::AssertOk((mat - mat2) == mat4, V3DFILE_INFO);

		V3DTest::AssertOk((mat * mat2) == V3DMatrix3
		(30.0f, 36.0f, 42.0f,
			66.0f, 81.0f, 96.0f,
			102.0f, 126.0f, 150.0f), V3DFILE_INFO);

		mat4.Identity();
		V3DTest::AssertOk(mat4 == V3DMatrix3
		(1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix3(mat) * V3DVector3D(1, 2, 3) == V3DVector3D(14, 32, 50), V3DFILE_INFO);

		V3DTest::AssertOk((mat * 10) == V3DMatrix3
		(10.0f, 20.0f, 30.0f,
			40.0f, 50.0f, 60.0f,
			70.0f, 80.0f, 90.0f), V3DFILE_INFO);

		V3DMatrix3 mat5 = mat;
		V3DTest::AssertOk(V3DMatrix3(mat5).Inverse(mat5) == false, V3DFILE_INFO);
		V3DMatrix3 mat6
		(1.0f, 3.0f, 3.0f,
			1.0f, 4.0f, 3.0f,
			1.0f, 3.0f, 4.0f);
		V3DTest::AssertOk(mat6.Inverse(mat6) == true, V3DFILE_INFO);

		const V3DMatrix3 mat7
		(1.0f, 3.0f, 3.0f,
			1.0f, 4.0f, 3.0f,
			1.0f, 3.0f, 4.0f);
		V3DTest::AssertOk(mat7.Inverse() == V3DMatrix3
		(7.0f, -3.0f, -3.0f,
			-1.0f, 1.0f, 0.0f,
			-1.0f, 0.0f, 1.0f), V3DFILE_INFO);

		mat4 = mat;
		V3DTest::AssertOk(mat4.Transpose() == V3DMatrix3
		(1.0f, 4.0f, 7.0f,
			2.0f, 5.0f, 8.0f,
			3.0f, 6.0f, 9.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix3
		(-5.0f, 0.0f, -1.0f,
			1.0f, 2.0f, -1.0f,
			-3.0f, 4.0f, 1.0f).Determinant() == -40.0f, V3DFILE_INFO);

		V3DMatrix3 mat8(-5.0f, 3.0f, -1.0f,
			1.0f, 5.0f, -1.0f,
			-3.0f, 4.0f, 10.0f);
		mat8.Orthonormalize();
		const auto mat9 = mat8.Inverse();
		auto mat10 = mat8 * mat9;
		V3DTest::AssertOk(1.0f == floorf(mat10(0, 0)), V3DFILE_INFO);
		V3DTest::AssertOk(1.0f == floorf(mat10(1, 1)), V3DFILE_INFO);
		V3DTest::AssertOk(1.0f == floorf(mat10(2, 2)), V3DFILE_INFO); //A * inverse(A) = Identity, if A -> Orthogonal
	}

	void V3DMathematicsTests::V3DMatrix4Test()
	{
		const V3DMatrix4 mat
		(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f, 7.0f);

		const V3DMatrix4 mat2 = mat;
		const V3DMatrix4 mat3 = mat;

		V3DTest::AssertOk(mat == mat2, V3DFILE_INFO);
		V3DTest::AssertOk(mat == mat3, V3DFILE_INFO);
		V3DTest::AssertOk(mat != V3DMatrix4(), V3DFILE_INFO);

		V3DTest::AssertOk((mat + mat2) == V3DMatrix4
		(2.0f, 4.0f, 6.0f, 8.0f,
			10.0f, 12.0f, 14.0f, 16.0f,
			18.0f, 2.0f, 4.0f, 6.0f,
			8.0f, 10.0f, 12.0f, 14.0f), V3DFILE_INFO);

		V3DTest::AssertOk((mat - mat2) == V3DMatrix4(), V3DFILE_INFO);

		V3DTest::AssertOk((mat * mat2) == V3DMatrix4
		(54.0f, 37.0f, 47.0f, 57.0f,
			130.0f, 93.0f, 119.0f, 145.0f,
			44.0f, 41.0f, 56.0f, 71.0f,
			111.0f, 79.0f, 101.0f, 123.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector3D(0.0f, 0.0f, -1.0f) == V3DVector3D(10.0f, 0.0f, -1.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector4D(0.0f, 0.0f, -1.0f, 0.0f) == V3DVector4D(0.0f, 0.0f, -1.0f, 0.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMatrix4(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector4D(10.0f, 10.0f, 10.0f, 1.0f) == V3DVector4D(20.0f, 10.0f, 10.0f, 1.0f), V3DFILE_INFO);

		V3DTest::AssertOk((mat * 10) == V3DMatrix4
		(10.0f, 20.0f, 30.0f, 40.0f,
			50.0f, 60.0f, 70.0f, 80.0f,
			90.0f, 10.0f, 20.0f, 30.0f,
			40.0f, 50.0f, 60.0f, 70.0f), V3DFILE_INFO);

		V3DMatrix4 matT2D;
		matT2D.SetTranslation(V3DVector2D(2, 2));
		V3DTest::AssertOk(V3DVector2D(2, 2) == matT2D.GetTranslation2D(), V3DFILE_INFO);
		matT2D.MakeTranslation(V3DVector2D(2, 2));
		V3DTest::AssertOk(matT2D == V3DMatrix4::GetTranslation(V3DVector2D(2, 2)), V3DFILE_INFO);

		V3DMatrix4 matT3D;
		matT3D.SetTranslation(V3DVector3D(2, 2, 2));
		V3DTest::AssertOk(V3DVector3D(2, 2, 2) == matT3D.GetTranslation3D(), V3DFILE_INFO);
		matT3D.MakeTranslation(V3DVector3D(2, 2, 2));
		V3DTest::AssertOk(matT3D == V3DMatrix4::GetTranslation(V3DVector3D(2, 2, 2)), V3DFILE_INFO);

		V3DMatrix4 matR, matR2;
		matR.Identity();
		matR.SetRotationYaw(90.0f); //Y
		matR2.m[0][0] = cosf(90.0f);
		matR2.m[0][2] = -sinf(90.0f);
		matR2.m[2][0] = sinf(90.0f);
		matR2.m[2][2] = cosf(90.0f);
		V3DTest::AssertOk(matR.m[0][0] == matR2.m[0][0], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[0][2] == matR2.m[0][2], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[2][0] == matR2.m[2][0], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[2][2] == matR2.m[2][2], V3DFILE_INFO);
		matR.SetRotationPitch(90.0f); //X
		matR2.m[1][1] = cosf(90.0f);
		matR2.m[1][2] = sinf(90.0f);
		matR2.m[2][1] = -sinf(90.0f);
		matR2.m[2][2] = cosf(90.0f);
		V3DTest::AssertOk(matR.m[1][1] == matR2.m[1][1], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[1][2] == matR2.m[1][2], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[2][1] == matR2.m[2][1], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[2][2] == matR2.m[2][2], V3DFILE_INFO);
		matR.SetRotationRoll(90.0f); //Z
		matR2.m[0][0] = cosf(90.0f);
		matR2.m[0][1] = sinf(90.0f);
		matR2.m[1][0] = -sinf(90.0f);
		matR2.m[1][1] = cosf(90.0f);
		V3DTest::AssertOk(matR.m[0][0] == matR2.m[0][0], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[0][1] == matR2.m[0][1], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[1][0] == matR2.m[1][0], V3DFILE_INFO);
		V3DTest::AssertOk(matR.m[1][1] == matR2.m[1][1], V3DFILE_INFO);

		V3DMatrix4 mat4;
		mat4.Identity();
		V3DTest::AssertOk(mat4.IsHasScale() == false, V3DFILE_INFO);
		mat4.SetScale(V3DVector3D(2, 2, 2));
		V3DTest::AssertOk(mat4 == V3DMatrix4(2.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 2.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f), V3DFILE_INFO);
		V3DTest::AssertOk(mat4.IsHasScale() == true, V3DFILE_INFO);
		V3DTest::AssertOk(mat4 == V3DMatrix4().GetScale(V3DVector3D(2, 2, 2)), V3DFILE_INFO);

		mat4.Identity();
		V3DTest::AssertOk(mat4.IsAffine() == true, V3DFILE_INFO);

		const V3DMatrix4 matAff(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 0.0f,
			1.0f, 0.0f, 0.0f, 1.0f);
		V3DMatrix4 matAff2;
		matAff2.Identity();
		V3DTest::AssertOk(matAff.Concatenate(matAff.Inverse()) == matAff2, V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(1.0f, 1.0f, 1.0f, 1.0f,
			2.0f, 2.0f, 2.0f, 2.0f,
			3.0f, 3.0f, 3.0f, 3.0f,
			4.0f, 4.0f, 4.0f, 4.0f).TransformAffine(V3DVector3D(1, 1, 1)) == V3DVector3D(4, 8, 12), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(1.0f, 1.0f, 1.0f, 1.0f,
			2.0f, 2.0f, 2.0f, 2.0f,
			3.0f, 3.0f, 3.0f, 3.0f,
			4.0f, 4.0f, 4.0f, 4.0f).TransformAffine(V3DVector4D(1, 1, 1, 1)) == V3DVector4D(4, 8, 12, 1), V3DFILE_INFO);

		const V3DMatrix4 mat5(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 20.0f,
			1.0f, 0.0f, 0.0f, 1.0f);
		V3DMatrix4 mat6;
		mat6.Identity();
		V3DTest::AssertOk(mat5.Concatenate(mat5.Inverse()) == mat6, V3DFILE_INFO);

		V3DTest::AssertOk(mat5.ConcatenateAffine(mat5.InverseAffine()) == mat6, V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 0.0f,
			1.0f, 0.0f, 0.0f, 1.0f).Inverse() ==
			V3DMatrix4(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, -1.0f, 1.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f, 1.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(mat).Transpose() ==
			V3DMatrix4(1.0f, 5.0f, 9.0f, 4.0f,
				2.0f, 6.0f, 1.0f, 5.0f,
				3.0f, 7.0f, 2.0f, 6.0f,
				4.0f, 8.0f, 3.0f, 7.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4(3.0f, 0.0f, 2.0f, -1.0f,
			1.0f, 2.0f, 0.0f, -2.0f,
			4.0f, 0.0f, 6.0f, -3.0f,
			5.0f, 0.0f, 2.0f, 0.0f).Determinant() == 20.0f, V3DFILE_INFO);
	}

	void V3DMathematicsTests::V3DRandomTest()
	{
		int rand10Counter = 0;
		const int rand10 = V3DRandom::CreateRandom(0, 10), rand11 = V3DRandom::CreateRandom(0, 10), rand12 = V3DRandom::CreateRandom(0, 10);
		const int rand13 = V3DRandom::CreateRandom(0, 10), rand14 = V3DRandom::CreateRandom(0, 10), rand15 = V3DRandom::CreateRandom(0, 10);
		if (rand10 == rand13) rand10Counter++;
		if (rand11 == rand14) rand10Counter++;
		if (rand12 == rand15) rand10Counter++;
		V3DTest::AssertOk(rand10Counter < 3, V3DFILE_INFO);

		const int rand20 = V3DRandom::CreateRandom(0, 10), rand21 = V3DRandom::CreateRandom(0, 10), rand22 = V3DRandom::CreateRandom(0, 10);
		V3DTest::AssertOk(rand20 != rand21, V3DFILE_INFO);
		V3DTest::AssertOk(rand20 != rand22, V3DFILE_INFO);
		V3DTest::AssertOk(rand21 != rand22, V3DFILE_INFO);

		const V3DVector2D rand30 = V3DRandom::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100)), rand31 = V3DRandom::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100)), rand32 = V3DRandom::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		V3DTest::AssertOk(rand30 != rand31, V3DFILE_INFO);
		V3DTest::AssertOk(rand30 != rand32, V3DFILE_INFO);
		V3DTest::AssertOk(rand31 != rand32, V3DFILE_INFO);
	}

	void V3DMathematicsTests::RunAllTests()
	{
		V3DMathTest();
		V3DVector2DTest();
		V3DVector3DTest();
		V3DCircleTest();
		V3DRectangleTest();
		V3DVector4DTest();
		V3DMatrix3Test();
		V3DMatrix4Test();
		V3DRandomTest();
	}
}
