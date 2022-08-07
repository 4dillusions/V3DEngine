/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAudioSystem.h"
#include "V3DSoundAsset.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogMessageType.h"
#include "V3DEngine/V3DAsset/V3DAssetManager.h"
#include "ThirdParty/SoLoud/soloud.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DAsset;

namespace V3D::V3DEngine::V3DAudio
{
	V3DAudioSystem::V3DAudioSystem(V3DAssetManager* assetManager) : assetManager{ assetManager }
	{
		soloudSystem = V3DMemory::New<SoLoud::Soloud>(V3DFILE_INFO);
		const auto result = soloudSystem->init();

		V3DString log;
		log += "Init SoLoud AudioSystem: ";
		if (result == SoLoud::SO_NO_ERROR)
		{
			log += soloudSystem->getBackendString();
			log += " backend";
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, log);
		}
		else
		{
			log += SoLoud::Soloud::getErrorString(result);
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, log);
		}
	}

	V3DAudioSystem::~V3DAudioSystem()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Release SoLoud AudioSystem");

		soloudSystem->deinit();
		V3DMemory::Delete(soloudSystem);
	}

	void V3DAudioSystem::SetMusicEnable(bool isEnabled)
	{
		isMusicEnable = isEnabled;

		if (!isEnabled)
			StopMusic();
	}

	bool V3DAudioSystem::GetMusicEnable() const
	{
		return isMusicEnable;
	}

	void V3DAudioSystem::SetSFXEnable(bool isEnabled)
	{
		isSFXEnable = isEnabled;
	}

	bool V3DAudioSystem::GetSFXEnable() const
	{
		return isSFXEnable;
	}
	
	void V3DAudioSystem::PlayMusic(const char* soundName)
	{
		if (isMusicEnable)
		{
			if ((musicAsset = dynamic_cast<V3DSoundAsset*>(assetManager->GetAsset(soundName))))
				soloudSystem->play(*const_cast<SoLoud::AudioSource*>(musicAsset->GetAudioSource()));
		}
	}

	void V3DAudioSystem::StopMusic() const
	{
		if (musicAsset != nullptr)
			soloudSystem->stopAudioSource(*const_cast<SoLoud::AudioSource*>(musicAsset->GetAudioSource()));
	}

	void V3DAudioSystem::PlaySFX(const char* soundName) const
	{
		if (isSFXEnable)
		{
			if (const auto sfxAsset = dynamic_cast<V3DSoundAsset*>(assetManager->GetAsset(soundName)))
				soloudSystem->play(*const_cast<SoLoud::AudioSource*>(sfxAsset->GetAudioSource()));
		}
	}
}
