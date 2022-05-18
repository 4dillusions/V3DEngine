/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppUnusedIncludeDirective
#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

namespace V3D::V3DEngine::V3DIO
{
    //definitions will be implement in platform specific .cpp
    class V3DENGINE_API V3DFile final
    {
    public:
        V3DFile() = delete;
        V3DFile(const V3DFile&) = delete;
        V3DFile(V3DFile&&) = delete;
        ~V3DFile() = delete;
        V3DFile& operator=(const V3DFile&) = delete;
        V3DFile& operator=(V3DFile&&) = delete;        

        static bool IsExist(V3DCore::V3DAssetPathType path, const char* fileName);
    	static long GetSize(V3DCore::V3DAssetPathType path, const char* fileName);
        static void Create(const char* fileName);
        static void Delete(const char* fileName);
    };
}
