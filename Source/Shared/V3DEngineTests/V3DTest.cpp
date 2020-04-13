/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTest.h"
#include "V3DEngineTests/V3DTestIOPlatform.h"
#include "V3DEngine/V3DMacros.h"

#include <chrono>

using namespace std;
using namespace std::chrono;

namespace V3D::V3DEngineTests
{
	int V3DTest::errorCounter = 0;
	int V3DTest::tests = 0;
	int V3DTest::passedTests = 0;
	list<const char*> V3DTest::errorList;
	std::map<std::string, std::function<void()>> V3DTest::timingList;

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

	void V3DTest::AddTimingTest(const std::string& timingFunctionName, const std::function<void()>& timingFunction)
	{
		if (timingList.find(timingFunctionName) == timingList.end())
			timingList.insert({ timingFunctionName, timingFunction });
	}

	void V3DTest::RunTimingTests()
	{
		WriteOutput("\nTiming tests:");
		
		for (const auto& func : timingList)
		{
			auto start = system_clock::now();
			func.second();
			auto end = system_clock::now();
			
			WriteOutput(func.first + " " + to_string(duration_cast<milliseconds>(end - start).count()) + " ms");
		}
	}

	void V3DTest::WriteStatistics()
	{
		WriteOutput("UnitTest" + string(V3DPLATFORM_INFO));
		WriteOutput("Passed: " + to_string(tests) + '/' + to_string(passedTests));
		WriteOutput("Unit test Errors:");

		if (errorCounter > 0)
		{
			for (auto text : errorList)
				WriteOutput(text);
		}
		else
			WriteOutput("0 error");

		Init();
	}
}
