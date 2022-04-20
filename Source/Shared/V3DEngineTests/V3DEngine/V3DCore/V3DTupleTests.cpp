/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTupleTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DTuple.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DTupleTests::TupleTest()
	{
		constexpr int V1 = 22;
		constexpr float V2 = 3.14f;
		const auto TupleTest1 = [&](V3DTuple2<int, float>& t)
		{
			t.item1 = V1;
			t.item2 = V2;
		};

		V3DTuple2<int, float> t1(1, 2);
		TupleTest1(t1);
		V3DTest::AssertOk(V3DMath::IsEqual(static_cast<float>(t1.item1), V1), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMath::IsEqual(t1.item2, V2), V3DFILE_INFO);

		constexpr int V3 = 12;
		constexpr int V4 = 34;
		const auto T2 = V3DTuple::Create(V3, V4);
		V3DTest::AssertOk(T2.item1 == V3, V3DFILE_INFO);
		V3DTest::AssertOk(T2.item2 == V4, V3DFILE_INFO);
	}
	
	void V3DTupleTests::RunAllTests()
	{	
		TupleTest();
	}
}
