/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRandomTest final
	{
	public:
		V3DRandomTest() = delete;
		V3DRandomTest(const V3DRandomTest&) = delete;
		V3DRandomTest(V3DRandomTest&&) = delete;
		~V3DRandomTest() = delete;
		V3DRandomTest& operator=(const V3DRandomTest&) = delete;
		V3DRandomTest& operator=(V3DRandomTest&&) = delete;

		static void RandomTest();
		
		static void TimingTest();
		
		static void RunAllTests();
	};
}
