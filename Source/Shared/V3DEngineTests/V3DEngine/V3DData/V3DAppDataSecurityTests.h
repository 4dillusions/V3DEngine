/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DData
{
	class V3DAppDataSecurityTests final
	{
	public:
		V3DAppDataSecurityTests() = delete;
		V3DAppDataSecurityTests(const V3DAppDataSecurityTests&) = delete;
		V3DAppDataSecurityTests(V3DAppDataSecurityTests&&) = delete;
		~V3DAppDataSecurityTests() = delete;
		V3DAppDataSecurityTests& operator=(const V3DAppDataSecurityTests&) = delete;
		V3DAppDataSecurityTests& operator=(V3DAppDataSecurityTests&&) = delete;

		static void AllAppDataValidTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
