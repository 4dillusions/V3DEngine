/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DComponentTests final
	{
	public:
		V3DComponentTests() = delete;
		V3DComponentTests(const V3DComponentTests&) = delete;
		V3DComponentTests(V3DComponentTests&&) = delete;
		~V3DComponentTests() = delete;
		V3DComponentTests& operator=(const V3DComponentTests&) = delete;
		V3DComponentTests& operator=(V3DComponentTests&&) = delete;

		static void GameComponentTest();
		static void GameCompositeComponentTest();
		static void GameCompositeComponentPoolTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
