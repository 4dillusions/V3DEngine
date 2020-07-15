/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DGameComponentTest final
	{
	public:
		V3DGameComponentTest() = delete;
		V3DGameComponentTest(const V3DGameComponentTest&) = delete;
		V3DGameComponentTest(V3DGameComponentTest&&) = delete;
		~V3DGameComponentTest() = delete;
		V3DGameComponentTest& operator=(const V3DGameComponentTest&) = delete;
		V3DGameComponentTest& operator=(V3DGameComponentTest&&) = delete;

		static void CtorsOperatorsTest();

		static void RunAllTests();
	};
}
