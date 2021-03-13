/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DDynamicArrayTests final
	{
	public:
		V3DDynamicArrayTests() = delete;
		V3DDynamicArrayTests(const V3DDynamicArrayTests&) = delete;
		V3DDynamicArrayTests(V3DDynamicArrayTests&&) = delete;
		~V3DDynamicArrayTests() = delete;
		V3DDynamicArrayTests& operator=(const V3DDynamicArrayTests&) = delete;
		V3DDynamicArrayTests& operator=(V3DDynamicArrayTests&&) = delete;

		static void CtorDtorTest();
		static void AddGetDataTest();
		static void AddRemoveStaticTest();
		static void AddRemoveDynamicTest();
		static void RemoveAtTest();
		static void CopyReturnTest();

		static void DynamicArrayAddRemoveTimingTest();
		static void DynamicArrayIterateTimingTest();

		static void RunAllTests();
	};
}
