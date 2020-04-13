/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	class V3DIOTests final
	{
	public:
		V3DIOTests() = delete;
		V3DIOTests(const V3DIOTests&) = delete;
		V3DIOTests(V3DIOTests&&) = delete;
		~V3DIOTests() = delete;
		V3DIOTests& operator=(const V3DIOTests&) = delete;
		V3DIOTests& operator=(V3DIOTests&&) = delete;

		static void V3DLoggerTest();
		
		static void RunAllTests();
	};
}
