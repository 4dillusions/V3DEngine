/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DSQLiteTests final
	{
	public:
		V3DSQLiteTests() = delete;
		V3DSQLiteTests(const V3DSQLiteTests&) = delete;
		V3DSQLiteTests(V3DSQLiteTests&&) = delete;
		~V3DSQLiteTests() = delete;
		V3DSQLiteTests& operator=(const V3DSQLiteTests&) = delete;
		V3DSQLiteTests& operator=(V3DSQLiteTests&&) = delete;

		static void CRUDTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
