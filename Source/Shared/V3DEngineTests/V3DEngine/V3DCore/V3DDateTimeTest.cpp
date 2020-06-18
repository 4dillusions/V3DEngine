/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDateTimeTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DDateTime.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DDateTimeTest::DateTimeTest()
	{
		const auto now = V3DDateTime::GetNow();

		V3DTest::AssertOk(now->year > 1900, V3DFILE_INFO);
		V3DTest::AssertOk(now->year < 2100, V3DFILE_INFO);
		V3DTest::AssertOk(now->month > 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->month < 13, V3DFILE_INFO);
		V3DTest::AssertOk(now->day > 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->day < 32, V3DFILE_INFO);
		V3DTest::AssertOk(now->hour >= 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->hour < 25, V3DFILE_INFO);
		V3DTest::AssertOk(now->min >= 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->min < 60, V3DFILE_INFO);
		V3DTest::AssertOk(now->sec >= 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->sec < 60, V3DFILE_INFO);
		V3DTest::AssertOk(now->millisec >= 0, V3DFILE_INFO);
		V3DTest::AssertOk(now->millisec < 1000, V3DFILE_INFO);

		V3DTimeSpan nowTest;  // NOLINT
		nowTest.year = 2014;
		nowTest.month = 9;
		nowTest.day = 8;
		nowTest.hour = 17;
		nowTest.min = 51;
		nowTest.sec = 4;
		nowTest.millisec = 777;

		V3DTest::AssertOk(V3DDateTime::GetTimeStamp(&nowTest) == V3DString("[8.9.2014 17:51:4] "), V3DFILE_INFO);
		V3DTest::AssertOk(V3DDateTime::GetSqlTimeStamp(&nowTest) == V3DString("2014-9-8 17:51:4.777"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DDateTime::GetSQLTimeStampNumbers(&nowTest) == V3DString("20149817514777"), V3DFILE_INFO);
	}
	
	void V3DDateTimeTest::RunAllTests()
	{	
		DateTimeTest();
	}
}
