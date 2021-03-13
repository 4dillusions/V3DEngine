/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DTimeHourTest final
	{
	public:
		V3DTimeHourTest() = delete;
		V3DTimeHourTest(const V3DTimeHourTest&) = delete;
		V3DTimeHourTest(V3DTimeHourTest&&) = delete;
		~V3DTimeHourTest() = delete;
		V3DTimeHourTest& operator=(const V3DTimeHourTest&) = delete;
		V3DTimeHourTest& operator=(V3DTimeHourTest&&) = delete;

		static void TimeHourTest();
		
		static void RunAllTests();
	};
}
