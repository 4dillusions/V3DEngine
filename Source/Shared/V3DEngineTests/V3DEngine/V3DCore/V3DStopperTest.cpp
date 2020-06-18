/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStopperTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DStopper.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DStopperTest::StopperTest()
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
	
	void V3DStopperTest::RunAllTests()
	{	
		StopperTest();
	}
}
