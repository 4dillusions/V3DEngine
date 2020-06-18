/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRandomClassicTest.h"

#include "V3DMathematicsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DRandomClassic.h"
#include "V3DEngine/V3DMathematics/V3DVector2D.h"

#include <string>

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DRandomClassicTest::RandomClassicTest()
	{
		int rand10Counter = 0;
		const int rand10 = V3DRandomClassic::CreateRandom(0, 100), rand11 = V3DRandomClassic::CreateRandom(0, 100), rand12 = V3DRandomClassic::CreateRandom(0, 100);
		const int rand13 = V3DRandomClassic::CreateRandom(0, 100), rand14 = V3DRandomClassic::CreateRandom(0, 100), rand15 = V3DRandomClassic::CreateRandom(0, 100);
		if (rand10 == rand13) rand10Counter++;
		if (rand11 == rand14) rand10Counter++;
		if (rand12 == rand15) rand10Counter++;
		V3DTest::AssertOk(rand10Counter < 3, V3DFILE_INFO);

		const int rand20 = V3DRandomClassic::CreateRandom(0, 100), rand21 = V3DRandomClassic::CreateRandom(0, 100), rand22 = V3DRandomClassic::CreateRandom(0, 100);
		V3DTest::AssertOk(rand20 != rand21, V3DFILE_INFO);
		V3DTest::AssertOk(rand20 != rand22, V3DFILE_INFO);
		V3DTest::AssertOk(rand21 != rand22, V3DFILE_INFO);

		const V3DVector2D rand30 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100)), rand31 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100)), rand32 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		V3DTest::AssertOk(rand30 != rand31, V3DFILE_INFO);
		V3DTest::AssertOk(rand30 != rand32, V3DFILE_INFO);
		V3DTest::AssertOk(rand31 != rand32, V3DFILE_INFO);
	}

	void V3DRandomClassicTest::TimingTest()
	{
		for (int i = 0; i < V3DMathematicsTests::randomCountSize; i++)
			V3DRandomClassic::CreateRandom(0, V3DMathematicsTests::maxRandom);
	}
	
	void V3DRandomClassicTest::RunAllTests()
	{	
		RandomClassicTest();

		V3DTest::AddTimingTest("V3DRandomClassicTimingTest", TimingTest);
	}
}
