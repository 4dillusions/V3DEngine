/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DData
{
	class V3DDataTests final
	{
	public:
		V3DDataTests() = delete;
		V3DDataTests(const V3DDataTests&) = delete;
		V3DDataTests(V3DDataTests&&) = delete;
		~V3DDataTests() = delete;
		V3DDataTests& operator=(const V3DDataTests&) = delete;
		V3DDataTests& operator=(V3DDataTests&&) = delete;

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
