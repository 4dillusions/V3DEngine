/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDynamicArrayTests.h"

#include "V3DCollectionsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DDynamicArray.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngineTests/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DDynamicArrayTests::CtorDtorTest()
	{
		V3DDynamicArray<int> intdArray;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::dynamicArrayMemoryAllocCount, V3DFILE_INFO);
		intdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDynamicArray<V3DTestObjectA> staticObjdArray;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::dynamicArrayMemoryAllocCount, V3DFILE_INFO);
		staticObjdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDynamicArray<V3DTestObjectA*> dynamicObjdArray;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::dynamicArrayMemoryAllocCount, V3DFILE_INFO);
		dynamicObjdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::AddGetDataTest()
	{
		V3DDynamicArray<int> intdArray;
		intdArray.Add(10);
		intdArray.First();
		V3DTest::AssertOk(*intdArray.GetCurrent() == 10, V3DFILE_INFO);
		intdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDynamicArray<V3DTestObjectA> staticObjdArray;
		V3DTestObjectA sObj;
		sObj.SetId(20);
		staticObjdArray.Add(sObj);
		staticObjdArray.First();
		V3DTest::AssertOk(staticObjdArray.GetCurrent()->GetId() == 20, V3DFILE_INFO);
		staticObjdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDynamicArray<V3DTestObjectA*> dynamicObjdArray;
		V3DTestObjectA* dObj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		dObj->SetId(20);
		dynamicObjdArray.Add(dObj);
		dynamicObjdArray.First();
		V3DTest::AssertOk((*dynamicObjdArray.GetCurrent())->GetId() == 20, V3DFILE_INFO);
		V3DMemory::Delete(dObj);
		dynamicObjdArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::AddRemoveStaticTest()
	{
		V3DDynamicArray<int> dArray;

		dArray.Add(2);
		dArray.Add(7);
		dArray.Add(5);
		dArray.Add(6);
		dArray.Add(9);
		dArray.Add(11);
		dArray.Add(4);

		V3DTest::AssertOk(dArray.GetLength() == 7, V3DFILE_INFO);

		for (dArray.First(); dArray.IsDone(); dArray.Next())
			if (*dArray.GetCurrent() == 5)
				dArray.RemoveCurrent();

		int allNumbers = 0;
		for (dArray.First(); dArray.IsDone(); dArray.Next())
			allNumbers += *dArray.GetCurrent();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);

		dArray.RemoveAll();

		dArray.Add(4);
		dArray.Add(5);
		dArray.Add(6);

		V3DTest::AssertOk(dArray.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (dArray.First(); dArray.IsDone(); dArray.Next())
			allNumbers += *dArray.GetCurrent();

		V3DTest::AssertOk((allNumbers == (4 + 5 + 6)), V3DFILE_INFO);

		dArray.RemoveAll();
		dArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::AddRemoveDynamicTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		V3DDynamicArray<V3DTestObjectA*> dArray;

		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 2));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 7));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 9));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 4));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(dArray.GetLength() == 7, V3DFILE_INFO);

		for (dArray.First(); dArray.IsDone(); dArray.Next())
			if ((*dArray.GetCurrent())->GetId() == 5)
			{
				V3DMemory::Delete(*dArray.GetCurrent());
				dArray.RemoveCurrent();
			}

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 6, V3DFILE_INFO);
		V3DTest::AssertOk(dArray.GetLength() == 6, V3DFILE_INFO);

		auto allNumbers = 0;
		for (dArray.First(); dArray.IsDone(); dArray.Next())
			allNumbers += (*dArray.GetCurrent())->GetId();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);

		for (dArray.First(); dArray.IsDone(); dArray.Next())
			V3DMemory::Delete(*dArray.GetCurrent());

		dArray.RemoveAll();

		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 4));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		dArray.Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(dArray.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (dArray.First(); dArray.IsDone(); dArray.Next())
			allNumbers += (*dArray.GetCurrent())->GetId();

		V3DTest::AssertOk((allNumbers == (4 + 5 + 6)), V3DFILE_INFO);

		for (dArray.First(); dArray.IsDone(); dArray.Next())
			V3DMemory::Delete(*dArray.GetCurrent());

		dArray.RemoveAll();
		dArray.~V3DDynamicArray();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::RemoveAtTest()
	{
		V3DDynamicArray<int> dArray;

		dArray.Add(2);
		dArray.Add(7);
		dArray.Add(5);
		dArray.Add(6);
		dArray.Add(9);
		dArray.Add(11);
		dArray.Add(4);

		dArray.RemoveAt(8);
		dArray.RemoveAt(2);

		int allNumbers = 0;
		for (dArray.First(); dArray.IsDone(); dArray.Next())
			allNumbers += *dArray.GetCurrent();

		dArray.RemoveAll();
		dArray.~V3DDynamicArray();
		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::CopyReturnTest()
	{
		auto ObjReturnTest = []()
		{
			V3DDynamicArray<V3DString> result;

			V3DString temp;
			temp += "one";
			result.Add(temp);

			temp.Clear();
			temp += "two";
			result.Add(temp);

			return result;
		};

		V3DTest::AssertOk(*ObjReturnTest()[0] == V3DString("one") && *ObjReturnTest()[1] == V3DString("two"), V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDynamicArrayTests::DynamicArrayAddRemoveTimingTest()
	{
		static V3DDynamicArray<V3DTestObjectA*>* dArray;

		V3DTest::AddTimingTest("DynamicArrayAddRemoveTimingTest", V3DTimingTestData
			{
				[]()
				{
					dArray = V3DMemory::New<V3DDynamicArray<V3DTestObjectA*>>(V3DFILE_INFO);
				},true,0
			});

		V3DTest::AddTimingTest("DynamicArrayAddRemoveTimingTest", V3DTimingTestData
			{
				[]()
				{
					for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
						dArray->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

					for (dArray->First(); dArray->IsDone(); dArray->Next())
						V3DMemory::Delete(*dArray->GetCurrent());

					dArray->RemoveAll();
				},false,1
			});

		V3DTest::AddTimingTest("DynamicArrayAddRemoveTimingTest", V3DTimingTestData
			{
				[]()
				{
					V3DMemory::Delete(dArray);
				}, true, 2
			});
	}

	void V3DDynamicArrayTests::DynamicArrayIterateTimingTest()
	{
		static V3DDynamicArray<V3DTestObjectA*>* list;

		V3DTest::AddTimingTest("DynamicArrayIterateTimingTest", V3DTimingTestData
			{
				[]()
				{
					list = V3DMemory::New<V3DDynamicArray<V3DTestObjectA*>>(V3DFILE_INFO);

					for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
						list->Add(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));
				}, true, 0
			});

		V3DTest::AddTimingTest("DynamicArrayIterateTimingTest", V3DTimingTestData
			{
				[]()
				{
					for (list->First(); list->IsDone(); list->Next())
						(*list->GetCurrent())->SetId((*list->GetCurrent())->GetId() + 1);
				}, false, 1
			});

		V3DTest::AddTimingTest("DynamicArrayIterateTimingTest", V3DTimingTestData
			{
				[]()
				{
					for (list->First(); list->IsDone(); list->Next())
						V3DMemory::Delete(*list->GetCurrent());

					V3DMemory::Delete(list);
				}, true, 2
			});
	}

	void V3DDynamicArrayTests::RunAllTests()
	{
		CtorDtorTest();
		AddGetDataTest();
		AddRemoveStaticTest();
		AddRemoveDynamicTest();
		RemoveAtTest();
		CopyReturnTest();

		DynamicArrayAddRemoveTimingTest();
		DynamicArrayIterateTimingTest();
	}
}
