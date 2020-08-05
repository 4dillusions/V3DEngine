/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DJsonIOTest final
	{
	public:
		V3DJsonIOTest() = delete;
		V3DJsonIOTest(const V3DJsonIOTest&) = delete;
		V3DJsonIOTest(V3DJsonIOTest&&) = delete;
		~V3DJsonIOTest() = delete;
		V3DJsonIOTest& operator=(const V3DJsonIOTest&) = delete;
		V3DJsonIOTest& operator=(V3DJsonIOTest&&) = delete;

		static void JsonParseTest();
		static void BuildJsonFromCodeTest();
		static void ConfigLoadSaveTest();
		static void UIBuildTest();

		static void RunAllTests();
	};
}
