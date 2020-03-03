/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTypesTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DTypes.h"

namespace V3D::V3DEngineTests::V3DEngine
{
	void V3DTypesTests::RunAllTests()
	{
		V3DTest::AssertOk(sizeof(Bool) == 1, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(Byte) == 1, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(Char) == 1, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(Double) == 8, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(Float) == 4, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(Int) == 4, V3DFILE_INFO);
		V3DTest::AssertOk(sizeof(UInt) == 4, V3DFILE_INFO);
	}
}
