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
    /*
        Binary stream (char*) read/write from/to file
        It enables continuos writing

        definitions will be implement in platform specific .cpp
    */
    class V3DENGINE_API V3DBinaryRW final
    {
    public:
        V3DBinaryRW() = delete;
        V3DBinaryRW(const V3DBinaryRW&) = delete;
        V3DBinaryRW(V3DBinaryRW&&) = delete;
        ~V3DBinaryRW() = delete;
        V3DBinaryRW& operator=(const V3DBinaryRW&) = delete;
        V3DBinaryRW& operator=(V3DBinaryRW&&) = delete;        

        static char* Read(V3DCore::V3DAssetPathType path, const char* fileName);
        static void Write(const char* fileName, const char* data, long size, long offset = 0);
    };
}
