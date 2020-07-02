/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCollectionsTests.h"

#include "V3DObjectPoolTests.h"
#include "V3DLinkedListTests.h"
#include "V3DDynamicArrayTests.h"
#include "V3DDecimalTreeTests.h"
#include "StdTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DCollectionsTests::RunAllTests()
	{
		V3DObjectPoolTests::RunAllTests();
		V3DLinkedListTests::RunAllTests();
		V3DDynamicArrayTests::RunAllTests();
		V3DDecimalTreeTests::RunAllTests();
		StdTests::RunAllTests();
	}
}
