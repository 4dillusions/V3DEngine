/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    class V3DTestPlayerData
    {
        int id{};
        V3D::V3DEngine::V3DCore::V3DString name;

    public:
        V3DTestPlayerData() = default;
        explicit V3DTestPlayerData(V3D::V3DEngine::V3DCore::V3DString name);
        V3DTestPlayerData(int id, V3D::V3DEngine::V3DCore::V3DString name);

    	bool operator ==(const V3DTestPlayerData& value) const;
        bool operator !=(const V3DTestPlayerData& value) const;

        int GetId() const;
        void SetId(int idValue);
        V3D::V3DEngine::V3DCore::V3DString GetName() const;
        void SetName(const V3D::V3DEngine::V3DCore::V3DString& nameValue);
        bool GetIsValid() const;
    };
}
