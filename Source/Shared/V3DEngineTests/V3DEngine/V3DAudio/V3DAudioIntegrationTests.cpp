/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAudioIntegrationTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DAudio/V3DAudioSystem.h"

#include <thread>
#include <chrono>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DAudio;

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	void V3DAudioIntegrationTests::InitAudioTest()
	{
		V3DTest::AddIntegrationTest(
				[&]
				{
					V3DIAudioSystem* audio = V3DMemory::New<V3DAudioSystem>(V3DFILE_INFO);
					V3DMemory::Delete(audio);
				});
	}

	void V3DAudioIntegrationTests::PlaySFXAudioTest()
	{
		V3DTest::AddIntegrationTest(
			[&]
			{
				V3DIAudioSystem* audio = V3DMemory::New<V3DAudioSystem>(V3DFILE_INFO);

				audio->LoadSound("");
				audio->PlaySFX("");

				std::this_thread::sleep_for(std::chrono::milliseconds(6000));
				V3DMemory::Delete(audio);
			});
	}

	void V3DAudioIntegrationTests::RunAllTests()
	{
		InitAudioTest();
		PlaySFXAudioTest();
	}
}
