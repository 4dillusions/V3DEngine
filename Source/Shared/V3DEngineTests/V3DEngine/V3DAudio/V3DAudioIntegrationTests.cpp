/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAudioIntegrationTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"
#include "V3DEngine/V3DAudio/V3DAudioSystem.h"
#include "V3DEngine/V3DAudio/V3DSoundAsset.h"
#include "V3DEngine/V3DAsset/V3DAssetManager.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogMessageType.h"

#include <thread>
#include <chrono>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DAudio;
using namespace V3D::V3DEngine::V3DAsset;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	void V3DAudioIntegrationTests::InitAudioTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------InitAudioTest--------------------------");
				V3DIAudioSystem* audio = V3DIoc<V3DIAudioSystem>::CreateTransient();
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::LoadAssetTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------LoadAssetTest--------------------------");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "mysound.wav");
			});
	}

	void V3DAudioIntegrationTests::PlaySFXAudioTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------PlaySFXAudioTest--------------------------");

				//reload again
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "mysound.wav");

				//play it
				V3DIAudioSystem* audio = V3DIoc<V3DIAudioSystem>::CreateTransient();
				audio->PlayMusic("mysound.wav");
				
				std::this_thread::sleep_for(std::chrono::milliseconds(3000));
				V3DIoc<V3DAssetManager>::GetSingleton()->UnloadAll(); //have to unload assets before release AudioSystem
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::RunAllTests()
	{
		InitAudioTest();
		LoadAssetTest();
		PlaySFXAudioTest();
	}
}
