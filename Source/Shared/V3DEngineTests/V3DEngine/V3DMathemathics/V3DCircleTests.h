/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DCircleTests final
	{
	public:
		V3DCircleTests() = delete;
		V3DCircleTests(const V3DCircleTests&) = delete;
		V3DCircleTests(V3DCircleTests&&) = delete;
		~V3DCircleTests() = delete;
		V3DCircleTests& operator=(const V3DCircleTests&) = delete;
		V3DCircleTests& operator=(V3DCircleTests&&) = delete;

		static void CircleTest();
		
		static void RunAllTests();
	};
}
