/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DWatchTest final
	{
	public:
		V3DWatchTest() = delete;
		V3DWatchTest(const V3DWatchTest&) = delete;
		V3DWatchTest(V3DWatchTest&&) = delete;
		~V3DWatchTest() = delete;
		V3DWatchTest& operator=(const V3DWatchTest&) = delete;
		V3DWatchTest& operator=(V3DWatchTest&&) = delete;

		static void WatchTest();
		
		static void RunAllTests();
	};
}
