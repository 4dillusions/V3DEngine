/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DISQLRepository.h"

namespace V3D::V3DEngine::V3DIO
{
    class V3DSQLiteContext;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
    struct V3DTestPlayerData;

    class V3DTestPlayerSqlRepository : public V3D::V3DEngine::V3DData::V3DISQLRepository<V3DTestPlayerData>
    {
        V3D::V3DEngine::V3DIO::V3DSQLiteContext* db{};

    public:
        V3DTestPlayerSqlRepository();

	    V3DTestPlayerData Select(const V3DTestPlayerData& data) const override;
        bool Insert(V3DTestPlayerData& data) const override;
        bool Update(const V3DTestPlayerData& data) const override;
	    bool Delete(const V3DTestPlayerData& data) const override;
	    bool DeleteAll() const override;
    };
}
