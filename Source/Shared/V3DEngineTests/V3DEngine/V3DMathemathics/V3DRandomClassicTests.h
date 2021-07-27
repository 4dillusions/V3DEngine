/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRandomClassicTests final
	{
	public:
		V3DRandomClassicTests() = delete;
		V3DRandomClassicTests(const V3DRandomClassicTests&) = delete;
		V3DRandomClassicTests(V3DRandomClassicTests&&) = delete;
		~V3DRandomClassicTests() = delete;
		V3DRandomClassicTests& operator=(const V3DRandomClassicTests&) = delete;
		V3DRandomClassicTests& operator=(V3DRandomClassicTests&&) = delete;

		static void RandomClassicTest();
		
		static void TimingTest();
		
		static void RunAllTests();
	};
}
