/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStackTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCollections/V3DStack.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DStackTests::CtorDtorTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTestObjectA::SetReferenceCounter(0);
		V3DStack<V3DTestObjectA> staticObjStack { 3 };
		V3DTest::AssertOk(staticObjStack.IsEmpty(), V3DFILE_INFO);

		staticObjStack.Add(V3DTestObjectA());
		V3DTest::AssertOk(!staticObjStack.IsEmpty(), V3DFILE_INFO);

		staticObjStack.Add(V3DTestObjectA());
		staticObjStack.Add(V3DTestObjectA());
		V3DTest::AssertOk(staticObjStack.IsFull(), V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3, V3DFILE_INFO);

		staticObjStack.~V3DStack();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
	}

	void V3DStackTests::StackStaticTest()
	{
		V3DStack<int> numberLIFO{ 5 };
		
		V3DTest::AssertOk(numberLIFO.Add(1), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(10), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(11), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(3), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(!numberLIFO.Add(100), V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 11, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 10, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Take() == nullptr, V3DFILE_INFO);
		
		V3DTest::AssertOk(numberLIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(5), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(7), V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(3), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(1), V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(9), V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 9, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 5, V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Take() == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(*numberLIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberLIFO.Take() == nullptr, V3DFILE_INFO);
	}

	void V3DStackTests::StackDynamicTest()
	{
		int memoryLeakCount = V3DMemory::GetMemoryLeakCount();

		V3DTestObjectA::SetReferenceCounter(0);
		
		V3DStack<V3DTestObjectA*> objLIFO{ 5 };
		auto obj1 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 1);
		auto obj2 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 2);
		auto obj3 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 3);
		auto obj5 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5);
		auto obj7 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 7);
		auto obj9 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 9);
		auto obj10 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 10);
		auto obj11 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11);
		auto obj100 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 100);
		
		V3DTest::AssertOk(objLIFO.Add(obj1), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj10), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj11), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj3), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk(!objLIFO.Add(obj100), V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 3, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 11, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 10, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Take() == nullptr, V3DFILE_INFO);

		V3DTest::AssertOk(objLIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj5), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj7), V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj3), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj1), V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj9), V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 9, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 1, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 3, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 5, V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Take() == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk((*objLIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objLIFO.Take() == nullptr, V3DFILE_INFO);

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 9, V3DFILE_INFO);
		V3DMemory::Delete(obj1);
		V3DMemory::Delete(obj2);
		V3DMemory::Delete(obj3);
		V3DMemory::Delete(obj5);
		V3DMemory::Delete(obj7);
		V3DMemory::Delete(obj9);
		V3DMemory::Delete(obj10);
		V3DMemory::Delete(obj11);
		V3DMemory::Delete(obj100);
		objLIFO.~V3DStack();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == memoryLeakCount, V3DFILE_INFO);
	}
	
	void V3DStackTests::RunAllTests()
	{
		CtorDtorTest();
		StackStaticTest();
		StackDynamicTest();
	}
}
