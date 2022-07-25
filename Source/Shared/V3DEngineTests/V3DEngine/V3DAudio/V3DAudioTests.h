/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	class V3DAudioTests final
	{
	public:
		V3DAudioTests() = delete;
		V3DAudioTests(const V3DAudioTests&) = delete;
		V3DAudioTests(V3DAudioTests&&) = delete;
		~V3DAudioTests() = delete;
		V3DAudioTests& operator=(const V3DAudioTests&) = delete;
		V3DAudioTests& operator=(V3DAudioTests&&) = delete;

		static void RunAllTests();
	};
}
