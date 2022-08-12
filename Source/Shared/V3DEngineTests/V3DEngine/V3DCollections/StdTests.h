/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class StdTests final
	{
	public:
		StdTests() = delete;
		StdTests(const StdTests&) = delete;
		StdTests(StdTests&&) = delete;
		~StdTests() = delete;
		StdTests& operator=(const StdTests&) = delete;
		StdTests& operator=(StdTests&&) = delete;

		static void StdVectorAddRemoveTimingTest();
		static void StdVectorIterateTimingTest();
		static void StdMapAddRemoveTimingTest();
		static void StdMapIterateTimingTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
