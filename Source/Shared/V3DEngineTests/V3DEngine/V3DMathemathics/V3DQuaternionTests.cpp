/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DQuaternionTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DQuaternion.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <cmath>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DQuaternionTests::OperatorsTest()
	{
		const V3DQuaternion Quat{ 20, 30, 40, 50 };
		const V3DQuaternion Quat2 = Quat;
		const V3DQuaternion Quat3 = Quat;

		V3DTest::AssertOk(Quat == Quat2, V3DFILE_INFO);
		V3DTest::AssertOk(Quat == Quat3, V3DFILE_INFO);
		V3DTest::AssertOk(Quat.x == 30, V3DFILE_INFO);
		V3DTest::AssertOk(Quat.y == 40, V3DFILE_INFO);
		V3DTest::AssertOk(Quat.z == 50, V3DFILE_INFO);
		V3DTest::AssertOk(Quat.w == 20, V3DFILE_INFO);
		V3DTest::AssertOk(Quat != V3DQuaternion(), V3DFILE_INFO);

		V3DTest::AssertOk((V3DQuaternion(1, 2, 3, 4) + V3DQuaternion(3, 4, 5, 6)) == V3DQuaternion(4, 6, 8, 10), V3DFILE_INFO);
		V3DTest::AssertOk((V3DQuaternion(3, 4, 5, 6) - V3DQuaternion(1, 2, 3, 4)) == V3DQuaternion(2, 2, 2, 2), V3DFILE_INFO);

		V3DTest::AssertOk((V3DQuaternion(1, 2, 3, 4) * V3DQuaternion(4, 5, 6, 7)) == V3DQuaternion(-52, 10, 24, 20), V3DFILE_INFO);
		V3DTest::AssertOk((V3DQuaternion(1, 2, 3, 4) * 10) == V3DQuaternion(10, 20, 30, 40), V3DFILE_INFO);
	}
	
	void V3DQuaternionTests::FunctionsTest()
	{
		V3DTest::AssertOk(V3DQuaternion(0.1, 0.2, 0.2, 0.4).Length() == 0.5, V3DFILE_INFO);
		V3DTest::AssertOk(V3DQuaternion(1, 2, 3, 4).DotProduct(V3DQuaternion(6, 7, 8, 10)) == 84, V3DFILE_INFO);

		V3DTest::AssertOk(V3DQuaternion(1, 1, 1, 1).RotationAngle() == 60, V3DFILE_INFO);
		V3DTest::AssertOk(V3DQuaternion(1, 0, 0, 0).RotationAngle() == 180, V3DFILE_INFO);
		V3DTest::AssertOk(V3DQuaternion(0.7071, 0, 0.7071, 0).RotationAngle() == 90, V3DFILE_INFO);
		
		V3DTest::AssertOk(V3DQuaternion(1, 2, 3, 4).RotationAxis() == V3DVector3D(2, 3, 4), V3DFILE_INFO);
		V3DVector3D vecAxis;
		V3DQuaternion(1, 2, 3, 4).ToRotationAxis(vecAxis);
		V3DTest::AssertOk(vecAxis == V3DVector3D(2, 3, 4), V3DFILE_INFO);

		const V3DMatrix3 RotMatrix1(1, 0, 0, 0, 1, 0, 0, 0, 1);
		const V3DMatrix3 RotMatrix2(0, 0, 1, 1, 0, 0, 0, 1, 0);
		const V3DQuaternion quat1(1, 0, 0, 0);
		const V3DQuaternion quat2(0.5, 0.5, 0.5, 0.5);
		V3DMatrix3 rotMatrixFromQuat;
		V3DQuaternion quaternionFromRotMatrix;

		V3DTest::AssertOk(V3DQuaternion(RotMatrix1) == quat1, V3DFILE_INFO);
		V3DTest::AssertOk(V3DQuaternion(RotMatrix2) == quat2, V3DFILE_INFO);
		
		quaternionFromRotMatrix.FromRotationMatrix(RotMatrix1);
		V3DTest::AssertOk(quaternionFromRotMatrix == quat1, V3DFILE_INFO);
		quaternionFromRotMatrix.FromRotationMatrix(RotMatrix2);
		V3DTest::AssertOk(quaternionFromRotMatrix == quat2, V3DFILE_INFO);

		quat1.ToRotationMatrix(rotMatrixFromQuat);
		V3DTest::AssertOk(rotMatrixFromQuat == RotMatrix1, V3DFILE_INFO);
		quat2.ToRotationMatrix(rotMatrixFromQuat);
		V3DTest::AssertOk(rotMatrixFromQuat == RotMatrix2, V3DFILE_INFO);
		
		V3DTest::AssertOk(V3DQuaternion(1, 2, 3, 4).Normalise() == V3DQuaternion(1, 2, 3, 4).Length(), V3DFILE_INFO);

		quaternionFromRotMatrix.Normalizing();
		V3DTest::AssertOk(ceilf(quaternionFromRotMatrix.Length()) == 1, V3DFILE_INFO);
	}
	
	void V3DQuaternionTests::RunAllTests()
	{	
		OperatorsTest();
		FunctionsTest();
	}
}
