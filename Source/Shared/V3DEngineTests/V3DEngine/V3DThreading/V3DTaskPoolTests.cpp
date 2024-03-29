/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTaskPoolTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DThreading/V3DTaskPool.h"
#include "V3DEngineTests/V3DTestObject/V3DTestEventActionFunc.h"
#include "V3DEngine/V3DData/V3DIFileRepository.h"
#include "V3DEngineTests/V3DTestObject/V3DTestContentData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSimpleFileRepository.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DEnvironment.h"
#include "V3DEngine/V3DIO/V3DFile.h"

#include <cassert>

using namespace std;
using namespace V3D::V3DEngine::V3DThreading;
using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DData;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DThreading
{
	atomic jobCounter{ 0 };
	atomic workerCounter{ 0 };
	atomic memoryLeakCount{ 0 };
	constexpr int LoopCount = 200;
	V3DTaskPool<void*>* pool;
	const int PoolSize = V3DEnvironment::GetCpuCoreCount() - 1;
	
	void TestFunc1() { (void)sqrt(1000); ++jobCounter; }
	void TestFunc2() { (void)sqrt(20000); ++jobCounter; }
	void TestFunc3() { (void)sqrt(300000); ++jobCounter; }
	void TestFunc4() { (void)sqrt(4000000); ++jobCounter; }

	void V3DTaskPoolTests::PoolObjectMethodTest()
	{
		int x = 100;
		V3DTestEventActionFunc test(x, 10);

		pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, 2);
		pool->SubmitJobFunction(&V3DTestEventActionFunc::IncrementXWithNumber, test);
		pool->SubmitJobFunction(&V3DTestEventActionFunc::MultiplicationXWithNumber, test);
		pool->WaitForFinish();
		V3DTest::AssertOk(x == 1100, V3DFILE_INFO);
		V3DMemory::Delete(pool);

		x = 100;
		auto pool2 = V3DMemory::New<V3DTaskPool<int>>(V3DFILE_INFO, 2);
		pool2->SubmitJobFunction(&V3DTestEventActionFunc::IncrementXWithParam, test, 10);
		pool2->SubmitJobFunction(&V3DTestEventActionFunc::MultiplicationXWithParam, test, 20);
		pool2->WaitForFinish();
		V3DTest::AssertOk(x == 2200, V3DFILE_INFO);
		V3DMemory::Delete(pool2);
	}

	void V3DTaskPoolTests::PoolStressTest()
	{
		jobCounter.store(0);
		workerCounter.store(0);

		memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
		pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize);

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < LoopCount; j++)
			{
				pool->SubmitJobFunction(TestFunc1);
				workerCounter.store(workerCounter.load() + 1);

				pool->SubmitJobFunction(TestFunc2);
				workerCounter.store(workerCounter.load() + 1);

				pool->SubmitJobFunction(TestFunc3);
				workerCounter.store(workerCounter.load() + 1);

				pool->SubmitJobFunction(TestFunc4);
				workerCounter.store(workerCounter.load() + 1);
			}

		pool->WaitForFinish();

		V3DMemory::Delete(pool);
		V3DTest::AssertOk(memoryLeakCount.load() == V3DMemory::GetMemoryLeakCount(), V3DFILE_INFO);

		V3DTest::AssertOk(jobCounter.load() == LoopCount * 4 * 100, V3DFILE_INFO);
		V3DTest::AssertOk(workerCounter.load() == LoopCount * 4 * 100, V3DFILE_INFO);
	}

	void V3DTaskPoolTests::ThreadVsPoolTimingTest()
	{
		//run functions on threads step by step
		V3DTest::AddTimingTest("V3DTaskPoolThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter.store(0);
					
					for (int i = 0; i < LoopCount; i++)
					{
						auto t1 = thread(TestFunc1);
						auto t2 = thread(TestFunc2);
						auto t3 = thread(TestFunc3);
						auto t4 = thread(TestFunc4);
						t1.join();
						t2.join();
						t3.join();
						t4.join();
					}

					assert(jobCounter.load() == LoopCount * 4);
				}, false, 0
			});

		//create pool
		V3DTest::AddTimingTest("V3DTaskPoolTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
					pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize);
				}, true, 0
			});

		//run functions on threads parallel
		V3DTest::AddTimingTest("V3DTaskPoolTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter.store(0);
					workerCounter.store(0);

					for (int i = 0; i < LoopCount; i++)
					{
						pool->SubmitJobFunction(TestFunc1);
						++workerCounter;

						pool->SubmitJobFunction(TestFunc2);
						++workerCounter;

						pool->SubmitJobFunction(TestFunc3);
						++workerCounter;

						pool->SubmitJobFunction(TestFunc4);
						++workerCounter;
					}
					
					pool->WaitForFinish();

					V3DMemory::Delete(pool);

					assert(memoryLeakCount.load() == V3DMemory::GetMemoryLeakCount());
					assert(jobCounter.load() == LoopCount * 4);
					assert(workerCounter.load() == LoopCount * 4);
				}, false, 1
			});
	}

	void V3DTaskPoolTests::ThreadPerSystemPoolTimingTest()
	{
		//xample: create pool with 3 threads
		V3DTest::AddTimingTest("V3DTaskPoolThreadPerSystemTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
					pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize);
				}, true, 0
			});

		//xample: run 6 functions on pool with 3 threads on 4 cpu cores
		V3DTest::AddTimingTest("V3DTaskPoolThreadPerSystemTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter.store(0);
					workerCounter.store(0);

					for (int i = 0; i < LoopCount; i++)
					{
						for (int poolSizeIndex = 0; poolSizeIndex < PoolSize * 2; poolSizeIndex++)
						{
							pool->SubmitJobFunction(TestFunc4);
						}
						pool->WaitForFinish();
					}
					
					V3DMemory::Delete(pool);
				}, false, 1
			});

		//xample: create pool with 6 threads
		V3DTest::AddTimingTest("V3DTaskPoolThreadPerSystemDoubleThreadsTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
					pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize * 2);
				}, true, 0
			});

		//xample: run 6 functions on pool with 6 threads on 4 cpu cores
		V3DTest::AddTimingTest("V3DTaskPoolThreadPerSystemDoubleThreadsTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter.store(0);
					workerCounter.store(0);

					for (int i = 0; i < LoopCount; i++)
					{
						for (int poolSizeIndex = 0; poolSizeIndex < PoolSize * 2; poolSizeIndex++)
						{
							pool->SubmitJobFunction(TestFunc4);
						}
						pool->WaitForFinish();
					}

					V3DMemory::Delete(pool);
				}, false, 1
			});
	}

	atomic contentCounter{ 0 };
	constexpr int ContentCount = 10;
	
	void V3DTaskPoolTests::LoadContentTimingTest()
	{
		auto LoadContent = [&](const V3DString& name)
		{
			V3DIFileRepository<V3DTestContentData*>* simpleFileRepository = V3DMemory::New<V3DTestSimpleFileRepository<V3DTestContentData*>>(V3DFILE_INFO);
			auto data = simpleFileRepository->Load(V3DAssetPathType::Internal, name.ToChar());
			for (int j = 0; j < ContentCount; j++)
				(void)data->bytes[j];

			V3DMemory::Delete(data);
			V3DMemory::Delete(simpleFileRepository);
			contentCounter.store(contentCounter.load() + 1);
		};

		//GenerateContents
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentSingleThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
					V3DIFileRepository<V3DTestContentData*>* simpleFileRepository = V3DMemory::New<V3DTestSimpleFileRepository<V3DTestContentData*>>(V3DFILE_INFO);
					auto data = V3DMemory::New<V3DTestContentData>(V3DFILE_INFO);

					for (int i = 0; i < V3DTestContentData::Size; ++i)
						data->bytes[i] = static_cast<char>(i % 255);

					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						simpleFileRepository->Save(data, name.ToChar());
						assert(V3DFile::GetSize(V3DAssetPathType::Internal, name.ToChar()) == V3DTestContentData::Size);
					}

					V3DMemory::Delete(data);
					V3DMemory::Delete(simpleFileRepository);
					assert(memoryLeakCount.load() == V3DMemory::GetMemoryLeakCount());
				}, true, 0
			});

		//LoadContentsSingleThread
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentSingleThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					contentCounter.store(0);
					//memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());

					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						LoadContent(name);
					}

					assert(contentCounter.load() == ContentCount);
					//assert(memoryLeakCount.load() == V3DMemory::GetMemoryLeakCount());
				}, false, 1
			});

		//LoadContentsTaskPool
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentTimingTest", V3DTestTimingData
			{
				[&]
				{
					contentCounter.store(0);
					//memoryLeakCount.store(V3DMemory::GetMemoryLeakCount());
					auto taskPool = V3DMemory::New<V3DTaskPool<V3DString>>(V3DFILE_INFO, PoolSize);

					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						taskPool->SubmitJobFunction(LoadContent, name);
					}

					taskPool->WaitForFinish();
					
					V3DMemory::Delete(taskPool);

					//assert(memoryLeakCount.load() == V3DMemory::GetMemoryLeakCount());
					assert(contentCounter.load() == ContentCount);
				}, false, 2
			});

		//RemoveContents
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentTimingTest", V3DTestTimingData
			{
				[&]
				{
					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						V3DFile::Delete(name.ToChar());
					}

				}, true, 3
			});
	}

	void V3DTaskPoolTests::RunAllUnitTests()
	{
		PoolObjectMethodTest();
		PoolStressTest();
	}

	void V3DTaskPoolTests::RegisterIntegrationTests()
	{
	}

	void V3DTaskPoolTests::RegisterTimingTests()
	{
		ThreadVsPoolTimingTest();
		ThreadPerSystemPoolTimingTest();
		LoadContentTimingTest();
	}
}
