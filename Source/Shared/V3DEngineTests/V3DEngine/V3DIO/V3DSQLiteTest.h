/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DSQLiteTest final
	{
	public:
		V3DSQLiteTest() = delete;
		V3DSQLiteTest(const V3DSQLiteTest&) = delete;
		V3DSQLiteTest(V3DSQLiteTest&&) = delete;
		~V3DSQLiteTest() = delete;
		V3DSQLiteTest& operator=(const V3DSQLiteTest&) = delete;
		V3DSQLiteTest& operator=(V3DSQLiteTest&&) = delete;

		static void CRUDTest();
		
		static void RunAllTests();
	};
}
