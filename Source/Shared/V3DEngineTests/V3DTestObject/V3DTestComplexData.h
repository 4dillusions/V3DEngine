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
			const unsigned int HeadSize;
			const unsigned int VerticeSize;
			const unsigned int UvSize;

			DataSize(const V3DTestComplexDataHead* head) : HeadSize{ sizeof(V3DTestComplexDataHead) }, VerticeSize{ static_cast<unsigned int>(sizeof(*vertices)) * head->verticeCount }, UvSize{ static_cast<unsigned int>(sizeof(*uvs)) * head->uvCount }    // NOLINT(bugprone-implicit-widening-of-multiplication-result)
			{ }
		};

		V3DTestComplexData() = default;
		V3DTestComplexData(const V3DTestComplexData&) = default;
		V3DTestComplexData(V3DTestComplexData&&) = default;
		V3DTestComplexData& operator=(const V3DTestComplexData&) = default;
		V3DTestComplexData& operator=(V3DTestComplexData&&) = default;

		explicit V3DTestComplexData(const V3DTestComplexDataHead& dataHead);
		~V3DTestComplexData();

		unsigned int GetSize() const;
	};
}
