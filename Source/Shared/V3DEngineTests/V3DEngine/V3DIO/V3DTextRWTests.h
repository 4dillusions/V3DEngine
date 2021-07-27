/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DTextRWTests final
	{
	public:
		V3DTextRWTests() = delete;
		V3DTextRWTests(const V3DTextRWTests&) = delete;
		V3DTextRWTests(V3DTextRWTests&&) = delete;
		~V3DTextRWTests() = delete;
		V3DTextRWTests& operator=(const V3DTextRWTests&) = delete;
		V3DTextRWTests& operator=(V3DTextRWTests&&) = delete;

		static void TextRWTest();

		static void RunAllTests();
	};
}
