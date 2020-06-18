/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemoryTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngineTests/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DMemoryTest::ValueTest()
	{
		int* value = V3DMemory::New<int>(V3DFILE_INFO, 0);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 1, V3DFILE_INFO);
		V3DMemory::Delete(value);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(value == nullptr, V3DFILE_INFO);
	}
	
	void V3DMemoryTest::ArrayTest()
	{
		int* arr = V3DMemory::NewArray<int>(V3DFILE_INFO, 10);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 1, V3DFILE_INFO);
		V3DMemory::DeleteArray(arr);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(arr == nullptr, V3DFILE_INFO);
	}
	
	void V3DMemoryTest::MatrixTest()
	{
		const int matrixSize = 5;
		int** matrix = V3DMemory::NewMatrix<int>(V3DFILE_INFO, matrixSize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 1 + matrixSize, V3DFILE_INFO);
		V3DMemory::DeleteMatrix(matrix, matrixSize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}
	
	void V3DMemoryTest::PointerArrayTest()
	{
		const int pointerArraySize = 10;
		V3DTestObjectA::SetReferenceCounter(0);
		V3DTestObjectA** pointerArray = V3DMemory::NewPointerArray<V3DTestObjectA>(V3DFILE_INFO, pointerArraySize);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 1, V3DFILE_INFO);
		for (int i = 0; i < pointerArraySize; i++)
			pointerArray[i] = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 1 + pointerArraySize, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == pointerArraySize, V3DFILE_INFO);

		for (int i = 0; i < pointerArraySize; i++)
			V3DMemory::Delete(pointerArray[i]);

		V3DMemory::DeletePointerArray(pointerArray);

		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
	}

	void V3DMemoryTest::RunAllTests()
	{
		ValueTest();
		ArrayTest();
		MatrixTest();
		PointerArrayTest();
	}
}
