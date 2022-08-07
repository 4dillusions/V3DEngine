/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DDecimalTree.h"

namespace V3D::V3DEngine::V3DAsset
{
	class V3DAssetBase;

	class V3DENGINE_API V3DAssetManager final
    {
	    V3DCollections::V3DDecimalTree<int, V3DAssetBase*> assets;

        bool Load(bool isStatic, V3DAssetBase* asset, V3DCore::V3DAssetPathType path, const char* name);

    public:
        V3DAssetManager();
        V3DAssetManager(const V3DAssetManager&) = delete;
        V3DAssetManager(V3DAssetManager&&) = delete;
        ~V3DAssetManager();
        V3DAssetManager& operator=(const V3DAssetManager&) = delete;
        V3DAssetManager& operator=(V3DAssetManager&&) = delete;

        template<typename TAsset> bool Load(bool isStatic, V3DCore::V3DAssetPathType path, const char* name)
        {
            if (GetAsset(name))
                return true;

            return Load(isStatic, V3DCore::V3DMemory::New<TAsset>(V3DFILE_INFO), path, name);
        }

        V3DAssetBase* GetAsset(const char* name);
        
        void UnloadAll();
        void UnloadAll(bool isStatic);
    };
}
