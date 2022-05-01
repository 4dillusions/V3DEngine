/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DISQLRepository.h"
#include "V3DEngine/V3DIO/V3DISQLContext.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    class V3DTestPlayerData;

    class V3DTestPlayerSqlRepository : public V3D::V3DEngine::V3DData::V3DISQLRepository<V3DTestPlayerData>
    {
        V3D::V3DEngine::V3DIO::V3DISQLContext* dbContext{};

    public:
        V3DTestPlayerSqlRepository(V3D::V3DEngine::V3DIO::V3DISQLContext* context);

	    V3DTestPlayerData Select(const V3DTestPlayerData& data) const override;
        bool Insert(V3DTestPlayerData& data) const override;
        bool Update(const V3DTestPlayerData& data) const override;
	    bool Delete(const V3DTestPlayerData& data) const override;
	    bool DeleteAll() const override;
    };
}
