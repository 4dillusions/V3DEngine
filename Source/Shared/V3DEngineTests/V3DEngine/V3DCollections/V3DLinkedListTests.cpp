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
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

#include "V3DCollectionsTests.h"

#include <cassert>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DLinkedListTests::CtorDtorTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTestObjectA::SetReferenceCounter(0);
		V3DLinkedList<V3DTestObjectA> staticObjLinkedList;
		staticObjLinkedList.Add(V3DTestObjectA());
		staticObjLinkedList.Add(V3DTestObjectA());
		staticObjLinkedList.Add(V3DTestObjectA());
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == staticObjLinkedList.GetLength() + 2, V3DFILE_INFO); //+2: head, tail
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3 + 2, V3DFILE_INFO); //+2: head, tail
		staticObjLinkedList.~V3DLinkedList();
		V3DTest::AssertOk(staticObjLinkedList.GetLength() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);

		V3DLinkedList<int> intList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + V3DCollectionsTests::ListMemoryAllocCount, V3DFILE_INFO);
		intList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA> staticObjList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + V3DCollectionsTests::ListMemoryAllocCount, V3DFILE_INFO);
		staticObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + V3DCollectionsTests::ListMemoryAllocCount, V3DFILE_INFO);
		dynamicObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddGetDataTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DLinkedList<int> intList;
		intList.Add(10);
		intList.First();
		V3DTest::AssertOk(*intList.GetCurrent() == 10, V3DFILE_INFO);
		intList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA> staticObjList;
		V3DTestObjectA sObj;
		sObj.SetId(20);
		staticObjList.Add(sObj);
		staticObjList.First();
		V3DTest::AssertOk(staticObjList.GetCurrent()->GetId() == 20, V3DFILE_INFO);
		staticObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		auto dObj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		dObj->SetId(20);
		dynamicObjList.Add(dObj);
		dynamicObjList.First();
		V3DTest::AssertOk((*dynamicObjList.GetCurrent())->GetId() == 20, V3DFILE_INFO);
		V3DMemory::Delete(dObj);
		dynamicObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddRemoveStaticTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DLinkedList<int> list;

		list.Add(2);
		list.Add(7);
		list.Add(5);
		list.Add(6);
		list.Add(9);
		list.Add(11);
		list.Add(4);

		V3DTest::AssertOk(list.GetLength() == 7, V3DFILE_INFO);

		for (list.First(); list.IsDone(); list.Next())
			if (*list.GetCurrent() == 5)
				list.RemoveCurrent();

		int allNumbers = 0;
		for (list.First(); list.IsDone(); list.Next())
			allNumbers += *list.GetCurrent();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);

		list.RemoveAll();

		list.Add(4);
		list.Add(5);
		list.Add(6);
		
		V3DTest::AssertOk(list.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (list.First(); list.IsDone(); list.Next())
			allNumbers += *list.GetCurrent();

		V3DTest::AssertOk((allNumbers == (4 + 5 + 6)), V3DFILE_INFO);

		list.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddRemoveDynamicTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTestObjectA::SetReferenceCounter(0);
		V3DLinkedList<V3DTestObjectA*> list;

		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 2));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 7));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 9));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 4));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(list.GetLength() == 7, V3DFILE_INFO);
		
		for (list.First(); list.IsDone(); list.Next())
			if ((*list.GetCurrent())->GetId() == 5)
			{
				V3DMemory::Delete(*list.GetCurrent());
				list.RemoveCurrent();
			}

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 6, V3DFILE_INFO);
		V3DTest::AssertOk(list.GetLength() == 6, V3DFILE_INFO);
		
		auto allNumbers = 0;
		for (list.First(); list.IsDone(); list.Next())
			allNumbers += (*list.GetCurrent())->GetId();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);

		for (list.First(); list.IsDone(); list.Next())
			V3DMemory::Delete(*list.GetCurrent());

		list.RemoveAll();

		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 4));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		list.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(list.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (list.First(); list.IsDone(); list.Next())
			allNumbers += (*list.GetCurrent())->GetId();

		V3DTest::AssertOk((allNumbers == (4 + 5 + 6)), V3DFILE_INFO);

		for (list.First(); list.IsDone(); list.Next())
			V3DMemory::Delete(*list.GetCurrent());

		list.~V3DLinkedList();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DLinkedListTests::RemoveLastThreeWhileIterateTest()
	{
		constexpr int ListLittleSize = 5;
		V3DLinkedList<V3DTestObjectA*> list;

		for (int i = 0; i < ListLittleSize; i++)
		{
			auto item = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, i + 1);
			item->SetIsAlive(i < 2);
			list.Add(item);
		}

		for (list.First(); list.IsDone(); list.Next())
			if (!(*list.GetCurrent())->GetIsAlive())
			{
				V3DMemory::Delete(*list.GetCurrent());
				list.RemoveCurrent();
			}

		int objectIdSum = 0;
		for (list.First(); list.IsDone(); list.Next())
			objectIdSum += (*list.GetCurrent())->GetId();

		V3DTest::AssertOk(objectIdSum == ListLittleSize - 2, V3DFILE_INFO);

		for (list.First(); list.IsDone(); list.Next())
			V3DMemory::Delete(*list.GetCurrent());
	}

	void V3DLinkedListTests::LinkedListAddRemoveTimingTest()
	{
		static V3DLinkedList<V3DTestObjectA*>* list;

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTestTimingData
		{
			[]()
			{
				list = V3DMemory::New<V3DLinkedList<V3DTestObjectA*>>(V3DFILE_INFO);
			},true,0
		});

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTestTimingData 
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
					list->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

				for (list->First(); list->IsDone(); list->Next())
					V3DMemory::Delete(*list->GetCurrent());

				list->RemoveAll();
			},false,1
		});

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTestTimingData
		{
			[]()
			{
				V3DMemory::Delete(list);
			}, true, 2
		});
	}

	void V3DLinkedListTests::LinkedListIterateTimingTest()
	{
		static V3DLinkedList<V3DTestObjectA*>* list;
		
		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTestTimingData
		{
			[]()
			{
				list = V3DMemory::New<V3DLinkedList<V3DTestObjectA*>>(V3DFILE_INFO);

				for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
					list->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

				assert(list->GetLength() == V3DCollectionsTests::BigSize);

				int i = 0;
				for (list->First(); list->IsDone(); list->Next(), i++)
					(*list->GetCurrent())->SetId((*list->GetCurrent())->GetId() + 1);

				assert(i == V3DCollectionsTests::BigSize);
			}, true, 0
		});

		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTestTimingData
		{
			[]()
			{
				for (list->First(); list->IsDone(); list->Next())
					(*list->GetCurrent())->SetId((*list->GetCurrent())->GetId() + 1);
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTestTimingData
		{
			[]()
			{
				for (list->First(); list->IsDone(); list->Next())
					V3DMemory::Delete(*list->GetCurrent());

				V3DMemory::Delete(list);
			}, true, 2
		});
	}

	void V3DLinkedListTests::RunAllUnitTests()
	{
		CtorDtorTest();
		AddGetDataTest();
		AddRemoveStaticTest();
		AddRemoveDynamicTest();
		RemoveLastThreeWhileIterateTest();
	}

	void V3DLinkedListTests::RegisterIntegrationTests()
	{
	}

	void V3DLinkedListTests::RegisterTimingTests()
	{
		LinkedListAddRemoveTimingTest();
		LinkedListIterateTimingTest();
	}
}
