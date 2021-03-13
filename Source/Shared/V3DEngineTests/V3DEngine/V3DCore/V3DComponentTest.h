/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DComponentTest final
	{
	public:
		V3DComponentTest() = delete;
		V3DComponentTest(const V3DComponentTest&) = delete;
		V3DComponentTest(V3DComponentTest&&) = delete;
		~V3DComponentTest() = delete;
		V3DComponentTest& operator=(const V3DComponentTest&) = delete;
		V3DComponentTest& operator=(V3DComponentTest&&) = delete;

		static void GameComponentTest();
		static void GameCompositeComponentTest();
		static void GameCompositeComponentPoolTest();

		static void RunAllTests();
	};
}
