/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#define UNITTEST

#include <list>
#include <map>
#include <functional>

namespace V3D::V3DEngineTests
{
	template <typename TDerived> class V3DITestIO;
	class V3DTestIO;
	
	//cross-platform unit test system for TDD
	class V3DTest final
	{
		static int errorCounter;
		static int tests;
		static int passedTests;
		static std::list<const char*> errorList;
		static std::map<std::string, std::function<void()>> timingList;
		static V3DITestIO<V3DTestIO> &testIO;

		static void Init();

	public:
		V3DTest() = delete;
		V3DTest(const V3DTest&) = delete;
		V3DTest(V3DTest&&) = delete;
		~V3DTest() = delete;
		V3DTest& operator=(const V3DTest&) = delete;
		V3DTest& operator=(V3DTest&&) = delete;

		static void AssertOk(bool isOk, const char* info);
		static void AddTimingTest(const std::string &timingFunctionName, const std::function<void()> &timingFunction);
		static void RunTimingTests();
		static void WriteStatistics();
	};
}
