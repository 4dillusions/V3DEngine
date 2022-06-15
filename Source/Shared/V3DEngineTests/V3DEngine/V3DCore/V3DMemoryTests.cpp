/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemoryTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngineTests/V3DEngine/V3DCollections/V3DCollectionsTests.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DMemoryTests::ValueTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		int* value = V3DMemory::New<int>(V3DFILE_INFO, 0);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1, V3DFILE_INFO);
		V3DMemory::Delete(value);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(value == nullptr, V3DFILE_INFO);
	}

	void V3DMemoryTests::ValuePlacementNewTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();
		V3DTestObjectA::SetReferenceCounter(0);

		V3DTestObjectA* value = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1, V3DFILE_INFO);
		V3DTest::AssertOk(value->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(value->GetIsAlive() == true, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 1, V3DFILE_INFO);

		value->SetId(12);
		value->SetIsAlive(false);
		V3DTest::AssertOk(value->GetId() == 12, V3DFILE_INFO);
		V3DTest::AssertOk(value->GetIsAlive() == false, V3DFILE_INFO);

		const V3DTestObjectA* valueAddress = value;
		value = V3DMemory::PlacementNew(value);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(valueAddress == value, V3DFILE_INFO);
		V3DTest::AssertOk(value->GetId() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(value->GetIsAlive() == true, V3DFILE_INFO);

		V3DMemory::Delete(value);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(value == nullptr, V3DFILE_INFO);
	}
	
	void V3DMemoryTests::ArrayTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		int* arr = V3DMemory::NewArray<int>(V3DFILE_INFO, 10);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1, V3DFILE_INFO);
		V3DMemory::DeleteArray(arr);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(arr == nullptr, V3DFILE_INFO);
	}
	
	void V3DMemoryTests::MatrixTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr int MatrixSize = 5;
		int** matrix = V3DMemory::NewMatrix<int>(V3DFILE_INFO, MatrixSize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1 + MatrixSize, V3DFILE_INFO);
		V3DMemory::DeleteMatrix(matrix, MatrixSize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DMemoryTests::PointerArrayTest()
	{
		const int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		constexpr int PointerArraySize = 10;
		V3DTestObjectA::SetReferenceCounter(0);
		V3DTestObjectA** pointerArray = V3DMemory::NewPointerArray<V3DTestObjectA>(V3DFILE_INFO, PointerArraySize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1, V3DFILE_INFO);
		for (int i = 0; i < PointerArraySize; i++)
			pointerArray[i] = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount + 1 + PointerArraySize, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == PointerArraySize, V3DFILE_INFO);

		for (int i = 0; i < PointerArraySize; i++)
			V3DMemory::Delete(pointerArray[i]);

		V3DMemory::DeletePointerArray(pointerArray);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
	}

	void V3DMemoryTests::MemoryAllocationCMallocTimingTest()
	{
		char* heap = static_cast<char*>(malloc(sizeof(char) * TestMemoryAllocsize));
		for (int i = 0; i < TestMemoryAllocsize; i++)
			heap[i] = 'A';
	}

	void V3DMemoryTests::MemoryAllocationCppNewTimingTest()
	{
		char* heap = V3DMemory::NewArrayExplicit<char>(TestMemoryAllocsize);
		for (int i = 0; i < TestMemoryAllocsize; i++)
			heap[i] = 'A';
	}

	void V3DMemoryTests::MemoryNewDeleteTimingTest()
	{
		static V3DTestObjectA* objecArray[V3DCollections::V3DCollectionsTests::BigSize];

		for (auto& i : objecArray)
			i = new V3DTestObjectA();

		for (auto& i : objecArray)
			delete i;
	}

	void V3DMemoryTests::RunAllTests()
	{
		ValueTest();
		ValuePlacementNewTest();
		ArrayTest();
		MatrixTest();
		PointerArrayTest();

		V3DTest::AddTimingTest("MemoryAllocationCMallocTimingTest", MemoryAllocationCMallocTimingTest);
		V3DTest::AddTimingTest("MemoryAllocationCppNewTimingTest", MemoryAllocationCppNewTimingTest);
		V3DTest::AddTimingTest("MemoryNewDeleteTimingTest", MemoryNewDeleteTimingTest);
	}
}
