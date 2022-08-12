/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMathTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DMathTests::MathTest()
	{
		V3DTest::AssertOk(V3DMath::Min(10, 23) == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Max(10, 23) == 23, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Lerp(10, 20, 0.5), 15.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Abs(-3.12), 3.12), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Abs(3.12), 3.12), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Clamp(12.4f, -10.2f, 10.2f), 10.2f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Clamp(-15.2f, -10.3f, 10.3f), -10.3f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Clamp(12, -10, 10) == 10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::Clamp(-15, -10, 10) == -10, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Distance(10.5f, 12.5f), 2.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Log(3, 9), 2.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Log(10, 1000), 3.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Pow(3, 2), 9.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(V3DMath::Pow(10, 3), 1000.0f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsPowerOfTwo(1024), V3DFILE_INFO);
		V3DTest::AssertOk(!V3DMath::IsPowerOfTwo(127), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(3.14f, 3.14f), V3DFILE_INFO);
		V3DTest::AssertOk(!V3DMath::IsEqual(3.141f, 3.14f), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(3.14486, 3.14486), V3DFILE_INFO);
		V3DTest::AssertOk(!V3DMath::IsEqual(3.144861, 3.14486), V3DFILE_INFO);
	}

	void V3DMathTests::RunAllUnitTests()
	{
		MathTest();
	}

	void V3DMathTests::RegisterIntegrationTests()
	{
	}

	void V3DMathTests::RegisterTimingTests()
	{
	}
}
