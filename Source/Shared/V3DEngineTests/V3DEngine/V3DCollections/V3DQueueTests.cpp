/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DQueueTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCollections/V3DQueue.h"
#include "V3DEngineTests/V3DTestObject/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngineTests::V3DTestObject;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DQueueTests::CtorDtorTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		V3DQueue<V3DTestObjectA> staticObjQueue { 3 };
		V3DTest::AssertOk(staticObjQueue.IsEmpty(), V3DFILE_INFO);

		staticObjQueue.Add(V3DTestObjectA());
		V3DTest::AssertOk(!staticObjQueue.IsEmpty(), V3DFILE_INFO);

		staticObjQueue.Add(V3DTestObjectA());
		staticObjQueue.Add(V3DTestObjectA());
		V3DTest::AssertOk(staticObjQueue.IsFull(), V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3, V3DFILE_INFO);

		staticObjQueue.~V3DQueue();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
	}

	void V3DQueueTests::QueueStaticTest()
	{
		V3DQueue<int> numberFIFO{ 5 };
		
		V3DTest::AssertOk(numberFIFO.Add(1), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(10), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(11), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(3), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(!numberFIFO.Add(100), V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 10, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 11, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Take() == nullptr, V3DFILE_INFO);

		V3DTest::AssertOk(numberFIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(5), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(7), V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(3), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(1), V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(9), V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 5, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 9, V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Take() == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Add(2), V3DFILE_INFO);
		V3DTest::AssertOk(*numberFIFO.Take() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(numberFIFO.Take() == nullptr, V3DFILE_INFO);
	}

	void V3DQueueTests::QueueDynamicTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		
		V3DQueue<V3DTestObjectA*> objFIFO{ 5 };
		auto obj1 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 1);
		auto obj2 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 2);
		auto obj3 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 3);
		auto obj5 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5);
		auto obj7 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 7);
		auto obj9 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 9);
		auto obj10 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 10);
		auto obj11 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11);
		auto obj100 = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 100);
		
		V3DTest::AssertOk(objFIFO.Add(obj1), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj10), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj11), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj3), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk(!objFIFO.Add(obj100), V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 1, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 10, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 11, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 3, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Take() == nullptr, V3DFILE_INFO);
		
		V3DTest::AssertOk(objFIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj5), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj7), V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj3), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj1), V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj9), V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 5, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 7, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 3, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 1, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 9, V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Take() == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Add(obj2), V3DFILE_INFO);
		V3DTest::AssertOk((*objFIFO.Take())->GetId() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(objFIFO.Take() == nullptr, V3DFILE_INFO);
		
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
		objFIFO.~V3DQueue();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DQueueTests::RunAllTests()
	{
		CtorDtorTest();
		QueueStaticTest();
		QueueDynamicTest();
	}
}
