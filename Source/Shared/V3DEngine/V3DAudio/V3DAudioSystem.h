/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DIAudioSystem.h"
#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DAsset
{
	class V3DAssetManager;
}

namespace SoLoud
{
	class Soloud;
	class AudioSource;
}

namespace V3D::V3DEngine::V3DAudio
{
	class V3DSoundAsset;

	class V3DENGINE_API V3DAudioSystem final : public V3DIAudioSystem  // NOLINT padding size
	{
		V3DAsset::V3DAssetManager* assetManager;
		V3DSoundAsset* musicAsset{};

		SoLoud::Soloud* soloudSystem;

		bool isMusicEnable = true;
		bool isSFXEnable = true;
		
    public:
        explicit V3DAudioSystem(V3DAsset::V3DAssetManager* assetManager);
        V3DAudioSystem(const V3DAudioSystem&) = delete;
        V3DAudioSystem(V3DAudioSystem&&) = delete;
        ~V3DAudioSystem() override;
        V3DAudioSystem& operator=(const V3DAudioSystem&) = delete;
        V3DAudioSystem& operator=(V3DAudioSystem&&) = delete;

		void SetMusicEnable(bool isEnabled) override;
		bool GetMusicEnable() const override;
		
		void SetSFXEnable(bool isEnabled) override;
		bool GetSFXEnable() const override;
		
		void PlayMusic(const char* soundName) override;
		void StopMusic() const override;
		
		void PlaySFX(const char* soundName) const override;
    };
}
