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
#include "V3DQueueTests.h"
#include "V3DStackTests.h"

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DCollectionsTests::RunAllUnitTests()
	{
		V3DObjectPoolTests::RunAllUnitTests();
		V3DLinkedListTests::RunAllUnitTests();
		V3DDynamicArrayTests::RunAllUnitTests();
		V3DDecimalTreeTests::RunAllUnitTests();
		V3DQueueTests::RunAllUnitTests();
		V3DStackTests::RunAllUnitTests();
		StdTests::RunAllUnitTests();
	}

	void V3DCollectionsTests::RegisterIntegrationTests()
	{
		V3DObjectPoolTests::RegisterIntegrationTests();
		V3DLinkedListTests::RegisterIntegrationTests();
		V3DDynamicArrayTests::RegisterIntegrationTests();
		V3DDecimalTreeTests::RegisterIntegrationTests();
		V3DQueueTests::RegisterIntegrationTests();
		V3DStackTests::RegisterIntegrationTests();
		StdTests::RegisterIntegrationTests();
	}

	void V3DCollectionsTests::RegisterTimingTests()
	{
		V3DObjectPoolTests::RegisterTimingTests();
		V3DLinkedListTests::RegisterTimingTests();
		V3DDynamicArrayTests::RegisterTimingTests();
		V3DDecimalTreeTests::RegisterTimingTests();
		V3DQueueTests::RegisterTimingTests();
		V3DStackTests::RegisterTimingTests();
		StdTests::RegisterTimingTests();
	}
}
