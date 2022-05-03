/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DIFileRepository.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
    template<typename TData> class V3DTestSimpleFileRepository final : public V3D::V3DEngine::V3DData::V3DIFileRepository<TData>
    {
    public:
        TData Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName) const override
        {
            auto data = reinterpret_cast<TData*>(V3D::V3DEngine::V3DIO::V3DBinaryRW::Read(path, fileName));
            const TData result = *data;
            V3D::V3DEngine::V3DCore::V3DMemory::DeleteArray(data);

            return result;
        }
        
        void Save(TData& data, const char* fileName) const override
        {
	        V3D::V3DEngine::V3DIO::V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(&data), sizeof(TData));
        }
    };

    template<typename TData> class V3DTestSimpleFileRepository<TData*> final : public V3D::V3DEngine::V3DData::V3DIFileRepository<TData*>
    {
    public:
        TData* Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName) const override
        {
            return reinterpret_cast<TData*>(V3D::V3DEngine::V3DIO::V3DBinaryRW::Read(path, fileName));
        }

        void Save(TData*& data, const char* fileName) const override
        {
            V3D::V3DEngine::V3DIO::V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(data), sizeof(TData));
        }
    };
}
