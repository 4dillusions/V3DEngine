/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTestBinaryDataHead.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DMemoryStream;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestBinaryData final
	{
		V3DTestBinaryDataHead* head{};

		float* vertices{};
		int* uvs{};

		char* dataStream{};

		struct DataSize
		{
			const unsigned long long HeadSize;
			const unsigned long long VerticeSize;
			const unsigned long long UvSize;

			DataSize(const V3DTestBinaryDataHead* head) : HeadSize{ sizeof(V3DTestBinaryDataHead) }, VerticeSize{ sizeof(*vertices) * head->verticeCount }, UvSize{ sizeof(*uvs) * head->uvCount }
			{ }
		};

		V3DTestBinaryData() = default;
		V3DTestBinaryData(const V3DTestBinaryData&) = default;
		V3DTestBinaryData(V3DTestBinaryData&&) = default;
		V3DTestBinaryData& operator=(const V3DTestBinaryData&) = default;
		V3DTestBinaryData& operator=(V3DTestBinaryData&&) = default;

		explicit V3DTestBinaryData(const V3DTestBinaryDataHead& dataHead);
		~V3DTestBinaryData();

		[[nodiscard]] unsigned long long GetSize() const;

		void Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName);
		void Load(V3D::V3DEngine::V3DIO::V3DMemoryStream &stream);
		void Save(const char* fileName) const;
		void Save(V3D::V3DEngine::V3DIO::V3DMemoryStream& streamOut) const;
	};
}
