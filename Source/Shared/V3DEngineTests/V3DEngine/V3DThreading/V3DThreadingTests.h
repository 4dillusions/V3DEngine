/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DThreading
{
	class V3DThreadingTests final
	{
	public:
		V3DThreadingTests() = delete;
		V3DThreadingTests(const V3DThreadingTests&) = delete;
		V3DThreadingTests(V3DThreadingTests&&) = delete;
		~V3DThreadingTests() = delete;
		V3DThreadingTests& operator=(const V3DThreadingTests&) = delete;
		V3DThreadingTests& operator=(V3DThreadingTests&&) = delete;

		static void RunAllTests();
	};
}
