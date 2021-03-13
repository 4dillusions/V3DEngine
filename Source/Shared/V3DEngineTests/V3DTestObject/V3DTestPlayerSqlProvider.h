/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTestPlayerSqlModel.h"

namespace V3D::V3DEngine::V3DIO
{
    class V3DSQLiteContext;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
    class V3DTestPlayerSqlProvider
    {
        V3D::V3DEngine::V3DIO::V3DSQLiteContext* db{};

    public:
        explicit V3DTestPlayerSqlProvider(V3D::V3DEngine::V3DIO::V3DSQLiteContext* db);

	    V3DTestPlayerSqlModel Select(V3DTestPlayerSqlModel& model) const;
        bool Insert(V3DTestPlayerSqlModel& model) const;
        bool Update(V3DTestPlayerSqlModel& model) const;
	    [[nodiscard]] bool Delete(int id) const;
	    [[nodiscard]] bool DeleteAll() const;
    };
}
