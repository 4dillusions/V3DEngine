/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DDecimalTreeTests.h"

#include "V3DCollectionsTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCollections/V3DDecimalTree.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngineTests/V3DTestObjectA.h"

using namespace V3D::V3DEngine::V3DCollections;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	void V3DDecimalTreeTests::CtorDtorTest()
	{
		V3DDecimalTree<int, int> intTree;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::decimalTreeMemoryAllocCount, V3DFILE_INFO);
		intTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDecimalTree<int, V3DTestObjectA> staticObjTree;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::decimalTreeMemoryAllocCount, V3DFILE_INFO);
		staticObjTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDecimalTree<int, V3DTestObjectA*> dynamicObjTree;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::decimalTreeMemoryAllocCount, V3DFILE_INFO);
		dynamicObjTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDecimalTree<V3DString, V3DTestObjectA*> dynamicObjTree2;
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == V3DCollectionsTests::decimalTreeMemoryAllocCount + 1, V3DFILE_INFO);
		dynamicObjTree2.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::AddGetDataTest()
	{
		V3DDecimalTree<int, int> intTree;
		intTree.Add(110, 10);
		intTree.First();
		V3DTest::AssertOk(*intTree.GetCurrentItem() == 10, V3DFILE_INFO);
		V3DTest::AssertOk(intTree.GetCurrentKey() == 110, V3DFILE_INFO);
		intTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDecimalTree<int, V3DTestObjectA> staticObjTree;
		V3DTestObjectA sObj;
		sObj.SetId(20);
		staticObjTree.Add(20, sObj);
		staticObjTree.First();
		V3DTest::AssertOk(staticObjTree.GetCurrentItem()->GetId() == 20, V3DFILE_INFO);
		V3DTest::AssertOk(staticObjTree.GetCurrentKey() == 20, V3DFILE_INFO);
		staticObjTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		V3DDecimalTree<int, V3DTestObjectA*> dynamicObjTree;
		V3DTestObjectA* dObj = V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO);
		dObj->SetId(20);
		dynamicObjTree.Add(20, dObj);
		dynamicObjTree.First();
		V3DTest::AssertOk((*dynamicObjTree.GetCurrentItem())->GetId() == 20, V3DFILE_INFO);
		V3DTest::AssertOk(dynamicObjTree.GetCurrentKey() == 20, V3DFILE_INFO);
		V3DMemory::Delete(dObj);
		dynamicObjTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);

		
		V3DDecimalTree<V3DString, int> staticObjStringTree;
		staticObjStringTree.Add(V3DString("texture1.jpg"), 345);
		staticObjStringTree.First();
		V3DTest::AssertOk(*staticObjStringTree.GetCurrentItem() == 345, V3DFILE_INFO);
		V3DTest::AssertOk(staticObjStringTree.GetCurrentKey() == V3DString("texture1.jpg"), V3DFILE_INFO);
		staticObjStringTree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::AddRemoveStaticTest()
	{
		V3DDecimalTree<int, int> tree;

		tree.Add(2, 20);
		tree.Add(7, 70);
		tree.Add(5, 50);
		tree.Add(6, 60);
		tree.Add(9, 90);
		tree.Add(11, 110);
		tree.Add(4, 40);

		V3DTest::AssertOk(tree.GetLength() == 7, V3DFILE_INFO);

		for (tree.First(); tree.IsDone(); tree.Next())
		{
			if (tree.GetCurrentKey() == 5)
				tree.RemoveCurrent();
		}

		int allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += *tree.GetCurrentItem();

		V3DTest::AssertOk((allNumbers == (20 + 70 + 60 + 90 + 110 + 40)), V3DFILE_INFO);

		tree.RemoveAll();

		tree.Add(4, 40);
		tree.Add(5, 50);
		tree.Add(6, 60);

		V3DTest::AssertOk(tree.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += *tree.GetCurrentItem();

		V3DTest::AssertOk((allNumbers == (40 + 50 + 60)), V3DFILE_INFO);

		tree.RemoveAll();
		tree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::AddRemoveStaticObjectKeyTest()
	{
		V3DDecimalTree<V3DString, int> tree;
		
		tree.Add(V3DString("two"), 2);
		tree.Add(V3DString("seven"), 7);
		tree.Add(V3DString("five"), 5);
		tree.Add(V3DString("six"), 6);
		tree.Add(V3DString("nine"), 9);
		tree.Add(V3DString("elevenTexture.jpg"), 11);
		tree.Add(V3DString("four"), 4);

		V3DTest::AssertOk(tree.GetLength() == 7, V3DFILE_INFO);

		for (tree.First(); tree.IsDone(); tree.Next())
		{
			if (tree.GetCurrentKey() == V3DString("five"))
				tree.RemoveCurrent();
		}

		int allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += *tree.GetCurrentItem();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 4)), V3DFILE_INFO);
		
		tree.RemoveAll();

		tree.Add(V3DString("four"), 40);
		tree.Add(V3DString("five"), 50);
		tree.Add(V3DString("six"), 60);

		V3DTest::AssertOk(tree.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += *tree.GetCurrentItem();

		V3DTest::AssertOk((allNumbers == (40 + 50 + 60)), V3DFILE_INFO);

		tree.RemoveAll();
		tree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::AddRemoveDynamicTest()
	{
		V3DTestObjectA::SetReferenceCounter(0);
		V3DDecimalTree<int, V3DTestObjectA*> tree;

		tree.Add(2, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 2));
		tree.Add(7, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 7));
		tree.Add(5, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		tree.Add(6, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));
		tree.Add(9, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 9));
		tree.Add(11, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11));
		tree.Add(44, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 44));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 7, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetLength() == 7, V3DFILE_INFO);

		for (tree.First(); tree.IsDone(); tree.Next())
			if (tree.GetCurrentKey() == 5)
			{
				V3DMemory::Delete(*tree.GetCurrentItem());
				tree.RemoveCurrent();
			}

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 6, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetLength() == 6, V3DFILE_INFO);

		auto allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += tree.GetCurrentKey();

		V3DTest::AssertOk((allNumbers == (2 + 7 + 6 + 9 + 11 + 44)), V3DFILE_INFO);

		for (tree.First(); tree.IsDone(); tree.Next())
			V3DMemory::Delete(*tree.GetCurrentItem());

		tree.RemoveAll();

		tree.Add(44, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 44));
		tree.Add(5, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 5));
		tree.Add(6, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 6));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetLength() == 3, V3DFILE_INFO);

		allNumbers = 0;
		for (tree.First(); tree.IsDone(); tree.Next())
			allNumbers += tree.GetCurrentKey();

		V3DTest::AssertOk((allNumbers == (44 + 5 + 6)), V3DFILE_INFO);

		for (tree.First(); tree.IsDone(); tree.Next())
			V3DMemory::Delete(*tree.GetCurrentItem());

		tree.RemoveAll();
		tree.~V3DDecimalTree();
		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 0, V3DFILE_INFO);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::RemoveAtTest()
	{
		V3DDecimalTree<V3DString, int> tree;

		tree.Add(V3DString("five"), 5);
		tree.Add(V3DString("nine"), 9);
		tree.Add(V3DString("elevenTexture.jpg"), 11);

		V3DTest::AssertOk(tree.GetItem(V3DString("five")) != nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetItem(V3DString("nine")) != nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetItem(V3DString("elevenTexture.jpg")) != nullptr, V3DFILE_INFO);

		V3DTest::AssertOk(tree.RemoveAt(V3DString("five")), V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetItem(V3DString("five")) == nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetLength() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetItem(V3DString("nine")) != nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(tree.GetItem(V3DString("elevenTexture.jpg")) != nullptr, V3DFILE_INFO);
		V3DTest::AssertOk(tree.RemoveAt(V3DString("five")) == false, V3DFILE_INFO);

		V3DTest::AssertOk(*tree.GetItem(V3DString("nine")) == 9, V3DFILE_INFO);
		V3DTest::AssertOk(*tree.GetItem(V3DString("elevenTexture.jpg")) == 11, V3DFILE_INFO);

		V3DTestObjectA::SetReferenceCounter(0);
		V3DDecimalTree<int, V3DTestObjectA*> treeDynamic;

		treeDynamic.Add(11, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 11));
		treeDynamic.Add(44, V3DMemory::New<V3DTestObjectA>(V3DFILE_INFO, 44));

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 2, V3DFILE_INFO);
		auto item = *treeDynamic.GetItem(11);
		treeDynamic.RemoveAt(11);
		V3DMemory::Delete(item);

		V3DTest::AssertOk(V3DTestObjectA::GetReferenceCounter() == 1, V3DFILE_INFO);
		V3DTest::AssertOk(treeDynamic.GetLength() == 1, V3DFILE_INFO);
	}

	void V3DDecimalTreeTests::RunAllTests()
	{
		CtorDtorTest();
		AddGetDataTest();
		AddRemoveStaticTest();
		AddRemoveStaticObjectKeyTest();
		AddRemoveDynamicTest();
		RemoveAtTest();

		//a modulos osztás helyett sima osztásra optimalizálni majd a hsashelés
		//a next-nél 'yield return'-szerűség kéne, mert így n * logn a bejárás, elég lassú
	}
}
