/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#define UNITTEST

#include "V3DCoreTests.h"
#include "V3DEngineTests/V3DTest.h"

#include "V3DEngine/V3DCore/V3DTuple.h"
#include "V3DEngine/V3DCore/V3DStopper.h"
#include "V3DEngine/V3DCore/V3DWatch.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DCore/V3DDateTime.h"

#include "V3DEngineTests/V3DTestObjectA.h"
#include "V3DEngineTests/V3DTestObjectB.h"
#include "V3DStringTest.h"

using namespace std;

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DCoreTests::V3DTupleTest()
	{
		const int v1 = 22;
		const float v2 = 3.14f;
		const auto TupleTest1 = [&](V3DTuple2<int, float>& t)
		{
			t.item1 = v1;
			t.item2 = v2;
		};

		V3DTuple2<int, float> t1(1, 2);
		TupleTest1(t1);
		V3DTest::AssertOk(t1.item1 == v1, V3DFILE_INFO);
		V3DTest::AssertOk(t1.item2 == v2, V3DFILE_INFO);

		const int v3 = 12;
		const int v4 = 34;
		const auto t2 = V3DTuple::Create(v3, v4);
		V3DTest::AssertOk(t2.item1 == v3, V3DFILE_INFO);
		V3DTest::AssertOk(t2.item2 == v4, V3DFILE_INFO);
	}

	void V3DCoreTests::V3DStopperTest()
	{
		V3DStopper timer;
		timer.Reset();

		long long time = 0;
		for (; ;)
		{
			time += timer.DeltaTime();

			if (time > 1)
				break;
		}

		V3DTest::AssertOk(time > 0, V3DFILE_INFO);
	}

	void V3DCoreTests::V3DWatchTest()
	{
		bool isAlarm = false;
		const auto OnAlarm = [&isAlarm]() { isAlarm = true; };

		V3DWatch watch(V3DTime(1, 0), V3DTime(0, 0), V3DTime(2, 0));
		watch.SetAlarmEvent(OnAlarm);

		for (int i = 0; i < 60; i++, watch++)
			;

		V3DTest::AssertOk(isAlarm, V3DFILE_INFO);
	}

	void V3DCoreTests::V3DMemoryTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		int* x = V3DMemory::New<int>(V3DFILE_INFO, 0);
		int* y = V3DMemory::NewArray<int>(V3DFILE_INFO, 10);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 2, V3DFILE_INFO);

		V3DMemory::Delete(x);
		V3DMemory::DeleteArray(y);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(x == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(y == nullptr, V3DFILE_INFO);
	}

	void V3DCoreTests::V3DIocTest()
	{
		//static Ioc test
		V3DIoc<V3DTestObjectA>::Get().SetId(12);
		V3DTest::AssertOk(V3DIoc<V3DTestObjectA>::Get().GetId() == 12, V3DFILE_INFO);
		V3DIoc<V3DTestObjectA>::Get().SetId(20);
		V3DTest::AssertOk(V3DIoc<V3DTestObjectA>::Get().GetId() == 20, V3DFILE_INFO);

		//dynamic Ioc test
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::IsExist() == false, V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Register<V3DTestObjectA>();
		V3DIoc<V3DITestObject*>::Create();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'A', V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Get()->SetId(20);
		V3DIoc<V3DITestObject*>::Register<V3DTestObjectB>(); //no operation if instance not nullptr
		V3DIoc<V3DITestObject*>::Create(); //no operation if instance not nullptr
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetId() == 20, V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'A', V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Release();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::IsExist() == false, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Register<V3DTestObjectB>();
		V3DIoc<V3DITestObject*>::Create();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'B', V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Release();
		V3DIoc<V3DITestObject*>::Register<V3DTestObjectA>([]()
		{
			auto result = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
			result->SetId(44);

			return result;
		});
		V3DIoc<V3DITestObject*>::Create();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'B', V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetId() == 44, V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Release();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DCoreTests::V3DStringTest()
	{		
		V3DStringTest::RunAllTests();
	}

	void V3DCoreTests::V3DDateTimeTest()
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

	void V3DCoreTests::RunAllTests()
	{
		V3DTupleTest();
		V3DStopperTest();
		V3DWatchTest();
		V3DMemoryTest();
		V3DIocTest();
		V3DStringTest();
		V3DDateTimeTest();
	}
}
