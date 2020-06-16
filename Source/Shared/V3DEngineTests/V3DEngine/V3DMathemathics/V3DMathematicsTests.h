/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DMathematics
{
	class V3DMathematicsTests final
	{
		static const int timingCountSize = 100'000;
		static const int maxRandom = 1'000;
		
	public:
		V3DMathematicsTests() = delete;
		V3DMathematicsTests(const V3DMathematicsTests&) = delete;
		V3DMathematicsTests(V3DMathematicsTests&&) = delete;
		~V3DMathematicsTests() = delete;
		V3DMathematicsTests& operator=(const V3DMathematicsTests&) = delete;
		V3DMathematicsTests& operator=(V3DMathematicsTests&&) = delete;

		static void V3DMathTest();
		static void V3DVector2DTest();
		static void V3DVector3DTest();
		static void V3DCircleTest();
		static void V3DRectangleTest();
		static void V3DVector4DTest();
		static void V3DMatrix3Test();
		static void V3DMatrix4Test();
		static void V3DRandomTest();
		static void V3DRandomClassicTest();

		static void V3DRandomTimingTest();
		static void V3DRandomClassicTimingTest();

		static void RunAllTests();
	};
}
