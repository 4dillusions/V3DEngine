/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DVector2DTests final
	{
	public:
		V3DVector2DTests() = delete;
		V3DVector2DTests(const V3DVector2DTests&) = delete;
		V3DVector2DTests(V3DVector2DTests&&) = delete;
		~V3DVector2DTests() = delete;
		V3DVector2DTests& operator=(const V3DVector2DTests&) = delete;
		V3DVector2DTests& operator=(V3DVector2DTests&&) = delete;

		static void OperatorsTest();
		static void FunctionsTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
