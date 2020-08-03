/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DAssetPathType.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestSimpleBinaryData final
	{
		int id{};
		char text[10]{};

		void Load(V3D::V3DEngine::V3DCore::V3DAssetPathType path, const char* fileName);
		void Save(const char* fileName);
	};
}
