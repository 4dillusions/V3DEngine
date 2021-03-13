/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DStopperTest final
	{
	public:
		V3DStopperTest() = delete;
		V3DStopperTest(const V3DStopperTest&) = delete;
		V3DStopperTest(V3DStopperTest&&) = delete;
		~V3DStopperTest() = delete;
		V3DStopperTest& operator=(const V3DStopperTest&) = delete;
		V3DStopperTest& operator=(V3DStopperTest&&) = delete;

		static void StopperTest();
		
		static void RunAllTests();
	};
}
