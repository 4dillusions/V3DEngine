/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DCircleTest final
	{
	public:
		V3DCircleTest() = delete;
		V3DCircleTest(const V3DCircleTest&) = delete;
		V3DCircleTest(V3DCircleTest&&) = delete;
		~V3DCircleTest() = delete;
		V3DCircleTest& operator=(const V3DCircleTest&) = delete;
		V3DCircleTest& operator=(V3DCircleTest&&) = delete;

		static void CircleTest();
		
		static void RunAllTests();
	};
}
