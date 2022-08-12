/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DMemoryTests final
	{
		static constexpr int TestMemoryAllocsize = 20'000'000; //20'000'000;
		
	public:
		V3DMemoryTests() = delete;
		V3DMemoryTests(const V3DMemoryTests&) = delete;
		V3DMemoryTests(V3DMemoryTests&&) = delete;
		~V3DMemoryTests() = delete;
		V3DMemoryTests& operator=(const V3DMemoryTests&) = delete;
		V3DMemoryTests& operator=(V3DMemoryTests&&) = delete;

		static void ValueTest();
		static void ValuePlacementNewTest();
		static void ArrayTest();
		static void MatrixTest();
		static void PointerArrayTest();

		static void MemoryAllocationCMallocTimingTest();
		static void MemoryAllocationCppNewTimingTest();
		static void MemoryNewDeleteTimingTest();
		
		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
