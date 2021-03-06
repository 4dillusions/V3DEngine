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
	V3DMemoryStream::V3DMemoryStream(unsigned long long maxSize) : MaxSize{maxSize}, isBufferAllocated{ true }
	{
		buffer = V3DMemory::NewArray<char>(V3DFILE_INFO, MaxSize);
	}

	V3DMemoryStream::V3DMemoryStream(unsigned long long maxSize, char* bufferData) : MaxSize{ maxSize }, buffer{ bufferData }, isBufferAllocated{ false }
	{ }

	V3DMemoryStream::V3DMemoryStream(char* bufferData) : MaxSize{ 0 }, buffer{ bufferData }, isBufferAllocated{ false }
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

	unsigned long long V3DMemoryStream::GetCurrentSize() const
	{
		return head;
	}

	void V3DMemoryStream::Write(const void* data, unsigned long long dataSize)
	{
		memcpy(buffer + head, data, dataSize);
		head += dataSize;
	}

	void V3DMemoryStream::Read(void* dataOut, unsigned long long dataSize)
	{
		memcpy(dataOut, buffer + head, dataSize);
		head += dataSize;
	}
}