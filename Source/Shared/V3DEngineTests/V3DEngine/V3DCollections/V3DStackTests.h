/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DStackTests final
	{
	public:
		V3DStackTests() = delete;
		V3DStackTests(const V3DStackTests&) = delete;
		V3DStackTests(V3DStackTests&&) = delete;
		~V3DStackTests() = delete;
		V3DStackTests& operator=(const V3DStackTests&) = delete;
		V3DStackTests& operator=(V3DStackTests&&) = delete;

		static void CtorDtorTest();
		static void StackStaticTest();
		static void StackDynamicTest();

		static void RunAllTests();
	};
}
