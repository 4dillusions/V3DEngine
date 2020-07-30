/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DTextRWTest final
	{
	public:
		V3DTextRWTest() = delete;
		V3DTextRWTest(const V3DTextRWTest&) = delete;
		V3DTextRWTest(V3DTextRWTest&&) = delete;
		~V3DTextRWTest() = delete;
		V3DTextRWTest& operator=(const V3DTextRWTest&) = delete;
		V3DTextRWTest& operator=(V3DTextRWTest&&) = delete;

		static void TextRWTest();

		static void RunAllTests();
	};
}
