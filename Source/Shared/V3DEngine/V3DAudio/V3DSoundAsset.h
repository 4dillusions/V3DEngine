/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DAsset/V3DAssetBase.h"

namespace SoLoud
{
	class AudioSource;
}

namespace V3D::V3DEngine::V3DAsset
{
    class V3DAssetManager;
}

namespace V3D::V3DEngine::V3DAudio
{
	class V3DENGINE_API V3DSoundAsset final : public V3DAsset::V3DAssetBase
    {
		SoLoud::AudioSource* audioSource{};

    public:
        V3DSoundAsset() = default;
        V3DSoundAsset(const V3DSoundAsset&) = delete;
        V3DSoundAsset(V3DSoundAsset&&) = delete;
        ~V3DSoundAsset() override;
        V3DSoundAsset& operator=(const V3DSoundAsset&) = delete;
        V3DSoundAsset& operator=(V3DSoundAsset&&) = delete;

		bool GetIsBinary() const override;
		const SoLoud::AudioSource* GetAudioSource() const;

        void Load() override;
    };
}
