/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTestComplexDataHead.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DMemoryStream;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestComplexData final
	{
		V3DTestComplexDataHead* head{};

		float* vertices{};
		int* uvs{};

		char* dataStream{};

		struct DataSize
		{
			const unsigned long long HeadSize;
			const unsigned long long VerticeSize;
			const unsigned long long UvSize;

			DataSize(const V3DTestComplexDataHead* head) : HeadSize{ sizeof(V3DTestComplexDataHead) }, VerticeSize{ sizeof(*vertices) * head->verticeCount }, UvSize{ sizeof(*uvs) * head->uvCount }
			{ }
		};

		V3DTestComplexData() = default;
		V3DTestComplexData(const V3DTestComplexData&) = default;
		V3DTestComplexData(V3DTestComplexData&&) = default;
		V3DTestComplexData& operator=(const V3DTestComplexData&) = default;
		V3DTestComplexData& operator=(V3DTestComplexData&&) = default;

		explicit V3DTestComplexData(const V3DTestComplexDataHead& dataHead);
		~V3DTestComplexData();

		unsigned long long GetSize() const;
	};
}
