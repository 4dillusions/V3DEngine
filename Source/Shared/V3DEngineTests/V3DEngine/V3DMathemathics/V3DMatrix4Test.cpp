/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMatrix4Test.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMatrix4.h"
#include "V3DEngine/V3DMathematics/V3DVector2D.h"
#include "V3DEngine/V3DMathematics/V3DVector3D.h"
#include "V3DEngine/V3DMathematics/V3DVector4D.h"

#include <cmath>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMatrix4Test::OperatorsTest()
	{
		const V3DMatrix4 Mat
		(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f, 7.0f);

		const V3DMatrix4 Mat2 = Mat;
		const V3DMatrix4 Mat3 = Mat;

		V3DTest::AssertOk(Mat == Mat2, V3DFILE_INFO);
		V3DTest::AssertOk(Mat == Mat3, V3DFILE_INFO);
		V3DTest::AssertOk(Mat != V3DMatrix4(), V3DFILE_INFO);

		V3DTest::AssertOk((Mat + Mat2) == V3DMatrix4
		(2.0f, 4.0f, 6.0f, 8.0f,
			10.0f, 12.0f, 14.0f, 16.0f,
			18.0f, 2.0f, 4.0f, 6.0f,
			8.0f, 10.0f, 12.0f, 14.0f), V3DFILE_INFO);

		V3DTest::AssertOk((Mat - Mat2) == V3DMatrix4(), V3DFILE_INFO);

		V3DTest::AssertOk((Mat * Mat2) == V3DMatrix4
		(54.0f, 37.0f, 47.0f, 57.0f,
			130.0f, 93.0f, 119.0f, 145.0f,
			44.0f, 41.0f, 56.0f, 71.0f,
			111.0f, 79.0f, 101.0f, 123.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector3D(0.0f, 0.0f, -1.0f) == V3DVector3D(10.0f, 0.0f, -1.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector4D(0.0f, 0.0f, -1.0f, 0.0f) == V3DVector4D(0.0f, 0.0f, -1.0f, 0.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 0.0f, 0.0f, 10.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f) * V3DVector4D(10.0f, 10.0f, 10.0f, 1.0f) == V3DVector4D(20.0f, 10.0f, 10.0f, 1.0f), V3DFILE_INFO);

		V3DTest::AssertOk((Mat * 10) == V3DMatrix4
		(10.0f, 20.0f, 30.0f, 40.0f,
			50.0f, 60.0f, 70.0f, 80.0f,
			90.0f, 10.0f, 20.0f, 30.0f,
			40.0f, 50.0f, 60.0f, 70.0f), V3DFILE_INFO);
	}

	void V3DMatrix4Test::FunctionsTest()
	{
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
		V3DTest::AssertOk(mat4 == V3DMatrix4
		(2.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 2.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 2.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f), V3DFILE_INFO);
		V3DTest::AssertOk(mat4.IsHasScale() == true, V3DFILE_INFO);
		V3DTest::AssertOk(mat4 == V3DMatrix4().GetScale(V3DVector3D(2, 2, 2)), V3DFILE_INFO);

		mat4.Identity();
		V3DTest::AssertOk(mat4.IsAffine() == true, V3DFILE_INFO);

		const V3DMatrix4 MatAff
		(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 0.0f,
			1.0f, 0.0f, 0.0f, 1.0f);
		V3DMatrix4 matAff2;
		matAff2.Identity();
		V3DTest::AssertOk(MatAff.Concatenate(MatAff.Inverse()) == matAff2, V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 1.0f, 1.0f, 1.0f,
			2.0f, 2.0f, 2.0f, 2.0f,
			3.0f, 3.0f, 3.0f, 3.0f,
			4.0f, 4.0f, 4.0f, 4.0f).TransformAffine(V3DVector3D(1, 1, 1)) == V3DVector3D(4, 8, 12), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 1.0f, 1.0f, 1.0f,
			2.0f, 2.0f, 2.0f, 2.0f,
			3.0f, 3.0f, 3.0f, 3.0f,
			4.0f, 4.0f, 4.0f, 4.0f).TransformAffine(V3DVector4D(1, 1, 1, 1)) == V3DVector4D(4, 8, 12, 1), V3DFILE_INFO);

		const V3DMatrix4 Mat5
		(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 20.0f,
			1.0f, 0.0f, 0.0f, 1.0f);
		V3DMatrix4 mat6;
		mat6.Identity();
		V3DTest::AssertOk(Mat5.Concatenate(Mat5.Inverse()) == mat6, V3DFILE_INFO);

		V3DTest::AssertOk(Mat5.ConcatenateAffine(Mat5.InverseAffine()) == mat6, V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f, 0.0f,
			1.0f, 0.0f, 0.0f, 1.0f).Inverse() ==
			V3DMatrix4
			(1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, -1.0f, 1.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f, 1.0f), V3DFILE_INFO);

		const V3DMatrix4 Mat
		(1.0f, 2.0f, 3.0f, 4.0f,
			5.0f, 6.0f, 7.0f, 8.0f,
			9.0f, 1.0f, 2.0f, 3.0f,
			4.0f, 5.0f, 6.0f, 7.0f);

		V3DTest::AssertOk(V3DMatrix4(Mat).Transpose() ==
			V3DMatrix4
			(1.0f, 5.0f, 9.0f, 4.0f,
				2.0f, 6.0f, 1.0f, 5.0f,
				3.0f, 7.0f, 2.0f, 6.0f,
				4.0f, 8.0f, 3.0f, 7.0f), V3DFILE_INFO);

		V3DTest::AssertOk(V3DMatrix4
		(3.0f, 0.0f, 2.0f, -1.0f,
			1.0f, 2.0f, 0.0f, -2.0f,
			4.0f, 0.0f, 6.0f, -3.0f,
			5.0f, 0.0f, 2.0f, 0.0f).Determinant() == 20.0f, V3DFILE_INFO);
	}

	void V3DMatrix4Test::RunAllTests()
	{
		OperatorsTest();
		FunctionsTest();
	}
}
