/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"
#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngine::V3DCore
{
    class V3DEnvironment;
}

namespace V3D::V3DEngine::V3DIO
{
    /*
        Raw text read/write from/to file
        It's not enable continuos writing
    */
    class V3DENGINE_API V3DTextRW final
    {
        static V3DCore::V3DEnvironment* GetEnvironment();
        
    public:
        V3DTextRW() = delete;
        V3DTextRW(const V3DTextRW&) = delete;
        V3DTextRW(V3DTextRW&&) = delete;
        ~V3DTextRW() = delete;
        V3DTextRW& operator=(const V3DTextRW&) = delete;
        V3DTextRW& operator=(V3DTextRW&&) = delete;        

        static V3DCore::V3DString Read(V3DCore::V3DAssetPathType path, const char* fileName);
        static void Write(const char* fileName, const V3DCore::V3DString& text);
    };
}
