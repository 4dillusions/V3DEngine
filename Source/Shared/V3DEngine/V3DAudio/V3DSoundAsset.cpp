/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DSoundAsset.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DAsset/V3DAssetData.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "ThirdParty/SoLoud/soloud_wav.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DAsset;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DAudio
{
	V3DSoundAsset::~V3DSoundAsset()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, V3DString("Release SoundAsset: ") + assetData->name);
		V3DMemory::Delete(audioSource);
	}

	bool V3DSoundAsset::GetIsBinary() const
	{
		return true;
	}
	
	const SoLoud::AudioSource* V3DSoundAsset::GetAudioSource() const
	{
		return audioSource;
	}

	void V3DSoundAsset::Load()
	{
		audioSource = V3DMemory::New<SoLoud::Wav>(V3DFILE_INFO);

		if (const auto result = dynamic_cast<SoLoud::Wav*>(audioSource)->loadMem(reinterpret_cast<const unsigned char*>(assetData->binaryData), assetData->binaryDataLenght, false, false); result != SoLoud::SO_NO_ERROR)
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, V3DString("Couldn't load sound: ") + assetData->name + " " + SoLoud::Soloud::getErrorString(result));
	}
}
