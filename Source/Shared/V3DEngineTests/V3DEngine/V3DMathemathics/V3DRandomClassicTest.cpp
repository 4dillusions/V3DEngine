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

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	void V3DRandomClassicTest::RandomClassicTest()
	{
		int randCounter = 0;
		
		const int Rand10 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand11 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand12 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand13 = V3DRandomClassic::CreateRandom(0, 100);
		const int rand14 = V3DRandomClassic::CreateRandom(0, 100);
		const int rand15 = V3DRandomClassic::CreateRandom(0, 100);
		if (Rand10 == Rand13) randCounter++;
		if (Rand11 == rand14) randCounter++;
		if (Rand12 == rand15) randCounter++;
		V3DTest::AssertOk(randCounter < 3, V3DFILE_INFO);

		randCounter = 0;
		const int Rand20 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand21 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand22 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand23 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand24 = V3DRandomClassic::CreateRandom(0, 100);
		const int Rand25 = V3DRandomClassic::CreateRandom(0, 100);
		if (Rand20 == Rand23) randCounter++;
		if (Rand21 == Rand24) randCounter++;
		if (Rand22 == Rand25) randCounter++;
		V3DTest::AssertOk(randCounter < 3, V3DFILE_INFO);
		
		randCounter = 0;
		const V3DVector2D Rand30 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		const V3DVector2D Rand31 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		const V3DVector2D Rand32 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		const V3DVector2D Rand33 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		const V3DVector2D Rand34 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		const V3DVector2D Rand35 = V3DRandomClassic::CreateRandom(V3DVector2D(0, 100), V3DVector2D(50, 100));
		if (Rand30 == Rand33) randCounter++;
		if (Rand31 == Rand34) randCounter++;
		if (Rand32 == Rand35) randCounter++;
		V3DTest::AssertOk(randCounter < 3, V3DFILE_INFO);
	}

	void V3DRandomClassicTest::TimingTest()
	{
		for (int i = 0; i < V3DMathematicsTests::RandomCountSize; i++)
			V3DRandomClassic::CreateRandom(0, V3DMathematicsTests::MaxRandom);
	}
	
	void V3DRandomClassicTest::RunAllTests()
	{	
		RandomClassicTest();

		V3DTest::AddTimingTest("V3DRandomClassicTimingTest", TimingTest);
	}
}
