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

#include "V3DCollectionsTests.h"

#include <assert.h>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

using namespace std;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DLinkedListTests::CtorDtorTest()
	{
		V3DLinkedList<int> intList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::listMemoryAllocCount, V3DFILE_INFO);
		intList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA> staticObjList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::listMemoryAllocCount, V3DFILE_INFO);
		staticObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::listMemoryAllocCount, V3DFILE_INFO);
		dynamicObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddGetDataTest()
	{
		V3DLinkedList<int> intList;
		intList.Add(10);
		intList.First();
		V3DTest::AssertOk(*intList.GetCurrent() == 10, V3DFILE_INFO);
		intList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA> staticObjList;
		V3DTestObjectA sObj;
		sObj.SetId(20);
		staticObjList.Add(sObj);
		staticObjList.First();
		V3DTest::AssertOk(staticObjList.GetCurrent()->GetId() == 20, V3DFILE_INFO);
		staticObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DLinkedList<V3DTestObjectA*> dynamicObjList;
		V3DTestObjectA* dObj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		dObj->SetId(20);
		dynamicObjList.Add(dObj);
		dynamicObjList.First();
		V3DTest::AssertOk((*dynamicObjList.GetCurrent())->GetId() == 20, V3DFILE_INFO);
		V3DMemory::Delete(dObj);
		dynamicObjList.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddRemoveStaticTest()
	{
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

		list.RemoveAll();
		list.~V3DLinkedList();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DLinkedListTests::AddRemoveDynamicTest()
	{
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

		list.RemoveAll();
		list.~V3DLinkedList();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DLinkedListTests::LinkedListAddRemoveTimingTest()
	{
		static V3DLinkedList<V3DTestObjectA*>* list;

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				list = V3DMemory::New<V3DLinkedList<V3DTestObjectA*>>(V3DFILE_INFO);
			},true,0
		});

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTimingTestData 
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
					list->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

				for (list->First(); list->IsDone(); list->Next())
					V3DMemory::Delete(*list->GetCurrent());

				list->RemoveAll();
			},false,1
		});

		V3DTest::AddTimingTest("V3DLinkedListAddRemoveTimingTest", V3DTimingTestData
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
		
		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				list = V3DMemory::New<V3DLinkedList<V3DTestObjectA*>>(V3DFILE_INFO);

				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
					list->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

				assert(list->GetLength() == V3DCollectionsTests::bigSize);

				int i = 0;
				for (list->First(); list->IsDone(); list->Next(), i++)
					(*list->GetCurrent())->SetId((*list->GetCurrent())->GetId() + 1);

				assert(i == V3DCollectionsTests::bigSize);
			}, true, 0
		});

		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (list->First(); list->IsDone(); list->Next())
					(*list->GetCurrent())->SetId((*list->GetCurrent())->GetId() + 1);
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DLinkedListIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (list->First(); list->IsDone(); list->Next())
					V3DMemory::Delete(*list->GetCurrent());

				V3DMemory::Delete(list);
			}, true, 2
		});
	}
	
	void V3DLinkedListTests::RunAllTests()
	{
		CtorDtorTest();
		AddGetDataTest();
		AddRemoveStaticTest();
		AddRemoveDynamicTest();

		LinkedListAddRemoveTimingTest();
		LinkedListIterateTimingTest();
	}
}
