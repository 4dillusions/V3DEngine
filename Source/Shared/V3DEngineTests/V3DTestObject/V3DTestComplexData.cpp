/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestComplexData.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestComplexData::V3DTestComplexData(const V3DTestComplexDataHead& dataHead)
	{
		head = V3DMemory::New<V3DTestComplexDataHead>(V3DFILE_INFO, dataHead.verticeCount, dataHead.uvCount);
		vertices = V3DMemory::NewArray<float>(V3DFILE_INFO, head->verticeCount);
		uvs = V3DMemory::NewArray<int>(V3DFILE_INFO, head->uvCount);
	}
	
	V3DTestComplexData::~V3DTestComplexData()
	{
		if (dataStream == nullptr)
		{
			V3DMemory::Delete(head);
			V3DMemory::DeleteArray(vertices);
			V3DMemory::DeleteArray(uvs);
		}
		else
			V3DMemory::DeleteArray(dataStream);
	}

	unsigned int V3DTestComplexData::GetSize() const
	{
		const DataSize dataSize(head);

		return dataSize.HeadSize + dataSize.VerticeSize + dataSize.UvSize;
	}
}
