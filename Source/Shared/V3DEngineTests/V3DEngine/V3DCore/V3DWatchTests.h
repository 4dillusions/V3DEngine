/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DWatchTests final
	{
	public:
		V3DWatchTests() = delete;
		V3DWatchTests(const V3DWatchTests&) = delete;
		V3DWatchTests(V3DWatchTests&&) = delete;
		~V3DWatchTests() = delete;
		V3DWatchTests& operator=(const V3DWatchTests&) = delete;
		V3DWatchTests& operator=(V3DWatchTests&&) = delete;

		static void WatchTest();
		
		static void RunAllTests();
	};
}
