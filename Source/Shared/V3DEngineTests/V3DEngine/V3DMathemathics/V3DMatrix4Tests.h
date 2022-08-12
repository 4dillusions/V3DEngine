/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMatrix4Tests final
	{
	public:
		V3DMatrix4Tests() = delete;
		V3DMatrix4Tests(const V3DMatrix4Tests&) = delete;
		V3DMatrix4Tests(V3DMatrix4Tests&&) = delete;
		~V3DMatrix4Tests() = delete;
		V3DMatrix4Tests& operator=(const V3DMatrix4Tests&) = delete;
		V3DMatrix4Tests& operator=(V3DMatrix4Tests&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
