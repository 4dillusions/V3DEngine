/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DENGINE_API V3DMemoryStream final  // NOLINT(clang-diagnostic-padded)
	{
		bool isBufferAllocated;
		char* buffer{};  // NOLINT(clang-diagnostic-padded)
		unsigned int head{};
		const unsigned int MaxSize;
		
		void Write(const void* data, unsigned int dataSize);
		void Read(void* dataOut, unsigned int dataSize);
		
	public:
		V3DMemoryStream() = delete;
		V3DMemoryStream(const V3DMemoryStream&) = delete;
		V3DMemoryStream(V3DMemoryStream&&) = delete;
		V3DMemoryStream& operator=(const V3DMemoryStream&) = delete;
		V3DMemoryStream& operator=(V3DMemoryStream&&) = delete;

		explicit V3DMemoryStream(unsigned int maxSize);
		explicit V3DMemoryStream(unsigned int maxSize, char* bufferData);
		explicit V3DMemoryStream(char* bufferData);
		~V3DMemoryStream();

		char* GetBuffer() const;
		unsigned int GetCurrentSize() const;

		template<typename T> void Read(T& data)
		{
			Read(static_cast<void*>(&data), sizeof(T));
		}

		template<typename T> void Write(T& data)
		{
			Write(static_cast<void*>(&data), sizeof(T));
		}
	};
}
