/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DLoggerTest final
	{
	public:
		V3DLoggerTest() = delete;
		V3DLoggerTest(const V3DLoggerTest&) = delete;
		V3DLoggerTest(V3DLoggerTest&&) = delete;
		~V3DLoggerTest() = delete;
		V3DLoggerTest& operator=(const V3DLoggerTest&) = delete;
		V3DLoggerTest& operator=(V3DLoggerTest&&) = delete;

		static void LoggerTest();

		static void RunAllTests();
	};
}
