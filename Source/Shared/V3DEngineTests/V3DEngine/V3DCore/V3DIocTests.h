/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DIocTests final
	{
	public:
		V3DIocTests() = delete;
		V3DIocTests(const V3DIocTests&) = delete;
		V3DIocTests(V3DIocTests&&) = delete;
		~V3DIocTests() = delete;
		V3DIocTests& operator=(const V3DIocTests&) = delete;
		V3DIocTests& operator=(V3DIocTests&&) = delete;

		static void DynamicTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
