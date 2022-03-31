/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestComplexFileRepository.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

#include "V3DTestComplexData.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestComplexData* V3DTestComplexFileRepository::Load(V3DAssetPathType path, const char* fileName) const
	{
		const auto result = V3DMemory::New<V3DTestComplexData>(V3DFILE_INFO);

		result->dataStream = V3DBinaryRW::Read(path, fileName);
		auto currentDataStream = result->dataStream;
		result->head = reinterpret_cast<V3DTestComplexDataHead*>(currentDataStream);

		const V3DTestComplexData::DataSize dataSize(result->head);

		currentDataStream += dataSize.HeadSize;
		result->vertices = reinterpret_cast<float*>(currentDataStream);

		currentDataStream += dataSize.VerticeSize;
		result->uvs = reinterpret_cast<int*>(currentDataStream);
		
		return result;
	}
	
	void V3DTestComplexFileRepository::Save(V3DTestComplexData*& data, const char* fileName) const
	{
		const V3DTestComplexData::DataSize dataSize(data->head);

		unsigned long long offset = 0;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(data->head), dataSize.HeadSize, offset);

		offset += dataSize.HeadSize;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(data->vertices), dataSize.VerticeSize, offset);

		offset += dataSize.VerticeSize;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(data->uvs), dataSize.UvSize, offset);
	}
}
