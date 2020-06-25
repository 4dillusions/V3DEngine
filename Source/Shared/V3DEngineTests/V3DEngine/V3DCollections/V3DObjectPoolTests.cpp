﻿/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DObjectPoolTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DObjectPool.h"
#include "V3DEngineTests/V3DTestObjectA.h"

#include <string>
#include <vector>

#include "V3DCollectionsTests.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

using namespace std;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DObjectPoolTests::CtorDtorTest()
	{
		V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> intPool;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::poolMemoryAllocCount, V3DFILE_INFO);
		intPool.~V3DObjectPool();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DObjectPoolTests::AddRemoveTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::poolMemoryAllocCount, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);

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

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 1, V3DFILE_INFO);

		testObjectPoolCounter = 0;
		objectPool.Add();
		for (objectPool.First(); objectPool.IsDone(); objectPool.Next(), testObjectPoolCounter++)
			;
		V3DTest::AssertOk(testObjectPoolCounter == 2, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
		V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);

		for (objectPool.First(); objectPool.IsDone(); /*unreachable code: objectPool.Next()*/)
		{
			objectPool.RemoveCurrent();
			break;
		}
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
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
			V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;
			objectPool.RemoveAll();
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
			V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		const auto ObjectPoolRemoveAllCurrentsTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;

			for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
				objectPool.RemoveCurrent();

			V3DTest::AssertOk(objectPool.GetLength() == 0, V3DFILE_INFO);
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
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
			V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;
			objectPool.RemoveAll();
			objectPool.Add();
			objectPool.Add();
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
			V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		const auto ObjectPoolRemoveAllCurrentsTest = []()
		{
			V3DTestObjectA::SetReferenceCounter(0);
			V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;

			for (objectPool.First(); objectPool.IsDone(); objectPool.Next())
				objectPool.RemoveCurrent();

			objectPool.Add();
			objectPool.Add();
			V3DTest::AssertOk(objectPool.GetLength() == 2, V3DFILE_INFO);
			V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == V3DCollectionsTests::size, V3DFILE_INFO);
		};
		ObjectPoolRemoveAllCurrentsTest();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DObjectPoolTests::RemoveFirstWhileIterateTest()
	{
		V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;
		for (int i = 0; i < V3DCollectionsTests::size; i++)
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
		V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::size> objectPool;
		for (int i = 0; i < V3DCollectionsTests::size; i++)
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

	void V3DObjectPoolTests::StdVectorAddRemoveTimingTest()
	{
		static vector<V3DTestObjectA*>* stdList;
		
		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{	
				stdList = V3DMemory::New<vector<V3DTestObjectA*>>(V3DFILE_INFO);
			}, true, 0
		});
		
		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
					stdList->push_back(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));

				for (auto i = stdList->begin(); i != stdList->end(); ++i)
				{
					if (!(*i)->GetIsAlive())
					{
						V3DMemory::Delete(*i);

						if (i == --stdList->end())
						{
							stdList->erase(i);
							break;
						}

						i = stdList->erase(i);
					}
				}
			}, false, 1
		});

		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (auto& i : *stdList)
					V3DMemory::Delete(i);

				V3DMemory::Delete(stdList);
			}, true, 2
		});
	}
	
	void V3DObjectPoolTests::StdVectorIterateTimingTest()
	{
		static vector<V3DTestObjectA*>* stdList;
		
		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				stdList = V3DMemory::New<vector<V3DTestObjectA*>>(V3DFILE_INFO);

				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
					stdList->push_back(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));
			}, true, 0
		});
		
		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (auto i = stdList->begin(); i != stdList->end(); ++i)
				{
					if (!(*i)->GetIsAlive())
					{
						V3DMemory::Delete(*i);

						if (i == --stdList->end())
						{
							stdList->erase(i);
							break;
						}

						i = stdList->erase(i);
					}

					(*i)->SetId((*i)->GetId() + 1);
				}
			}, false, 1
		});

		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (auto& i : *stdList)
					V3DMemory::Delete(i);

				V3DMemory::Delete(stdList);
			}, true, 2
		});
	}
	
	void V3DObjectPoolTests::ObjectPoolAddRemoveTimingTest()
	{
		static V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::bigSize>* objectPool;
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::bigSize>>(V3DFILE_INFO);
			}, true, 0
		});
		
		V3DTest::AddTimingTest("V3DObjectPoolAddRemoveTimingTest", V3DTimingTestData
		{
			[]()
			{
				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
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
		static V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::bigSize>* objectPool;
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest", V3DTimingTestData
		{
			[]()
			{
				objectPool = V3DMemory::New<V3DObjectPool<V3DTestObjectA, V3DCollectionsTests::bigSize>>(V3DFILE_INFO);

				for (int i = 0; i < V3DCollectionsTests::bigSize; i++)
					objectPool->Add();
			}, true, 0
		});
		
		V3DTest::AddTimingTest("V3DObjectPoolIterateTimingTest1", V3DTimingTestData
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

		StdVectorAddRemoveTimingTest();
		StdVectorIterateTimingTest();
		ObjectPoolAddRemoveTimingTest();
		ObjectPoolIterateTimingTest();
	}
}
