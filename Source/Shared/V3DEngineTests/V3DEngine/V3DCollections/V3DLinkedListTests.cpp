/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DLinkedListTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DLinkedList.h"
#include "V3DEngineTests/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

using namespace std;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DLinkedListTests::CtorDtorTest()
	{
		/*V3DObjectPool<int, size> intPool;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == poolHeadTailCount + size * 2, V3DFILE_INFO);
		intPool.~V3DObjectPool();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);*/

		V3DLinkedList<int> intList;
		intList.Add(13);

		V3DLinkedList<V3DTestObjectA> staticObjList;
		const V3DTestObjectA sObj;
		staticObjList.Add(sObj);
		
		auto dobj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		dynamicObjList.Add(dobj);
		
		V3DTest::AssertOk(false, V3DFILE_INFO);

		/*V3DLinkedList<int> intList;
		V3DLinkedList<V3DTestObjectA> staticObjList;
		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		const auto StringTestCtorOperators = [&]()
		{
			intList.Add(13);
			
			V3DTestObjectA sObj;
			staticObjList.Add(sObj);

			auto obj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
			V3DLinkedList<V3DTestObjectA*> dynamicObjList;
			dynamicObjList.Add(obj);
		};*/

		/*auto num = intList.GetData();
		auto sobj = staticObjList.GetData();
		auto dobj = dynamicObjList.GetData();*/

		int x = 0;
	}

	void V3DLinkedListTests::RunAllTests()
	{
		CtorDtorTest();
		//TODO
	}
}
