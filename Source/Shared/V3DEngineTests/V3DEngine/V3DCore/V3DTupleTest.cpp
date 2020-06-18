/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTupleTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DTuple.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DTupleTest::TupleTest()
	{
		const int v1 = 22;
		const float v2 = 3.14f;
		const auto TupleTest1 = [&](V3DTuple2<int, float>& t)
		{
			t.item1 = v1;
			t.item2 = v2;
		};

		V3DTuple2<int, float> t1(1, 2);
		TupleTest1(t1);
		V3DTest::AssertOk(t1.item1 == v1, V3DFILE_INFO);
		V3DTest::AssertOk(t1.item2 == v2, V3DFILE_INFO);

		const int v3 = 12;
		const int v4 = 34;
		const auto t2 = V3DTuple::Create(v3, v4);
		V3DTest::AssertOk(t2.item1 == v3, V3DFILE_INFO);
		V3DTest::AssertOk(t2.item2 == v4, V3DFILE_INFO);
	}
	
	void V3DTupleTest::RunAllTests()
	{	
		TupleTest();
	}
}
