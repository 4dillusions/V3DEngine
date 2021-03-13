/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    class V3DTestPlayerSqlModel
    {
        int id{};
        V3D::V3DEngine::V3DCore::V3DString name;

    public:
        V3DTestPlayerSqlModel() = default;
        explicit V3DTestPlayerSqlModel(const V3D::V3DEngine::V3DCore::V3DString& name);
        V3DTestPlayerSqlModel(int id, const V3D::V3DEngine::V3DCore::V3DString& name);

    	bool operator ==(const V3DTestPlayerSqlModel& value) const;
        bool operator !=(const V3DTestPlayerSqlModel& value) const;

        [[nodiscard]] int GetId() const;
        void SetId(int id);
        [[nodiscard]] V3D::V3DEngine::V3DCore::V3DString GetName() const;
        void SetName(const V3D::V3DEngine::V3DCore::V3DString& name);
        [[nodiscard]] bool GetIsValid() const;
    };
}
