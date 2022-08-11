/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTestObject/V3DTestTimingData.h"

#include <list>
#include <map>
#include <string>

namespace V3D::V3DEngineTests
{
	//cross-platform unit test system for TDD
	class V3DTest final
	{
		static int errorCounter;
		static int tests;
		static int passedTests;
		static std::list<const char*> errorList;
		static std::map<std::string, V3DTestObject::V3DTestTimingData> timingList;
		static std::list<std::function<void()>> integrationList;
		
		static void Reset();

		static std::string ConvertToString(int value);
		static void WriteOutput(const std::string& text); //will be implement in partial .cpp per platform
		static void WriteOutput(const char* text); //will be implement in partial .cpp per platform

	public:
		V3DTest() = delete;
		V3DTest(const V3DTest&) = delete;
		V3DTest(V3DTest&&) = delete;
		~V3DTest() = delete;
		V3DTest& operator=(const V3DTest&) = delete;
		V3DTest& operator=(V3DTest&&) = delete;

		static void AssertOk(bool isOk, const char* info);
		static void AddTimingTest(const std::string& timingFunctionName, const V3DTestObject::V3DTestTimingData& timingTestData);
		static void AddTimingTest(const std::string& timingFunctionName, const std::function<void()>& timingFunction);
		static void RunTimingTests();
		static void AddIntegrationTest(const std::function<const void()>& integrationFunction);
		static void RunIntegrationTests();
		static void WriteStatistics();
	};
}
