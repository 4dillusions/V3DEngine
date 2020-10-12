/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DENGINE_API V3DMemoryStream final
	{
		const unsigned long long MaxSize;
		unsigned long long head{};
		char* buffer{};
		bool isBufferAllocated;

		void Write(const void* data, unsigned long long dataSize);
		void Read(void* dataOut, unsigned long long dataSize);
		
	public:
		V3DMemoryStream() = delete;
		V3DMemoryStream(const V3DMemoryStream&) = delete;
		V3DMemoryStream(V3DMemoryStream&&) = delete;
		V3DMemoryStream& operator=(const V3DMemoryStream&) = delete;
		V3DMemoryStream& operator=(V3DMemoryStream&&) = delete;

		explicit V3DMemoryStream(unsigned long long maxSize);
		explicit V3DMemoryStream(unsigned long long maxSize, char* bufferData);
		explicit V3DMemoryStream(char* bufferData);
		~V3DMemoryStream();

		[[nodiscard]] char* GetBuffer() const;
		[[nodiscard]] unsigned long long GetCurrentSize() const;

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
