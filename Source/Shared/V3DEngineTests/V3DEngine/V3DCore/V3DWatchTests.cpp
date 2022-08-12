/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DWatchTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DTimeHour.h"
#include "V3DEngine/V3DCore/V3DWatchHour.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DWatchTests::WatchTest()
	{
		const auto MinTime = V3DTimeHour(0, 0);
		const auto MaxTime = V3DTimeHour(2, 0);
		V3DWatchHour watch(V3DTimeHour(1, 0), MinTime, MaxTime);

		bool isMaxTime = false;
		watch.SetMaxTimeAction(V3DAction([&isMaxTime]() { isMaxTime = true; }));
		for (int i = 0; i < 60; i++)
			watch.IncreaseSeconds();

		V3DTest::AssertOk(isMaxTime, V3DFILE_INFO);
		V3DTest::AssertOk(watch.GetTime() == MaxTime, V3DFILE_INFO);

		bool isMinTime = false;
		watch.SetMinTimeAction(V3DAction([&isMinTime]() { isMinTime = true; }));
		for (int i = 0; i < 120; i++)
			watch.DecreaseSeconds();

		V3DTest::AssertOk(isMinTime, V3DFILE_INFO);
		V3DTest::AssertOk(watch.GetTime() == MinTime, V3DFILE_INFO);

		watch.SetToZero();
		watch.DecreaseSeconds();
		V3DTest::AssertOk(watch.GetTime() == V3DTimeHour(0, 59), V3DFILE_INFO);

		watch.SetToZero();
		for (int i = 0; i < 60 * 61; i++)
			watch.IncreaseSeconds();

		V3DTest::AssertOk(watch.GetTime() == V3DTimeHour(59, 0), V3DFILE_INFO);
	}

	void V3DWatchTests::RunAllUnitTests()
	{
		WatchTest();
	}

	void V3DWatchTests::RegisterIntegrationTests()
	{
	}

	void V3DWatchTests::RegisterTimingTests()
	{
	}
}
