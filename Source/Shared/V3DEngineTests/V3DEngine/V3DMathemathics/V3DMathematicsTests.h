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
	public:
		static const int RandomCountSize = 100'000;
		static const int MaxRandom = 1'000;
		
		V3DMathematicsTests() = delete;
		V3DMathematicsTests(const V3DMathematicsTests&) = delete;
		V3DMathematicsTests(V3DMathematicsTests&&) = delete;
		~V3DMathematicsTests() = delete;
		V3DMathematicsTests& operator=(const V3DMathematicsTests&) = delete;
		V3DMathematicsTests& operator=(V3DMathematicsTests&&) = delete;

		static void RunAllTests();
	};
}
