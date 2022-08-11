/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngine::V3DAsset
{
	struct V3DENGINE_API V3DAssetData final  // NOLINT(cppcoreguidelines-pro-type-member-init)
	{
		bool isStatic;

		V3DCore::V3DAssetPathType path;  // NOLINT(clang-diagnostic-padded)
		V3DCore::V3DString name;
		
		unsigned int binaryDataLenght{};
		
		char* binaryData{};
	    V3DCore::V3DString* textData{};
    };
}
