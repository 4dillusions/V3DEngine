/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine
{
	class V3DTestRunner final
	{
	public:
		V3DTestRunner() = delete;
		V3DTestRunner(const V3DTestRunner&) = delete;
		V3DTestRunner(V3DTestRunner&&) = delete;
		~V3DTestRunner() = delete;
		V3DTestRunner& operator=(const V3DTestRunner&) = delete;
		V3DTestRunner& operator=(V3DTestRunner&&) = delete;
		
		static void RunAllTests();
	};
}
