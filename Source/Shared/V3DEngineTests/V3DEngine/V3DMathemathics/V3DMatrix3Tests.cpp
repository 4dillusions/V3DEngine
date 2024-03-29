/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMatrix3Tests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMatrix3.h"
#include "V3DEngine/V3DMathematics/V3DVector3D.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"

// ReSharper disable once CppUnusedIncludeDirective
#include <cmath>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMatrix3Tests::OperatorsTest()
	{
		const V3DMatrix3 Mat
		(1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f,
			7.0f, 8.0f, 9.0f);

		const V3DMatrix3 Mat2 = Mat;
		const V3DMatrix3 Mat3 = Mat;

		V3DTest::AssertOk(Mat == Mat2, V3DFILE_INFO);
		V3DTest::AssertOk(Mat == Mat3, V3DFILE_INFO);
		V3DTest::AssertOk(Mat != V3DMatrix3(), V3DFILE_INFO);

		V3DTest::AssertOk((Mat + Mat2) == V3DMatrix3
		(2.0f, 4.0f, 6.0f,
			8.0f, 10.0f, 12.0f,
			14.0f, 16.0f, 18.0f), V3DFILE_INFO);
	}

	void V3DMatrix3Tests::FunctionsTest()
	{
		const V3DMatrix3 Mat
		(1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f,
			7.0f, 8.0f, 9.0f);

		const V3DMatrix3 Mat2 = Mat;
		const V3DMatrix3 Mat3 = Mat;
		auto mat4 = Mat3;
		mat4.Zero();
		V3DTest::AssertOk((Mat - Mat2) == mat4, V3DFILE_INFO);

		V3DTest::AssertOk((Mat * Mat2) == V3DMatrix3
		(30.0f, 36.0f, 42.0f,
			66.0f, 81.0f, 96.0f,
			102.0f, 126.0f, 150.0f), V3DFILE_INFO);

		mat4.Identity();
		V3DTest::AssertOk(mat4 == V3DMatrix3
		(1.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 1.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix3(Mat) * V3DVector3D(1, 2, 3) == V3DVector3D(14, 32, 50), V3DFILE_INFO);

		V3DTest::AssertOk((Mat * 10) == V3DMatrix3
		(10.0f, 20.0f, 30.0f,
			40.0f, 50.0f, 60.0f,
			70.0f, 80.0f, 90.0f), V3DFILE_INFO);

		V3DMatrix3 mat5 = Mat;
		V3DTest::AssertOk(V3DMatrix3(mat5).Inverse(mat5) == false, V3DFILE_INFO);
		V3DMatrix3 mat6
		(1.0f, 3.0f, 3.0f,
			1.0f, 4.0f, 3.0f,
			1.0f, 3.0f, 4.0f);
		V3DTest::AssertOk(mat6.Inverse(mat6) == true, V3DFILE_INFO);

		const V3DMatrix3 Mat7
		(1.0f, 3.0f, 3.0f,
			1.0f, 4.0f, 3.0f,
			1.0f, 3.0f, 4.0f);
		V3DTest::AssertOk(Mat7.Inverse() == V3DMatrix3
		(7.0f, -3.0f, -3.0f,
			-1.0f, 1.0f, 0.0f,
			-1.0f, 0.0f, 1.0f), V3DFILE_INFO);

		mat4 = Mat;
		V3DTest::AssertOk(mat4.Transpose() == V3DMatrix3
		(1.0f, 4.0f, 7.0f,
			2.0f, 5.0f, 8.0f,
			3.0f, 6.0f, 9.0f), V3DFILE_INFO);

		V3DTest::AssertOk(
			V3DMath::IsEqual(
				V3DMatrix3(-5.0f, 0.0f, -1.0f,
							1.0f, 2.0f, -1.0f,
							-3.0f, 4.0f, 1.0f).Determinant(), -40.0f), V3DFILE_INFO);

		V3DMatrix3 mat8
		(-5.0f, 3.0f, -1.0f,
			1.0f, 5.0f, -1.0f,
			-3.0f, 4.0f, 10.0f);
		mat8.Orthonormalize();
		const auto Mat9 = mat8.Inverse();
		auto mat10 = mat8 * Mat9;
		V3DTest::AssertOk(1.0f == floorf(mat10(0, 0)), V3DFILE_INFO);
		V3DTest::AssertOk(1.0f == floorf(mat10(1, 1)), V3DFILE_INFO);
		V3DTest::AssertOk(1.0f == floorf(mat10(2, 2)), V3DFILE_INFO); //A * inverse(A) = Identity, if A -> Orthogonal
	}

	void V3DMatrix3Tests::RunAllUnitTests()
	{
		OperatorsTest();
		FunctionsTest();
	}

	void V3DMatrix3Tests::RegisterIntegrationTests()
	{
	}

	void V3DMatrix3Tests::RegisterTimingTests()
	{
	}
}
