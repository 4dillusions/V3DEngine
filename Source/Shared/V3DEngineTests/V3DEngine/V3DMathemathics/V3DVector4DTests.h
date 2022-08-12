/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DVector4DTests final
	{
	public:
		V3DVector4DTests() = delete;
		V3DVector4DTests(const V3DVector4DTests&) = delete;
		V3DVector4DTests(V3DVector4DTests&&) = delete;
		~V3DVector4DTests() = delete;
		V3DVector4DTests& operator=(const V3DVector4DTests&) = delete;
		V3DVector4DTests& operator=(V3DVector4DTests&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
