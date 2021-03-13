/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DComponentTest.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngineTests/V3DTestObject/V3DTestSprite.h"
#include "V3DEngineTests/V3DTestObject/V3DTestGameComponent.h"
#include "V3DEngineTests/V3DTestObject/V3DTestLayer.h"
#include "V3DEngineTests/V3DTestObject/V3DTestLayerPool.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

namespace V3D::V3DEngineTests::V3DEngine::V3DCore
{
	void V3DComponentTest::GameComponentTest()
	{
		const V3DTestGameComponent Comp, Comp2;
		V3DTest::AssertOk(Comp.GetId() != Comp2.GetId(), V3DFILE_INFO);
		//V3DTest::AssertOk(Comp < Comp2, V3DFILE_INFO);
		V3DTest::AssertOk(Comp != Comp2, V3DFILE_INFO);
		V3DTest::AssertOk(Comp == *&Comp, V3DFILE_INFO);

		const V3DTestGameComponent Comp3{"comp3"}, Comp4{"comp3"};
		V3DTest::AssertOk(Comp3 != Comp4, V3DFILE_INFO);
		V3DTest::AssertOk(V3DString(Comp3.GetName()) == V3DString(Comp4.GetName()), V3DFILE_INFO);
	}

	void V3DComponentTest::GameCompositeComponentTest()
	{
		auto gameLayer = V3DMemory::New<V3DTestLayer>(V3DFILE_INFO, "GameLayer");

		auto sprite1 = V3DMemory::New<V3DTestSprite>(V3DFILE_INFO, "Sprite1");
		auto sprite2 = V3DMemory::New<V3DTestSprite>(V3DFILE_INFO, "Sprite2");
		const auto Sprite3 = V3DMemory::New<V3DTestSprite>(V3DFILE_INFO, "Sprite3");
		const auto Sprite4 = V3DMemory::New<V3DTestSprite>(V3DFILE_INFO, "Sprite4");
		const auto Sprite5 = V3DMemory::New<V3DTestSprite>(V3DFILE_INFO, "Sprite5");

		gameLayer->Add(sprite1);
		gameLayer->Add(sprite2);
		gameLayer->Add(Sprite3);
		gameLayer->Add(Sprite4);
		gameLayer->Add(Sprite5);
		gameLayer->Add(sprite1);

		V3DTest::AssertOk(*gameLayer->Find(Sprite3) == *Sprite3, V3DFILE_INFO);
		V3DTest::AssertOk(*gameLayer->Find("Sprite4") == *Sprite4, V3DFILE_INFO);
		
		V3DTestSprite::componentUpdate = 0;
		gameLayer->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 5, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayer->GetComponentsLength() == 5, V3DFILE_INFO);

		V3DTestSprite::componentUpdate = 0;
		sprite1->SetIsAlive(false);
		gameLayer->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 4, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayer->GetComponentsLength() == 4, V3DFILE_INFO);
		
		V3DTestSprite::componentUpdate = 0;
		gameLayer->Delete(Sprite4);
		gameLayer->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 3, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayer->GetComponentsLength() == 3, V3DFILE_INFO);

		V3DTestSprite::componentUpdate = 0;
		gameLayer->Remove(sprite2);
		gameLayer->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 2, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayer->GetComponentsLength() == 2, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayer->Find(sprite2) == nullptr, V3DFILE_INFO);

		V3DMemory::Delete(gameLayer);
		V3DMemory::Delete(sprite2);
		V3DTest::AssertOk(V3DMemory::GetMemoryLeakCount() == 0, V3DFILE_INFO);
	}

	void V3DComponentTest::GameCompositeComponentPoolTest()
	{
		auto gameLayerPool = V3DMemory::New<V3DTestLayerPool>(V3DFILE_INFO, "GameLayerPool", 5);

		auto sprite1 = gameLayerPool->Add();
		const auto Sprite2 = gameLayerPool->Add();
		const auto Sprite3 = gameLayerPool->Add();
		gameLayerPool->Add();
		gameLayerPool->Add();

		V3DTest::AssertOk(*gameLayerPool->Find(Sprite3) == *Sprite3, V3DFILE_INFO);

		V3DTestSprite::componentUpdate = 0;
		gameLayerPool->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 5, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayerPool->GetComponentsLength() == 5, V3DFILE_INFO);

		V3DTestSprite::componentUpdate = 0;
		sprite1->SetIsAlive(false);
		gameLayerPool->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 4, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayerPool->GetComponentsLength() == 4, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayerPool->Find(sprite1) == nullptr, V3DFILE_INFO);

		V3DTestSprite::componentUpdate = 0;
		gameLayerPool->Remove(Sprite2);
		gameLayerPool->Update(1);
		V3DTest::AssertOk(V3DTestSprite::componentUpdate == 3, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayerPool->GetComponentsLength() == 3, V3DFILE_INFO);
		V3DTest::AssertOk(gameLayerPool->Find(Sprite2) == nullptr, V3DFILE_INFO);

		V3DMemory::Delete(gameLayerPool);
	}
	
	void V3DComponentTest::RunAllTests()
	{
		GameComponentTest();
		GameCompositeComponentTest();
		GameCompositeComponentPoolTest();
	}
}
