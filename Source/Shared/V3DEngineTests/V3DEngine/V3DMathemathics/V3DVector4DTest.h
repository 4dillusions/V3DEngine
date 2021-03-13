/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DVector4DTest final
	{
	public:
		V3DVector4DTest() = delete;
		V3DVector4DTest(const V3DVector4DTest&) = delete;
		V3DVector4DTest(V3DVector4DTest&&) = delete;
		~V3DVector4DTest() = delete;
		V3DVector4DTest& operator=(const V3DVector4DTest&) = delete;
		V3DVector4DTest& operator=(V3DVector4DTest&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllTests();
	};
}
