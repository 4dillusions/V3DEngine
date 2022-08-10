/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DDecimalTreeTests final
	{
	public:
		V3DDecimalTreeTests() = delete;
		V3DDecimalTreeTests(const V3DDecimalTreeTests&) = delete;
		V3DDecimalTreeTests(V3DDecimalTreeTests&&) = delete;
		~V3DDecimalTreeTests() = delete;
		V3DDecimalTreeTests& operator=(const V3DDecimalTreeTests&) = delete;
		V3DDecimalTreeTests& operator=(V3DDecimalTreeTests&&) = delete;

		static void CtorDtorTest();
		static void AddGetDataTest();
		static void AddRemoveStaticTest();
		static void AddRemoveStaticObjectKeyTest();
		static void AddRemoveDynamicTest();
		static void RemoveAtTest();
		static void RemoveLastThreeWhileIterateTest();

		static void DecimalTreeAddRemoveTimingTest();
		static void DecimalTreeIterateTimingTest();

		static void RunAllTests();
	};
}
