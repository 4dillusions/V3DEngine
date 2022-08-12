/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRandomTests final
	{
	public:
		V3DRandomTests() = delete;
		V3DRandomTests(const V3DRandomTests&) = delete;
		V3DRandomTests(V3DRandomTests&&) = delete;
		~V3DRandomTests() = delete;
		V3DRandomTests& operator=(const V3DRandomTests&) = delete;
		V3DRandomTests& operator=(V3DRandomTests&&) = delete;

		static void RandomTest();
		
		static void TimingTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
