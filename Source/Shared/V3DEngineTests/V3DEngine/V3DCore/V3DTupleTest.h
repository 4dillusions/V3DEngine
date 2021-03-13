/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DTupleTest final
	{
	public:
		V3DTupleTest() = delete;
		V3DTupleTest(const V3DTupleTest&) = delete;
		V3DTupleTest(V3DTupleTest&&) = delete;
		~V3DTupleTest() = delete;
		V3DTupleTest& operator=(const V3DTupleTest&) = delete;
		V3DTupleTest& operator=(V3DTupleTest&&) = delete;

		static void TupleTest();
		
		static void RunAllTests();
	};
}
