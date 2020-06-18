/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMatrix4Test final
	{
	public:
		V3DMatrix4Test() = delete;
		V3DMatrix4Test(const V3DMatrix4Test&) = delete;
		V3DMatrix4Test(V3DMatrix4Test&&) = delete;
		~V3DMatrix4Test() = delete;
		V3DMatrix4Test& operator=(const V3DMatrix4Test&) = delete;
		V3DMatrix4Test& operator=(V3DMatrix4Test&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllTests();
	};
}
