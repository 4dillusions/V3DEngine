/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DIFileRepository.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    struct V3DTestComplexData;

    class V3DTestComplexFileRepository final : public V3D::V3DEngine::V3DData::V3DIFileRepository<V3DTestComplexData*>
    {
    public:
        V3DTestComplexData* Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName) const override;
        void Save(V3DTestComplexData*& data, const char* fileName) const override;
    };
}
