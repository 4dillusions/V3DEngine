/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DFileTest final
	{
	public:
		V3DFileTest() = delete;
		V3DFileTest(const V3DFileTest&) = delete;
		V3DFileTest(V3DFileTest&&) = delete;
		~V3DFileTest() = delete;
		V3DFileTest& operator=(const V3DFileTest&) = delete;
		V3DFileTest& operator=(V3DFileTest&&) = delete;

		static void FileTest();

		static void RunAllTests();
	};
}
