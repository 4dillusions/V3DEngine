/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DAbstractEnvironment.h"
#include "V3DEngine/V3DGameEngine.h"

namespace V3D::V3DEngine::V3DCore
{
    class V3DENGINE_API V3DEnvironment final : public V3DAbstractEnvironment
    {
    public:
        const char* GetPlatformName() const override;
        int GetWindowWidth() const override;
        int GetWindowHeight() const override;
        int GetScreenWidth() const override;
        int GetScreenHeight() const override;
        const char* GetAssetPath(V3DAssetPathType assetPath) const override;
    };
}
