/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAudioSystem.h"
#include "ThirdParty/SoLoud/soloud.h"
#include "ThirdParty/SoLoud/soloud_wav.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DIO/V3DLogMessageType.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DAudio
{
	V3DAudioSystem::V3DAudioSystem() : sfxSource{ nullptr }
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
			log += soloudSystem->getErrorString(result);
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, log);
		}
	}

	V3DAudioSystem::~V3DAudioSystem()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Release SoLoud AudioSystem");

		soloudSystem->deinit();
		V3DMemory::Delete(sfxSource);
		V3DMemory::Delete(soloudSystem);
	}

	void V3DAudioSystem::SetMusicEnable(bool isEnabled) const
	{ }

	bool V3DAudioSystem::GetMusicEnable() const
	{
		return false;
	}

	void V3DAudioSystem::SetSFXEnable(bool isEnabled) const
	{ }

	bool V3DAudioSystem::GetSFXEnable() const
	{
		return false;
	}

	void V3DAudioSystem::LoadSound(const char* soundName)
	{
		sfxSource = V3DMemory::New<SoLoud::Wav>(V3DFILE_INFO);

		unsigned int lenght = 0;
		auto soundData = V3DBinaryRW::Read(V3DAssetPathType::Sound, "mysound.wav", &lenght);

		if (const auto result = dynamic_cast<SoLoud::Wav*>(sfxSource)->loadMem(reinterpret_cast<const unsigned char*>(soundData), lenght, true); result != SoLoud::SO_NO_ERROR)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, V3DString("Couldn't load sound: ") + soundName + " " + soloudSystem->getErrorString(result));

		V3DMemory::DeleteArray(soundData);
	}

	void V3DAudioSystem::PlayMusic(const char* soundName) const
	{ }

	void V3DAudioSystem::StopMusic() const
	{ }

	void V3DAudioSystem::PlaySFX(const char* soundName) const
	{
		soloudSystem->play(*sfxSource);
	}
}
