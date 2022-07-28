/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DIAudioSystem.h"
#include "V3DEngine/V3DEngineLibrary.h"

namespace SoLoud
{
	class Soloud;
	class AudioSource;
}

namespace V3D::V3DEngine::V3DAudio
{
	class V3DENGINE_API V3DAudioSystem final : public V3DIAudioSystem  // NOLINT padding size
    {
		SoLoud::AudioSource* sfxSource;
		SoLoud::Soloud* soloudSystem;

		bool isMusicEnable = true;
		bool isSFXEnable = true;
		
    public:
        V3DAudioSystem();
        V3DAudioSystem(const V3DAudioSystem&) = delete;
        V3DAudioSystem(V3DAudioSystem&&) = delete;
        ~V3DAudioSystem() override;
        V3DAudioSystem& operator=(const V3DAudioSystem&) = delete;
        V3DAudioSystem& operator=(V3DAudioSystem&&) = delete;

		void SetMusicEnable(bool isEnabled) override;
		bool GetMusicEnable() const override;
		
		void SetSFXEnable(bool isEnabled) override;
		bool GetSFXEnable() const override;

		void LoadSound(const char* soundName) override;
		
		void PlayMusic(const char* soundName) const override;
		void StopMusic() const override;
		
		void PlaySFX(const char* soundName) const override;
    };
}
