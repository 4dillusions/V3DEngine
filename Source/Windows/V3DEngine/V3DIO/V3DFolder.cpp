/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DFolder.h"

#include <filesystem>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	bool V3DFolder::IsExist(V3DAssetPathType path)
	{	
		return exists(std::filesystem::path(V3DString(V3DEnvironment::GetAssetPath(path)).ToChar()));
	}
	
	V3DDynamicArray<V3DString> V3DFolder::GetFileList(V3DAssetPathType path)
	{
		V3DDynamicArray<V3DString> result;

		for (const auto& file : std::filesystem::directory_iterator(V3DString(V3DEnvironment::GetAssetPath(path)).ToChar()))
			result.Add(V3DString(file.path().filename().u8string().c_str()));
		
		return result;
	}
}
