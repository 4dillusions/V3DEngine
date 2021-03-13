/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DDateTimeTest final
	{
	public:
		V3DDateTimeTest() = delete;
		V3DDateTimeTest(const V3DDateTimeTest&) = delete;
		V3DDateTimeTest(V3DDateTimeTest&&) = delete;
		~V3DDateTimeTest() = delete;
		V3DDateTimeTest& operator=(const V3DDateTimeTest&) = delete;
		V3DDateTimeTest& operator=(V3DDateTimeTest&&) = delete;

		static void DateTimeTest();
		
		static void RunAllTests();
	};
}
