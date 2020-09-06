/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

namespace V3D::V3DEngine::V3DCore
{
    class V3DEnvironment;
}

namespace V3D::V3DEngine::V3DIO
{
    class V3DLogger;
	
    /*
        Binary stream (char*) read/write from/to file
        It enables continuos writing
    */
    class V3DENGINE_API V3DBinaryRW final
    {
        static V3DCore::V3DEnvironment* GetEnvironment();
        static V3DLogger* GetLogger();
    	
    public:
        V3DBinaryRW() = delete;
        V3DBinaryRW(const V3DBinaryRW&) = delete;
        V3DBinaryRW(V3DBinaryRW&&) = delete;
        ~V3DBinaryRW() = delete;
        V3DBinaryRW& operator=(const V3DBinaryRW&) = delete;
        V3DBinaryRW& operator=(V3DBinaryRW&&) = delete;        

        static char* Read(V3DCore::V3DAssetPathType path, const char* fileName);
        static void Write(const char* fileName, char* data, unsigned long long size, unsigned long long offset = 0);
    };
}
