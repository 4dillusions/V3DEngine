/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DFolderTest final
	{
	public:
		V3DFolderTest() = delete;
		V3DFolderTest(const V3DFolderTest&) = delete;
		V3DFolderTest(V3DFolderTest&&) = delete;
		~V3DFolderTest() = delete;
		V3DFolderTest& operator=(const V3DFolderTest&) = delete;
		V3DFolderTest& operator=(V3DFolderTest&&) = delete;

		static void FolderTest();

		static void RunAllTests();
	};
}
