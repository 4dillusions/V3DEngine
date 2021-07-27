/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DJsonIOTests final
	{
	public:
		V3DJsonIOTests() = delete;
		V3DJsonIOTests(const V3DJsonIOTests&) = delete;
		V3DJsonIOTests(V3DJsonIOTests&&) = delete;
		~V3DJsonIOTests() = delete;
		V3DJsonIOTests& operator=(const V3DJsonIOTests&) = delete;
		V3DJsonIOTests& operator=(V3DJsonIOTests&&) = delete;

		static void JsonParseTest();
		static void BuildJsonFromCodeTest();
		static void ConfigLoadSaveTest();
		static void UIBuildTest();

		static void RunAllTests();
	};
}
