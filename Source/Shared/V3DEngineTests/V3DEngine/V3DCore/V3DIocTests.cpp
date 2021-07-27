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
	void V3DIocTests::StaticTest()
	{
		V3DIoc<V3DTestObjectA>::Get().SetId(12);
		V3DTest::AssertOk(V3DIoc<V3DTestObjectA>::Get().GetId() == 12, V3DFILE_INFO);
		V3DIoc<V3DTestObjectA>::Get().SetId(20);
		V3DTest::AssertOk(V3DIoc<V3DTestObjectA>::Get().GetId() == 20, V3DFILE_INFO);
	}
	
	void V3DIocTests::DynamicTest()
	{
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

		V3DIoc<V3DITestObject*>::DeleteInstance();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::IsExist() == false, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::Register<V3DTestObjectB>();
		V3DIoc<V3DITestObject*>::Create();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'B', V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::DeleteInstance();
		V3DIoc<V3DITestObject*>::Register<V3DTestObjectA>([]()
		{
			auto result = V3DMemory::New<V3DTestObjectB>(V3DFILE_INFO);
			result->SetId(44);

			return result;
		});
		V3DIoc<V3DITestObject*>::Create();
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetTypeCode() == 'B', V3DFILE_INFO);
		V3DTest::AssertOk(V3DIoc<V3DITestObject*>::Get()->GetId() == 44, V3DFILE_INFO);

		V3DIoc<V3DITestObject*>::DeleteInstance();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DIocTests::RunAllTests()
	{	
		StaticTest();
		DynamicTest();
	}
}
