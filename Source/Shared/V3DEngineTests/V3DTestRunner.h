/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine
{
	enum class V3DTestType : unsigned;

	class V3DTestRunner final
	{
		static V3DTestType testType;

		static void Init();
		static void RegisterTimingTestsRunUniTests();
		static void RegisterAndRunIntegrationTests();
		static void RunTimingTests();
		static void CleanUp();

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
