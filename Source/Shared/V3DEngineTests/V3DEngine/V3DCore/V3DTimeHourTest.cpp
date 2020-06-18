/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTimeHourTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DTimeHour.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DTimeHourTest::TimeHourTest()
	{
		const auto time1 = V3DTimeHour(-2, -10);
		const auto time2 = V3DTimeHour(100, 80);
		const auto time3 = V3DTimeHour(-70, 72);
		const auto time4 = V3DTimeHour(60, -81);

		V3DTest::AssertOk(time1 == V3DTimeHour(0, 0), V3DFILE_INFO);
		V3DTest::AssertOk(time2 == V3DTimeHour(59, 59), V3DFILE_INFO);
		V3DTest::AssertOk(time3 == V3DTimeHour(0, 59), V3DFILE_INFO);
		V3DTest::AssertOk(time4 == V3DTimeHour(59, 0), V3DFILE_INFO);
	}
	
	void V3DTimeHourTest::RunAllTests()
	{	
		TimeHourTest();
	}
}
