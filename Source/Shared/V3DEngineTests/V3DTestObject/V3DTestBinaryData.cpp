/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestBinaryData.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DMemoryStream.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestBinaryData::V3DTestBinaryData(const V3DTestBinaryDataHead& dataHead)
	{
		head = V3DMemory::New<V3DTestBinaryDataHead>(V3DFILE_INFO, dataHead.verticeCount, dataHead.uvCount);
		vertices = V3DMemory::NewArray<float>(V3DFILE_INFO, head->verticeCount);
		uvs = V3DMemory::NewArray<int>(V3DFILE_INFO, head->uvCount);
	}
	
	V3DTestBinaryData::~V3DTestBinaryData()
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

	unsigned long long V3DTestBinaryData::GetSize() const
	{
		const DataSize dataSize(head);

		return dataSize.HeadSize + dataSize.VerticeSize + dataSize.UvSize;
	}

	void V3DTestBinaryData::Load(V3DAssetPathType path, const char* fileName)
	{
		dataStream = V3DBinaryRW::Read(path, fileName);
		auto currentDataStream = dataStream;
		head = reinterpret_cast<V3DTestBinaryDataHead*>(currentDataStream);

		const DataSize dataSize(head);

		currentDataStream += dataSize.HeadSize;
		vertices = reinterpret_cast<float*>(currentDataStream);

		currentDataStream += dataSize.VerticeSize;
		uvs = reinterpret_cast<int*>(currentDataStream);
	}

	void V3DTestBinaryData::Load(V3DMemoryStream& stream)
	{
		head = V3DMemory::New<V3DTestBinaryDataHead>(V3DFILE_INFO);
		stream.Read(*head);

		vertices = V3DMemory::NewArray<float>(V3DFILE_INFO, head->verticeCount);
		for (int i = 0; i < head->verticeCount; i++)
			stream.Read(vertices[i]);

		uvs = V3DMemory::NewArray<int>(V3DFILE_INFO, head->uvCount);
		for (int i = 0; i < head->uvCount; i++)
			stream.Read(uvs[i]);
	}
	
	void V3DTestBinaryData::Save(const char* fileName) const
	{
		const DataSize dataSize(head);

		unsigned long long offset = 0;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(head), dataSize.HeadSize, offset);

		offset += dataSize.HeadSize;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(vertices), dataSize.VerticeSize, offset);

		offset += dataSize.VerticeSize;
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(uvs), dataSize.UvSize, offset);
	}

	void V3DTestBinaryData::Save(V3D::V3DEngine::V3DIO::V3DMemoryStream& streamOut) const
	{
		streamOut.Write(*head);

		for (int i = 0; i < head->verticeCount; i++)
			streamOut.Write(vertices[i]);

		for (int i = 0; i < head->uvCount; i++)
			streamOut.Write(uvs[i]);
	}
}
