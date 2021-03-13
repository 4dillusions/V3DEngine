/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DAssetPathType.h"
#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngine::V3DCore
{
    class V3DEnvironment;
}

namespace V3D::V3DEngine::V3DIO
{
    class V3DENGINE_API V3DFolder final
    {
        static V3DCore::V3DEnvironment* GetEnvironment();
    	
    public:
        V3DFolder() = delete;
        V3DFolder(const V3DFolder&) = delete;
        V3DFolder(V3DFolder&&) = delete;
        ~V3DFolder() = delete;
        V3DFolder& operator=(const V3DFolder&) = delete;
        V3DFolder& operator=(V3DFolder&&) = delete;        

        static bool IsExist(V3DCore::V3DAssetPathType path);
        static V3DCollections::V3DDynamicArray<V3DCore::V3DString> GetFileList(V3DCore::V3DAssetPathType path);
    };
}
