/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
    class V3DString;
}

namespace V3D::V3DEngine::V3DData
{
    class V3DENGINE_API V3DAppDataSecurity final
    {
    public:
        V3DAppDataSecurity() = delete;
        V3DAppDataSecurity(const V3DAppDataSecurity&) = delete;
        V3DAppDataSecurity(V3DAppDataSecurity&&) = delete;
        ~V3DAppDataSecurity() = delete;
        V3DAppDataSecurity& operator=(const V3DAppDataSecurity&) = delete;
        V3DAppDataSecurity& operator=(V3DAppDataSecurity&&) = delete;
        
        static bool GetIsAllAppDataValid(const V3D::V3DEngine::V3DCore::V3DString& key, const V3D::V3DEngine::V3DCore::V3DString& validHash);
    };
}