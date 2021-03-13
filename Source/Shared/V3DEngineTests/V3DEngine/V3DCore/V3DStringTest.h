/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DStringTest final
	{
	public:
		V3DStringTest() = delete;
		V3DStringTest(const V3DStringTest&) = delete;
		V3DStringTest(V3DStringTest&&) = delete;
		~V3DStringTest() = delete;
		V3DStringTest& operator=(const V3DStringTest&) = delete;
		V3DStringTest& operator=(V3DStringTest&&) = delete;

		static void CtorOperatorsTest();
		static void ReturnTest();
		static void ToTest();
		static void HashAndConversionTest();
		static void GetTest();
		static void IsTest();
		static void CopyArrayTest();
		static void ReplaceRemoveTest();
		static void LargeTest();
		static void CopyTest();
		static void SplitTest();

		static void RunAllTests();
	};
}
