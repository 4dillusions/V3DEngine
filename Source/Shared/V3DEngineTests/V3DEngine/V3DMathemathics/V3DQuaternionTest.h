/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DQuaternionTest final
	{
	public:
		V3DQuaternionTest() = delete;
		V3DQuaternionTest(const V3DQuaternionTest&) = delete;
		V3DQuaternionTest(V3DQuaternionTest&&) = delete;
		~V3DQuaternionTest() = delete;
		V3DQuaternionTest& operator=(const V3DQuaternionTest&) = delete;
		V3DQuaternionTest& operator=(V3DQuaternionTest&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllTests();
	};
}
