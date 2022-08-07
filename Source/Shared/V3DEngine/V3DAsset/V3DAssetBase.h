/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DAsset
{
	struct V3DAssetData;

	class V3DENGINE_API V3DAssetBase
    {
	protected:
        V3DAssetData* assetData{};

    public:
        V3DAssetBase() = default;
        V3DAssetBase(const V3DAssetBase&) = delete;
        V3DAssetBase(V3DAssetBase&&) = delete;
        virtual ~V3DAssetBase();
        V3DAssetBase& operator=(const V3DAssetBase&) = delete;
        V3DAssetBase& operator=(V3DAssetBase&&) = delete;

        bool GetIsStatic() const;
		virtual bool GetIsBinary() const = 0;
        virtual void Load() = 0;

		void SetAssetData(V3DAssetData* asset);
    };
}
