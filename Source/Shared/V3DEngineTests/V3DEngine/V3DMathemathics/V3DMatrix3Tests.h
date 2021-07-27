/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMatrix3Tests final
	{
	public:
		V3DMatrix3Tests() = delete;
		V3DMatrix3Tests(const V3DMatrix3Tests&) = delete;
		V3DMatrix3Tests(V3DMatrix3Tests&&) = delete;
		~V3DMatrix3Tests() = delete;
		V3DMatrix3Tests& operator=(const V3DMatrix3Tests&) = delete;
		V3DMatrix3Tests& operator=(V3DMatrix3Tests&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllTests();
	};
}
