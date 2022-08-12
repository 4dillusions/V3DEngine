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
	void V3DAudioIntegrationTests::InitAudioIntegrationTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------InitAudioTest--------------------------");
				V3DIAudioSystem* audio = V3DIoc<V3DIAudioSystem>::CreateTransient();
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::LoadAssetIntegrationTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------LoadAssetTest--------------------------");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "mysound.wav");
			});
	}

	void V3DAudioIntegrationTests::PlaySFXAudioIntegrationTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------PlaySFXAudioTest--------------------------");

				//reload again
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "mysound.wav");

				//play a test sfx
				V3DIAudioSystem* audio = V3DIoc<V3DIAudioSystem>::CreateTransient();
				audio->PlaySFX("mysound.wav");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));

				//release
				V3DIoc<V3DAssetManager>::GetSingleton()->UnloadAll(); //have to unload assets before release AudioSystem
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::AudioStressIntegrationTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				//init
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------AudioStressTest--------------------------");
				V3DIAudioSystem* audio = V3DIoc<V3DIAudioSystem>::CreateTransient();

				V3DIoc<V3DAssetManager>::GetSingleton()->UnloadAll();

				////Menu screen
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------MenuScreen");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(true, V3DAssetPathType::Sound, "MenuMusic.ogg");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(true, V3DAssetPathType::Sound, "MenuClick.wav");

				audio->PlayMusic("MenuMusic.ogg");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				for (int i = 0; i < 5; i++)
				{
					audio->PlaySFX("MenuClick.wav");
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));

				////Level1 screen
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------Level1 screen");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level1PickUp.wav");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level1Break.wav");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level1Music.ogg");

				audio->PlayMusic("Level1Music.ogg");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				for (int i = 0; i < 5; i++)
				{
					audio->PlaySFX("Level1PickUp.wav");
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					audio->PlaySFX("Level1Break.wav");
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));

				////Menu screen
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------MenuScreen");
				audio->PlayMusic("MenuMusic.ogg");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				audio->PlaySFX("MenuClick.wav");
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));

				////Level2 screen
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------Level2 screen");
				V3DIoc<V3DAssetManager>::GetSingleton()->UnloadAll(false);
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level2Bang.wav");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level2Growl.wav");
				V3DIoc<V3DAssetManager>::GetSingleton()->Load<V3DSoundAsset>(false, V3DAssetPathType::Sound, "Level2Music.ogg");

				audio->PlayMusic("Level2Music.ogg");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				for (int i = 0; i < 5; i++)
				{
					audio->PlaySFX("Level2Growl.wav");
					std::this_thread::sleep_for(std::chrono::milliseconds(500));
					audio->PlaySFX("Level2Bang.wav");
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));

				////Menu screen
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------MenuScreen");
				audio->PlayMusic("MenuMusic.ogg");
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				audio->PlaySFX("MenuClick.wav");
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));

				//release
				V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "--------------------------release");
				V3DIoc<V3DAssetManager>::GetSingleton()->UnloadAll();
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::RunAllUnitTests()
	{
	}

	void V3DAudioIntegrationTests::RegisterIntegrationTests()
	{
		InitAudioIntegrationTest();
		LoadAssetIntegrationTest();
		PlaySFXAudioIntegrationTest();
		AudioStressIntegrationTest();
	}

	void V3DAudioIntegrationTests::RegisterTimingTests()
	{
	}
}
