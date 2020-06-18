/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRectangleTest final
	{
	public:
		V3DRectangleTest() = delete;
		V3DRectangleTest(const V3DRectangleTest&) = delete;
		V3DRectangleTest(V3DRectangleTest&&) = delete;
		~V3DRectangleTest() = delete;
		V3DRectangleTest& operator=(const V3DRectangleTest&) = delete;
		V3DRectangleTest& operator=(V3DRectangleTest&&) = delete;

		static void RectangleTest();
		
		static void RunAllTests();
	};
}
