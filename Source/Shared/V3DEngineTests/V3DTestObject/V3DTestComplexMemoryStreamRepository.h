/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DIStreamRepository.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DMemoryStream;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestComplexData;
	
    class V3DTestComplexMemoryStreamRepository final : public V3D::V3DEngine::V3DData::V3DIStreamRepository<V3DTestComplexData, V3D::V3DEngine::V3DIO::V3DMemoryStream>
    {
    public:
		void ReadDataFromStream(V3D::V3DEngine::V3DIO::V3DMemoryStream& stream, V3DTestComplexData& dataOut) const override;
		void WriteDataToStream(const V3DTestComplexData& data, V3D::V3DEngine::V3DIO::V3DMemoryStream& streamOut) const override;
    };
}
