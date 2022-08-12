/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DQuaternionTests final
	{
	public:
		V3DQuaternionTests() = delete;
		V3DQuaternionTests(const V3DQuaternionTests&) = delete;
		V3DQuaternionTests(V3DQuaternionTests&&) = delete;
		~V3DQuaternionTests() = delete;
		V3DQuaternionTests& operator=(const V3DQuaternionTests&) = delete;
		V3DQuaternionTests& operator=(V3DQuaternionTests&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
