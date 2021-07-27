/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DTimeHourTests final
	{
	public:
		V3DTimeHourTests() = delete;
		V3DTimeHourTests(const V3DTimeHourTests&) = delete;
		V3DTimeHourTests(V3DTimeHourTests&&) = delete;
		~V3DTimeHourTests() = delete;
		V3DTimeHourTests& operator=(const V3DTimeHourTests&) = delete;
		V3DTimeHourTests& operator=(V3DTimeHourTests&&) = delete;

		static void TimeHourTest();
		
		static void RunAllTests();
	};
}
