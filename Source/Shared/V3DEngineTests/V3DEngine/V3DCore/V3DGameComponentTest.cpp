/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DGameComponentTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngineTests/V3DTestGameComponent.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DGameComponentTest::CtorsOperatorsTest()
	{
		const V3DTestGameComponent Comp, Comp2;
		V3DTest::AssertOk(Comp.GetId() != Comp2.GetId(), V3DFILE_INFO);
		//V3DTest::AssertOk(Comp < Comp2, V3DFILE_INFO);
		V3DTest::AssertOk(Comp != Comp2, V3DFILE_INFO);

		const V3DTestGameComponent Comp3{"comp3"}, Comp4{"comp3"};
		V3DTest::AssertOk(Comp3 != Comp4, V3DFILE_INFO);
		V3DTest::AssertOk(V3DString(Comp3.GetName()) == V3DString(Comp4.GetName()), V3DFILE_INFO);
	}
	
	void V3DGameComponentTest::RunAllTests()
	{
		CtorsOperatorsTest();
	}
}
