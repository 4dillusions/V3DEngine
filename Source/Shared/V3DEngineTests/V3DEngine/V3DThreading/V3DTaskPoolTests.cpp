/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTaskPoolTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DThreading/V3DTaskPool.h"
#include "V3DEngine/V3DData/V3DIFileRepository.h"
#include "V3DEngineTests/V3DTestObject/V3DTestContentData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSimpleFileRepository.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DAbstractEnvironment.h"
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
	constexpr int LoopCount = 200;
	V3DTaskPool<void*>* pool;
	const int PoolSize = V3DAbstractEnvironment::GetCpuCoreCount() - 1;
	int memoryLeakCount;
	
	void TestFunc1() { (void)sqrt(1000); ++jobCounter; }
	void TestFunc2() { (void)sqrt(20000); ++jobCounter; }
	void TestFunc3() { (void)sqrt(300000); ++jobCounter; }
	void TestFunc4() { (void)sqrt(4000000); ++jobCounter; }

	void V3DTaskPoolTests::PoolStressTest()
	{
		jobCounter = 0;
		workerCounter = 0;

		memoryLeakCount = V3DMemory::GetMemoryLeakCount();
		pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize);

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < LoopCount; j++)
			{
				pool->SetJobFunction(TestFunc1);
				++workerCounter;

				pool->SetJobFunction(TestFunc2);
				++workerCounter;

				pool->SetJobFunction(TestFunc3);
				++workerCounter;

				pool->SetJobFunction(TestFunc4);
				++workerCounter;
			}

		while (jobCounter < LoopCount * 4 * 100)
			;

		V3DMemory::Delete(pool);
		V3DTest::AssertOk(memoryLeakCount == V3DMemory::GetMemoryLeakCount(), V3DFILE_INFO);

		V3DTest::AssertOk(jobCounter == LoopCount * 4 * 100, V3DFILE_INFO);
		V3DTest::AssertOk(workerCounter == LoopCount * 4 * 100, V3DFILE_INFO);
	}

	void V3DTaskPoolTests::ThreadVsPoolTimingTest()
	{
		V3DTest::AddTimingTest("V3DTaskPoolThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter = 0;
					
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

					assert(jobCounter == LoopCount * 4);
				}, false, 0
			});

		V3DTest::AddTimingTest("V3DTaskPoolTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount = V3DMemory::GetMemoryLeakCount();
					pool = V3DMemory::New<V3DTaskPool<void*>>(V3DFILE_INFO, PoolSize);
				}, true, 0
			});

		V3DTest::AddTimingTest("V3DTaskPoolTimingTest", V3DTestTimingData
			{
				[&]
				{
					jobCounter = 0;
					workerCounter = 0;

					for (int i = 0; i < LoopCount; i++)
					{
						pool->SetJobFunction(TestFunc1);
						++workerCounter;

						pool->SetJobFunction(TestFunc2);
						++workerCounter;

						pool->SetJobFunction(TestFunc3);
						++workerCounter;

						pool->SetJobFunction(TestFunc4);
						++workerCounter;
					}

					while (jobCounter < LoopCount * 4)
						;

					V3DMemory::Delete(pool);

					assert(memoryLeakCount == V3DMemory::GetMemoryLeakCount());
					assert(jobCounter == LoopCount * 4);
					assert(workerCounter == LoopCount * 4);
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

			V3DMemory::DeleteArray(data);
			V3DMemory::DeleteArray(simpleFileRepository);
			++contentCounter;
		};

		//GenerateContents
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentSingleThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					memoryLeakCount = V3DMemory::GetMemoryLeakCount();
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
					V3DMemory::DeleteArray(simpleFileRepository);
					assert(memoryLeakCount == V3DMemory::GetMemoryLeakCount());
				}, true, 0
			});

		//LoadContentsSingleThread
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentSingleThreadTimingTest", V3DTestTimingData
			{
				[&]
				{
					contentCounter = 0;
					memoryLeakCount = V3DMemory::GetMemoryLeakCount();
					
					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						LoadContent(name);
					}

					assert(contentCounter == ContentCount);
					assert(memoryLeakCount == V3DMemory::GetMemoryLeakCount());
				}, false, 1
			});

		//LoadContentsTaskPool, RemoveContents
		V3DTest::AddTimingTest("V3DTaskPoolLoadContentTimingTest", V3DTestTimingData
			{
				[&]
				{
					contentCounter = 0;
					memoryLeakCount = V3DMemory::GetMemoryLeakCount();
					auto taskPool = V3DMemory::New<V3DTaskPool<V3DString>>(V3DFILE_INFO, PoolSize);
					
					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						taskPool->SetJobFunction(LoadContent, name);
					}

					while (contentCounter < 10)
						;

					V3DMemory::Delete(taskPool);

					for (int i = 0; i < ContentCount; i++)
					{
						V3DString name("data");
						name += i;
						name += ".dat";

						V3DFile::Delete(name.ToChar());
					}
					                                                         
					assert(contentCounter == ContentCount);
					assert(memoryLeakCount == V3DMemory::GetMemoryLeakCount());
				}, false, 2
			});
	}
	
	void V3DTaskPoolTests::RunAllTests()
	{
		PoolStressTest();

		ThreadVsPoolTimingTest();
		LoadContentTimingTest();
	}
}
