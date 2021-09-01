/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DIFileRepository.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    struct V3DTestSimpleData;

    class V3DTestSimpleFileRepository final : public V3D::V3DEngine::V3DData::V3DIFileRepository<V3DTestSimpleData>
    {
    public:
        V3DTestSimpleData Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName) const override;
        void Save(V3DTestSimpleData& data, const char* fileName) const override;
    };
}
