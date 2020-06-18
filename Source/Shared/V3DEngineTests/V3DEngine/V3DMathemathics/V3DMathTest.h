/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMathTest final
	{
	public:
		V3DMathTest() = delete;
		V3DMathTest(const V3DMathTest&) = delete;
		V3DMathTest(V3DMathTest&&) = delete;
		~V3DMathTest() = delete;
		V3DMathTest& operator=(const V3DMathTest&) = delete;
		V3DMathTest& operator=(V3DMathTest&&) = delete;

		static void MathTest();
		
		static void RunAllTests();
	};
}
