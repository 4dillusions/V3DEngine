/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DRectangleTests final
	{
	public:
		V3DRectangleTests() = delete;
		V3DRectangleTests(const V3DRectangleTests&) = delete;
		V3DRectangleTests(V3DRectangleTests&&) = delete;
		~V3DRectangleTests() = delete;
		V3DRectangleTests& operator=(const V3DRectangleTests&) = delete;
		V3DRectangleTests& operator=(V3DRectangleTests&&) = delete;

		static void RectangleTest();
		
		static void RunAllTests();
	};
}
