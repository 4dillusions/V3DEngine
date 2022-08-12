/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DLoggerTests final
	{
	public:
		V3DLoggerTests() = delete;
		V3DLoggerTests(const V3DLoggerTests&) = delete;
		V3DLoggerTests(V3DLoggerTests&&) = delete;
		~V3DLoggerTests() = delete;
		V3DLoggerTests& operator=(const V3DLoggerTests&) = delete;
		V3DLoggerTests& operator=(V3DLoggerTests&&) = delete;

		static void LoggerTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
