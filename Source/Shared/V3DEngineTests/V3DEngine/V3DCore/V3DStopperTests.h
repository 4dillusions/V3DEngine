/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DStopperTests final
	{
	public:
		V3DStopperTests() = delete;
		V3DStopperTests(const V3DStopperTests&) = delete;
		V3DStopperTests(V3DStopperTests&&) = delete;
		~V3DStopperTests() = delete;
		V3DStopperTests& operator=(const V3DStopperTests&) = delete;
		V3DStopperTests& operator=(V3DStopperTests&&) = delete;

		static void StopperTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
