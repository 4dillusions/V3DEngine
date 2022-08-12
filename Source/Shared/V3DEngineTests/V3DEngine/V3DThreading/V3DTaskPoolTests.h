/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DThreading
{
	class V3DTaskPoolTests final
	{
	public:
		V3DTaskPoolTests() = delete;
		V3DTaskPoolTests(const V3DTaskPoolTests&) = delete;
		V3DTaskPoolTests(V3DTaskPoolTests&&) = delete;
		~V3DTaskPoolTests() = delete;
		V3DTaskPoolTests& operator=(const V3DTaskPoolTests&) = delete;
		V3DTaskPoolTests& operator=(V3DTaskPoolTests&&) = delete;

		static void PoolObjectMethodTest();
		static void PoolStressTest();

		static void ThreadVsPoolTimingTest();
		static void ThreadPerSystemPoolTimingTest();
		static void LoadContentTimingTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
