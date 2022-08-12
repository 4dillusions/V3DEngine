/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DNetTests final
	{
	public:
		V3DNetTests() = delete;
		V3DNetTests(const V3DNetTests&) = delete;
		V3DNetTests(V3DNetTests&&) = delete;
		~V3DNetTests() = delete;
		V3DNetTests& operator=(const V3DNetTests&) = delete;
		V3DNetTests& operator=(V3DNetTests&&) = delete;

		static void InitTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
