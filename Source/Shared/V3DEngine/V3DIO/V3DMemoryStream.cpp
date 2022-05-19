/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DMemoryStream.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

#include <cstring>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	V3DMemoryStream::V3DMemoryStream(unsigned int maxSize) : isBufferAllocated{ true }, MaxSize{maxSize}
	{
		buffer = V3DMemory::NewArray<char>(V3DFILE_INFO, MaxSize);
	}

	V3DMemoryStream::V3DMemoryStream(unsigned int maxSize, char* bufferData) : isBufferAllocated{ false }, buffer{ bufferData }, MaxSize{ maxSize }
	{ }

	V3DMemoryStream::V3DMemoryStream(char* bufferData) : isBufferAllocated{ false }, buffer{ bufferData }, MaxSize{ 0 }
	{ }

	V3DMemoryStream::~V3DMemoryStream()
	{
		if (isBufferAllocated)
		{
			V3DMemory::DeleteArray(buffer);
		}
	}
	
	char* V3DMemoryStream::GetBuffer() const
	{
		return buffer;
	}

	unsigned int V3DMemoryStream::GetCurrentSize() const
	{
		return head;
	}

	void V3DMemoryStream::Write(const void* data, unsigned int dataSize)
	{
		memcpy(buffer + head, data, dataSize);
		head += dataSize;
	}

	void V3DMemoryStream::Read(void* dataOut, unsigned int dataSize)
	{
		memcpy(dataOut, buffer + head, dataSize);
		head += dataSize;
	}
}