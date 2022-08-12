/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DFileTests final
	{
	public:
		V3DFileTests() = delete;
		V3DFileTests(const V3DFileTests&) = delete;
		V3DFileTests(V3DFileTests&&) = delete;
		~V3DFileTests() = delete;
		V3DFileTests& operator=(const V3DFileTests&) = delete;
		V3DFileTests& operator=(V3DFileTests&&) = delete;

		static void FileTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
