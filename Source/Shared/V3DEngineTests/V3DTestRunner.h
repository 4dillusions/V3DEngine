/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTest.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngineTests
{
	inline void RunAllTests()
	{
		V3DTest::AssertOk(false, V3DFILE_INFO);
		V3DTest::WriteStatistics();
	}
}
