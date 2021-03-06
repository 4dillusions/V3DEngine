/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DNetTest final
	{
	public:
		V3DNetTest() = delete;
		V3DNetTest(const V3DNetTest&) = delete;
		V3DNetTest(V3DNetTest&&) = delete;
		~V3DNetTest() = delete;
		V3DNetTest& operator=(const V3DNetTest&) = delete;
		V3DNetTest& operator=(V3DNetTest&&) = delete;

		static void InitTest();
		
		static void RunAllTests();
	};
}
