/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppUnusedIncludeDirective
#include "StdTests.h"

#include <vector>
#include <map>

#include "V3DCollectionsTests.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void StdTests::StdVectorAddRemoveTimingTest()
	{
		static std::vector<V3DTestObjectA*>* stdList;

		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					stdList = V3DMemory::New<std::vector<V3DTestObjectA*>>(V3DFILE_INFO);
				}, true, 0
			});

		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
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

		V3DTest::AddTimingTest("StdVectorAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (auto& i : *stdList)
						V3DMemory::Delete(i);

					V3DMemory::Delete(stdList);
				}, true, 2
			});
	}

	void StdTests::StdVectorIterateTimingTest()
	{
		static std::vector<V3DTestObjectA*>* stdList;

		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTestTimingData
			{
				[]()
				{
					stdList = V3DMemory::New<std::vector<V3DTestObjectA*>>(V3DFILE_INFO);

					for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
						stdList->push_back(V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO));
				}, true, 0
			});

		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTestTimingData
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

		V3DTest::AddTimingTest("StdVectorIterateTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (auto& i : *stdList)
						V3DMemory::Delete(i);

					V3DMemory::Delete(stdList);
				}, true, 2
			});
	}

	void StdTests::StdMapAddRemoveTimingTest()
	{
		static std::map<int, V3DTestObjectA*>* stdMap;

		V3DTest::AddTimingTest("StdMapAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					stdMap = V3DMemory::New<std::map<int, V3DTestObjectA*>>(V3DFILE_INFO);
				}, true, 0
			});

		V3DTest::AddTimingTest("StdMapAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
						stdMap->insert({i, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO) });

					for (auto i = stdMap->begin(); i != stdMap->end(); ++i)
					{
						if (!(*i).second->GetIsAlive())
						{
							V3DMemory::Delete(i->second);

							if (i == --stdMap->end())
							{
								stdMap->erase(i);
								break;
							}

							i = stdMap->erase(i);
						}
					}
				}, false, 1
			});

		V3DTest::AddTimingTest("StdMapAddRemoveTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (auto& i : *stdMap)
						V3DMemory::Delete(i.second);

					V3DMemory::Delete(stdMap);
				}, true, 2
			});
	}

	void StdTests::StdMapIterateTimingTest()
	{
		static std::map<int, V3DTestObjectA*>* stdMap;

		V3DTest::AddTimingTest("StdMapIterateTimingTest", V3DTestTimingData
			{
				[]()
				{
					stdMap = V3DMemory::New<std::map<int, V3DTestObjectA*>>(V3DFILE_INFO);

					for (int i = 0; i < V3DCollectionsTests::BigSize; i++)
						stdMap->insert({ i, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO) });
				}, true, 0
			});

		V3DTest::AddTimingTest("StdMapIterateTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (auto i = stdMap->begin(); i != stdMap->end(); ++i)
					{
						if (!(*i).second->GetIsAlive())
						{
							V3DMemory::Delete(i->second);

							if (i == --stdMap->end())
							{
								stdMap->erase(i);
								break;
							}

							i = stdMap->erase(i);
						}

						(*i).second->SetId((*i).second->GetId() + 1);
					}
				}, false, 1
			});

		V3DTest::AddTimingTest("StdMapIterateTimingTest", V3DTestTimingData
			{
				[]()
				{
					for (auto& i : *stdMap)
						V3DMemory::Delete(i.second);

					V3DMemory::Delete(stdMap);
				}, true, 2
			});
	}

	void StdTests::RunAllUnitTests()
	{
	}

	void StdTests::RegisterIntegrationTests()
	{
	}

	void StdTests::RegisterTimingTests()
	{
		StdVectorAddRemoveTimingTest();
		StdVectorIterateTimingTest();
		StdMapAddRemoveTimingTest();
		StdMapIterateTimingTest();
	}
}