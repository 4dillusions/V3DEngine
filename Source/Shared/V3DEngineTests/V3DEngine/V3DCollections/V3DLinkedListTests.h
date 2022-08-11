/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DLinkedListTests final
	{
	public:
		V3DLinkedListTests() = delete;
		V3DLinkedListTests(const V3DLinkedListTests&) = delete;
		V3DLinkedListTests(V3DLinkedListTests&&) = delete;
		~V3DLinkedListTests() = delete;
		V3DLinkedListTests& operator=(const V3DLinkedListTests&) = delete;
		V3DLinkedListTests& operator=(V3DLinkedListTests&&) = delete;

		static void CtorDtorTest();
		static void AddGetDataTest();
		static void AddRemoveStaticTest();
		static void AddRemoveDynamicTest();
		static void RemoveLastThreeWhileIterateTest();

		static void LinkedListAddRemoveTimingTest();
		static void LinkedListIterateTimingTest();

		static void RunAllTests();
	};
}
