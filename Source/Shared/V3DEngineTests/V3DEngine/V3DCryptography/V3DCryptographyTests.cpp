/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCryptographyTests.h"

#include "V3DCryptographyHelperTests.h"
#include "V3DCryptographyMethodTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	void V3DCryptographyTests::RunAllTests()
	{	
		V3DCryptographyHelperTests::RunAllTests();
		V3DCryptographyMethodTests::RunAllTests();
	}
}
