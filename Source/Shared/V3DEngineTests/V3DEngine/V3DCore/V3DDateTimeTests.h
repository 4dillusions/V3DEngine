/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DDateTimeTests final
	{
	public:
		V3DDateTimeTests() = delete;
		V3DDateTimeTests(const V3DDateTimeTests&) = delete;
		V3DDateTimeTests(V3DDateTimeTests&&) = delete;
		~V3DDateTimeTests() = delete;
		V3DDateTimeTests& operator=(const V3DDateTimeTests&) = delete;
		V3DDateTimeTests& operator=(V3DDateTimeTests&&) = delete;

		static void DateTimeTest();
		
		static void RunAllTests();
	};
}
