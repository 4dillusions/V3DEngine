/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	class V3DMemoryTest final
	{
		static const int TestMemoryAllocsize = 20'000'000; //20'000'000;
		
	public:
		V3DMemoryTest() = delete;
		V3DMemoryTest(const V3DMemoryTest&) = delete;
		V3DMemoryTest(V3DMemoryTest&&) = delete;
		~V3DMemoryTest() = delete;
		V3DMemoryTest& operator=(const V3DMemoryTest&) = delete;
		V3DMemoryTest& operator=(V3DMemoryTest&&) = delete;

		static void ValueTest();
		static void ArrayTest();
		static void MatrixTest();
		static void PointerArrayTest();

		static void MemoryAllocationCMallocTimingTest();
		static void MemoryAllocationCppNewTimingTest();
		
		static void RunAllTests();
	};
}
