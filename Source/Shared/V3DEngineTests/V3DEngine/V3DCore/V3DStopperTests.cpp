/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStopperTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DStopper.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DStopperTests::StopperTest()
	{
		V3DStopper timer;
		timer.Reset();

		long long time = 0;
		for (; ;)
		{
			time += timer.GetDeltaTimeMsec();

			if (time > 1)
				break;
		}

		V3DTest::AssertOk(time > 0, V3DFILE_INFO);
	}

	void V3DStopperTests::RunAllUnitTests()
	{
		StopperTest();
	}

	void V3DStopperTests::RegisterIntegrationTests()
	{
	}

	void V3DStopperTests::RegisterTimingTests()
	{
	}
}
