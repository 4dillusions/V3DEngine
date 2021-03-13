/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DIocTest final
	{
	public:
		V3DIocTest() = delete;
		V3DIocTest(const V3DIocTest&) = delete;
		V3DIocTest(V3DIocTest&&) = delete;
		~V3DIocTest() = delete;
		V3DIocTest& operator=(const V3DIocTest&) = delete;
		V3DIocTest& operator=(V3DIocTest&&) = delete;

		static void StaticTest();
		static void DynamicTest();
		
		static void RunAllTests();
	};
}
