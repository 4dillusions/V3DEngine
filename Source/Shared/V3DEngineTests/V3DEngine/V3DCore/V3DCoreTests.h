/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DCoreTests final
	{
	public:
		V3DCoreTests() = delete;
		V3DCoreTests(const V3DCoreTests&) = delete;
		V3DCoreTests(V3DCoreTests&&) = delete;
		~V3DCoreTests() = delete;
		V3DCoreTests& operator=(const V3DCoreTests&) = delete;
		V3DCoreTests& operator=(V3DCoreTests&&) = delete;

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
