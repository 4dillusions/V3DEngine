﻿/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DObjectPoolTests.h"
#include "V3DCollectionsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DObjectPool.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

#include <cassert>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DObjectPoolTests::CtorDtorTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DObjectPool<V3DTestObjectA> intPool { V3DCollectionsTests::Size };
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + V3DCollectionsTests::PoolMemoryAllocCount, V3DFILE_INFO);
		intPool.~V3DObjectPool();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::AddRemoveNewPlacementObjectTest()
	{
		//used objects
		V3DObjectPool<V3DTestObjectA> objectPool{ 2 };
		objectPool.Add()->SetId(10);
		objectPool.Add()->SetId(12);

		objectPool.RemoveAll();
		V3DTest::AssertOk(objectPool.Add()->GetId() == 12, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.Add()->GetId() == 10, V3DFILE_INFO);

		//placement new objects
		V3DObjectPool<V3DTestObjectA> placePool{ 2 };
		const auto place1 = placePool.Add();
		const auto place2 = placePool.Add();
		place1->SetId(10);
		place2->SetId(12);

		placePool.RemoveAll();
		const auto placement1 = placePool.Add(true);
		const auto placement2 = placePool.Add(true);
		V3DTest::AssertOk(placement1->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(placement2->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(place1 == placement2, V3DFILE_INFO);
		V3DTest::AssertOk(place2 == placement1, V3DFILE_INFO);
	}
	
	void V3DObjectPoolTests::AddRemoveUsedObjectTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTestObjectA::SetReferenceCounter(0);
		V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + V3DCollectionsTests::PoolMemoryAllocCount, V3DFILE_INFO);
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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveAllTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto ObjectPoolRemoveAllTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA> objectPool { V3DCollectionsTests::Size };
			objectPool.RemoveAll();
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::Size, V3DFILE_INFO);
			V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		constexpr auto ObjectPoolRemoveAllCurrentsTest = []()
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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveAllAndAddTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr auto ObjectPoolRemoveAllTest = []()
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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);

		constexpr auto ObjectPoolRemoveAllCurrentsTest = []()
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
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
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

	void V3DObjectPoolTests::RemoveLastThreeWhileIterateTest()
	{
		constexpr int PoolLittleSize = 5;
		V3DObjectPool<V3DTestObjectA> objectPool{ PoolLittleSize };
		for (int i = 0; i < PoolLittleSize; i++)
		{
			const auto obj = objectPool.Add();
			obj->SetId(i + 1);
			obj->SetIsAlive(i < 2);
		}

		for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
		{
			if (!objectPool.GetCurrent()->GetIsAlive())
				objectPool.RemoveCurrent();
		}

		int objectIdSum = 0;
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
			objectIdSum += objectPool.GetCurrent()->GetId();

		V3DTest::AssertOk(objectIdSum == PoolLittleSize - 2, V3DFILE_INFO);
	}
	
	void V3DObjectPoolTests::ObjectPoolAddRemoveTimingTest()
	{
		static V3DObjectPool<V3DTestObjectA>* objectPool;
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTestTimingData
		{
			[]()
			{
				objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA>>(V3DFILE_INFO, V3DCollectionsTests::BigSize);
			}, true, 0
		});
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTestTimingData
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
					objectPool->Add();

				for (objectPool->First(); objectPool->IsDone(); objectPool->Next())
					objectPool->RemoveCurrent();
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTestTimingData
		{
			[]()
			{
				V3DMemory::Delete(objectPool);
			}, true, 2
		});
	}

	void V3DObjectPoolTests::ObjectPoolAddRemovePlacementNewTimingTest()
	{
		static V3DObjectPool<V3DTestObjectA>* objectPool;

		V3DTest::AddTimingTest("V3DObjectPoolAddRemovePlacementNewTimingTest", V3DTestTimingData
			{
				[]()
				{
					objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA>>(V3DFILE_INFO, V3DCollectionsTests::BigSize);
				}, true, 0
			});

		V3DTest::AddTimingTest("V3DObjectPoolAddRemovePlacementNewTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
						objectPool->Add(true);

					for (objectPool->First(); objectPool->IsDone(); objectPool->Next())
						objectPool->RemoveCurrent();
				}, false, 1
			});

		V3DTest::AddTimingTest("V3DObjectPoolAddRemovePlacementNewTimingTest", V3DTestTimingData
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
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTestTimingData
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
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTestTimingData
		{
			[]()
			{
				for (objectPool->First(); objectPool->IsDone(); objectPool->Next())
					objectPool->GetCurrent()->SetId(objectPool->GetCurrent()->GetId() + 1);
			}, false, 1
		});

		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTestTimingData
		{
			[]()
			{
				V3DMemory::Delete(objectPool);
			}, true, 2
		});
	}

	void V3DObjectPoolTests::RunAllUnitTests()
	{
		CtorDtorTest();
		AddRemoveNewPlacementObjectTest();
		AddRemoveUsedObjectTest();
		RemoveAllTest();
		RemoveAllAndAddTest();
		RemoveFirstWhileIterateTest();
		RemoveLastWhileIterateTest();
		RemoveLastThreeWhileIterateTest();
	}

	void V3DObjectPoolTests::RegisterIntegrationTests()
	{
	}

	void V3DObjectPoolTests::RegisterTimingTests()
	{
		ObjectPoolAddRemoveTimingTest();
		ObjectPoolAddRemovePlacementNewTimingTest();
		ObjectPoolIterateTimingTest();
	}
}
