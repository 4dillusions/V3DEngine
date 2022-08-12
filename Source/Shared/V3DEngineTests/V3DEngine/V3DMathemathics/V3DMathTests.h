/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMathTests final
	{
	public:
		V3DMathTests() = delete;
		V3DMathTests(const V3DMathTests&) = delete;
		V3DMathTests(V3DMathTests&&) = delete;
		~V3DMathTests() = delete;
		V3DMathTests& operator=(const V3DMathTests&) = delete;
		V3DMathTests& operator=(V3DMathTests&&) = delete;

		static void MathTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
