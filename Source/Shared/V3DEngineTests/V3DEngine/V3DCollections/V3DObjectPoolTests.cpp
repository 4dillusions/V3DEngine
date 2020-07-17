/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DObjectPoolTests.h"

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DCollectionsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DObjectPool.h"
#include "V3DEngineTests/V3DTestObjectA.h"

#include <assert.h>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

using namespace std;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DObjectPoolTests::CtorDtorTest()
	{
		V3DObjectPool<V3DTestObjectA> intPool { V3DCollectionsTests::Size };
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::PoolMemoryAllocCount, V3DFILE_INFO);
		intPool.~V3DObjectPool();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DObjectPoolTests::AddRemoveTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::PoolMemoryAllocCount, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);

		for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
			;
		V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);

		int testObjectPoolCounter = 0;
		objectPool.Add();
		objectPool.Add();
		objectPool.Add();
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), testObjectPoolCounter++)
			;
		V3DTest::AssertOk(testObjectPoolCounter == 3, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == testObjectPoolCounter, V3DFILE_INFO);

		testObjectPoolCounter = 0;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), testObjectPoolCounter++)
			if (testObjectPoolCounter < 2)
				objectPool.RemoveCurrent();
			else
				break;

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 1, V3DFILE_INFO);

		testObjectPoolCounter = 0;
		objectPool.Add();
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), testObjectPoolCounter++)
			;
		V3DTest::AssertOk(testObjectPoolCounter == 2, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);

		for (objectPool.First(); objectPool.IsDone(); /*unreachable code: objectPool.Next()*/)
		{
			objectPool.RemoveCurrent();
			break;
		}
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 1, V3DFILE_INFO);
		
		objectPool.~V3DObjectPool();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveAllTest()
	{
		const auto ObjectPoolRemoveAllTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
			objectPool.RemoveAll();
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
			V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		const auto ObjectPoolRemoveAllCurrentsTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };

			for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
				objectPool.RemoveCurrent();

			V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllCurrentsTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveAllAndAddTest()
	{
		const auto ObjectPoolRemoveAllTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
			objectPool.RemoveAll();
			objectPool.Add();
			objectPool.Add();
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
			V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		const auto ObjectPoolRemoveAllCurrentsTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };

			for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
				objectPool.RemoveCurrent();

			objectPool.Add();
			objectPool.Add();
			V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllCurrentsTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveFirstWhileIterateTest()
	{
		V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
		for (int i = 0; i < V3DCollectionsTests::Size; i++)
			objectPool.Add();

		int index = 0;
		int killObjectsCounter = 2;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), index++)
		{
			objectPool.GetCurrent()->SetId(index);

			if (killObjectsCounter > 0)
			{
				killObjectsCounter--;
				objectPool.RemoveCurrent();
			}
		}

		int sum = 0;
		int sumId = 0;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
		{
			sum++;
			sumId += objectPool.GetCurrent()->GetId();
		}

		V3DTest::AssertOk(sum == 8, V3DFILE_INFO);
		V3DTest::AssertOk(sumId == 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveLastWhileIterateTest()
	{
		V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
		for (int i = 0; i < V3DCollectionsTests::Size; i++)
			objectPool.Add();

		int killObjectsCounter = 2;
		int index = 0;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), index++)
		{
			objectPool.GetCurrent()->SetId(index);

			if (index > 7 && killObjectsCounter > 0)
			{
				killObjectsCounter--;
				objectPool.RemoveCurrent();
			}
		}

		int sum = 0;
		int sumId = 0;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
		{
			sum++;
			sumId += objectPool.GetCurrent()->GetId();
		}

		V3DTest::AssertOk(sum == 8, V3DFILE_INFO);
		V3DTest::AssertOk(sumId == 1 + 2 + 3 + 4 + 5 + 6 + 7, V3DFILE_INFO);
	}
	
	void V3DObjectPoolTests::ObjectPoolAddRemoveTimingTest()
	{
		static V3DObjectPool<V3DTestObjectA>* objectPool;
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA>>(V3DFILE_INFO, V3DCollectionsTests::BigSize);
			}, true, 0
		});
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
					objectPool->Add();

				for (objectPool->First(); objectPool->IsDone(); objectPool->Next())
					objectPool->RemoveCurrent();
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				V3DMemory::Delete(objectPool);
			}, true, 2
		});
	}

	void V3DObjectPoolTests::ObjectPoolIterateTimingTest()
	{
		static V3DObjectPool<V3DTestObjectA>* objectPool;
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA>>(V3DFILE_INFO, V3DCollectionsTests::BigSize);

				for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
					objectPool->Add();

				assert(objectPool->GetLength() == V3DCollectionsTests::BigSize);

				int i = 0;
				for (objectPool->First(); objectPool->IsDone(); objectPool->Next(), i++)
					objectPool->GetCurrent()->SetId(objectPool->GetCurrent()->GetId() + 1);

				assert(i == V3DCollectionsTests::BigSize);
			}, true, 0
		});
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (objectPool->First(); objectPool->IsDone(); objectPool->Next())
					objectPool->GetCurrent()->SetId(objectPool->GetCurrent()->GetId() + 1);
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				V3DMemory::Delete(objectPool);
			}, true, 2
		});
	}

	void V3DObjectPoolTests::RunAllTests()
	{
		CtorDtorTest();
		AddRemoveTest();
		RemoveAllTest();
		RemoveAllAndAddTest();
		RemoveFirstWhileIterateTest();
		RemoveLastWhileIterateTest();

		ObjectPoolAddRemoveTimingTest();
		ObjectPoolIterateTimingTest();
	}
}
