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
        [[nodiscard]] const char* GetPlatformName() const override;
        [[nodiscard]] int GetWindowWidth() const override;
        [[nodiscard]] int GetWindowHeight() const override;
        [[nodiscard]] int GetScreenWidth() const override;
        [[nodiscard]] int GetScreenHeight() const override;
        [[nodiscard]] const char* GetAssetPath(V3DAssetPathType assetPath) const override;
    };
}
