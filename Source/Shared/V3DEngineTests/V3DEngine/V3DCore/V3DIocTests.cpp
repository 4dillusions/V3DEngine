/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIocTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectB.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DIocTests::DynamicTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTest::AssertOk(V3DIoc<V3DITestObject>::IsSingletonExist() == false, V3DFILE_INFO);

		V3DIoc<V3DITestObject>::RegisterAndCreateSingleton<V3DTestObjectA>();
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetTypeCode() == 'A', V3DFILE_INFO);

		V3DIoc<V3DITestObject>::GetSingleton()->SetId(20);
		V3DIoc<V3DITestObject>::RegisterTransient<V3DTestObjectB>(); //no operation if instance not nullptr
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::CreateTransient() == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetId() == 20, V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetTypeCode() == 'A', V3DFILE_INFO);

		V3DIoc<V3DITestObject>::Remove();
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::IsSingletonExist() == false, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DIoc<V3DITestObject>::RegisterAndCreateSingleton<V3DTestObjectB>();
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetTypeCode() == 'B', V3DFILE_INFO);

		V3DIoc<V3DITestObject>::Remove();
		V3DIoc<V3DITestObject>::RegisterAndCreateSingleton<V3DTestObjectA>(V3DFunc<V3DITestObject*>([]
		{
			const auto result = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
			result->SetId(44);

			return result;
		}));
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetTypeCode() == 'B', V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton()->GetId() == 44, V3DFILE_INFO);

		V3DIoc<V3DITestObject>::Remove();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		int id = 0;
		V3DIoc<V3DITestObject>::RegisterTransient<V3DTestObjectA>(V3DFunc<V3DITestObject*>(([&id]()
		{
			const auto result = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
			result->SetId(id++);

			return result;
		})));
		V3DTest::AssertOk(V3DIoc<V3DITestObject>::GetSingleton() == nullptr, V3DFILE_INFO);

		auto objB1 = V3DIoc<V3DITestObject>::CreateTransient();
		auto objB2 = V3DIoc<V3DITestObject>::CreateTransient();

		V3DTest::AssertOk(objB1->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(objB2->GetId() == 1, V3DFILE_INFO);

		V3DMemory::Delete(objB1);
		V3DMemory::Delete(objB2);

		V3DIoc<V3DITestObject>::Remove();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DIocTests::RunAllTests()
	{	
		DynamicTest();
	}
}
