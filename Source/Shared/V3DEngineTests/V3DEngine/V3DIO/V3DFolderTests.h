/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DFolderTests final
	{
	public:
		V3DFolderTests() = delete;
		V3DFolderTests(const V3DFolderTests&) = delete;
		V3DFolderTests(V3DFolderTests&&) = delete;
		~V3DFolderTests() = delete;
		V3DFolderTests& operator=(const V3DFolderTests&) = delete;
		V3DFolderTests& operator=(V3DFolderTests&&) = delete;

		static void FolderTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
