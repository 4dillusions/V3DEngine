/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DObjectPoolTests final
	{
	public:
		V3DObjectPoolTests() = delete;
		V3DObjectPoolTests(const V3DObjectPoolTests&) = delete;
		V3DObjectPoolTests(V3DObjectPoolTests&&) = delete;
		~V3DObjectPoolTests() = delete;
		V3DObjectPoolTests& operator=(const V3DObjectPoolTests&) = delete;
		V3DObjectPoolTests& operator=(V3DObjectPoolTests&&) = delete;

		static void CtorDtorTest();
		static void AddRemoveTest();
		static void RemoveAllTest();
		static void RemoveAllAndAddTest();
		static void RemoveFirstWhileIterateTest();
		static void RemoveLastWhileIterateTest();

		static void ObjectPoolAddRemoveTimingTest();
		static void ObjectPoolIterateTimingTest();

		static void RunAllTests();
	};
}
