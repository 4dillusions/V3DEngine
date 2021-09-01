/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestComplexMemoryStreamRepository.h"
#include "V3DEngine/V3DIO/V3DMemoryStream.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

#include "V3DTestComplexData.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	void V3DTestComplexMemoryStreamRepository::ReadDataFromStream(V3DMemoryStream& stream, V3DTestComplexData& dataOut) const
	{
		dataOut.head = V3DMemory::New<V3DTestComplexDataHead>(V3DFILE_INFO);
		stream.Read(*dataOut.head);

		dataOut.vertices = V3DMemory::NewArray<float>(V3DFILE_INFO, dataOut.head->verticeCount);
		for (int i = 0; i < dataOut.head->verticeCount; i++)
			stream.Read(dataOut.vertices[i]);

		dataOut.uvs = V3DMemory::NewArray<int>(V3DFILE_INFO, dataOut.head->uvCount);
		for (int i = 0; i < dataOut.head->uvCount; i++)
			stream.Read(dataOut.uvs[i]);
	}
	
	void V3DTestComplexMemoryStreamRepository::WriteDataToStream(const V3DTestComplexData& data, V3DMemoryStream& streamOut) const
	{
		streamOut.Write(*data.head);

		for (int i = 0; i < data.head->verticeCount; i++)
			streamOut.Write(data.vertices[i]);

		for (int i = 0; i < data.head->uvCount; i++)
			streamOut.Write(data.uvs[i]);
	}
}
