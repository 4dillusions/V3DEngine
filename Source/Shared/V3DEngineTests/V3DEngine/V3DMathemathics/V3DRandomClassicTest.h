/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRandomClassicTest final
	{
	public:
		V3DRandomClassicTest() = delete;
		V3DRandomClassicTest(const V3DRandomClassicTest&) = delete;
		V3DRandomClassicTest(V3DRandomClassicTest&&) = delete;
		~V3DRandomClassicTest() = delete;
		V3DRandomClassicTest& operator=(const V3DRandomClassicTest&) = delete;
		V3DRandomClassicTest& operator=(V3DRandomClassicTest&&) = delete;

		static void RandomClassicTest();
		
		static void TimingTest();
		
		static void RunAllTests();
	};
}
