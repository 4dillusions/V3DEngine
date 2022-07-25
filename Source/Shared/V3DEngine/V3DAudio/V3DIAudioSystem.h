/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DAudio
{
	class V3DIAudioSystem
    {
    public:
        V3DIAudioSystem() = default;
        V3DIAudioSystem(const V3DIAudioSystem&) = default;
        V3DIAudioSystem(V3DIAudioSystem&&) = default;
        virtual ~V3DIAudioSystem() = default;
        V3DIAudioSystem& operator=(const V3DIAudioSystem&) = delete;
        V3DIAudioSystem& operator=(V3DIAudioSystem&&) = delete;

		virtual void SetMusicEnable(bool isEnabled) const = 0;
		virtual bool GetMusicEnable() const = 0;
		
		virtual void SetSFXEnable(bool isEnabled) const = 0;
		virtual bool GetSFXEnable() const = 0;

		virtual void LoadSound(const char* soundName) = 0;
		
		virtual void PlayMusic(const char* soundName) const = 0;
		virtual void StopMusic() const = 0;
		
		virtual void PlaySFX(const char* soundName) const = 0;
    };
}
