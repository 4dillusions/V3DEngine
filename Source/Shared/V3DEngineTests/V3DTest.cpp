/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTest.h"
#include "V3DEngineTests/V3DTestIO.h"
#include "V3DEngine/V3DCore/V3DEnvironment.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

#include <chrono>
#include <string>

using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests
{
	int V3DTest::errorCounter = 0;
	int V3DTest::tests = 0;
	int V3DTest::passedTests = 0;
	std::list<const char*> V3DTest::errorList;
	std::map<std::string, V3DTestTimingData> V3DTest::timingList;
	std::list<std::function<void()>> V3DTest::integrationList;
	V3DITestIO<V3DTestIO>& V3DTest::testIO = V3DTestIO::Get();

	void V3DTest::Init()
	{	
		errorCounter = 0;
		tests = 0;
		passedTests = 0;
		errorList.clear();
	}

	void V3DTest::AssertOk(bool isOk, const char* info)
	{
		tests++;

		if (isOk)
			passedTests++;
		else
		{
			errorCounter++;
			errorList.push_back(info);
		}
	}

	void V3DTest::AddTimingTest(const std::string& timingFunctionName, const V3DTestTimingData& timingTestData)
	{
		if (timingList.find(timingFunctionName) == timingList.end())
			timingList.insert({ timingFunctionName + testIO.ConvertToString(timingTestData.orderIndex), timingTestData });
	}

	void V3DTest::AddTimingTest(const std::string& timingFunctionName, const std::function<void()>& timingFunction)
	{
		AddTimingTest(timingFunctionName, V3DTestTimingData{ timingFunction });
	}

	void V3DTest::RunTimingTests()
	{
		testIO.WriteOutput("\nTiming tests:");

		for (const auto& mapItem : timingList)
		{
			if (mapItem.second.isKip)
			{
				mapItem.second.func();
				continue;
			}

			auto start = std::chrono::system_clock::now();
			mapItem.second.func();
			auto end = std::chrono::system_clock::now();

			auto functionName = mapItem.first.substr(0, mapItem.first.size() - 1);
			testIO.WriteOutput(functionName + " " + testIO.ConvertToString(static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count())) + " ms");
		}
	}

	void V3DTest::AddIntegrationTest(const std::function<void()>& integrationFunction)
	{
		integrationList.push_back(integrationFunction);
	}

	void V3DTest::RunIntegrationTests()
	{
		for (const auto& func : integrationList)
			func();
	}

	void V3DTest::WriteStatistics()
	{
		static auto environment = V3DIoc<V3DEnvironment>::Get();
		
		testIO.WriteOutput(std::string("UnitTest (") + V3DEnvironment::GetRunMode() + " " + environment.GetPlatformName() + ")");
		testIO.WriteOutput("Passed: " + testIO.ConvertToString(tests) + '/' + testIO.ConvertToString(passedTests));
		testIO.WriteOutput("Unit test Errors:");

		if (errorCounter > 0)
		{
			for (const auto text : errorList)
				testIO.WriteOutput(text);
		}
		else
			testIO.WriteOutput("0 error");

		Init();
	}
}
