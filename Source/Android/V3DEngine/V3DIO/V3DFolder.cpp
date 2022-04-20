/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DFolder.h"

#include "V3DEngine/android_native_app_glue.h"

#include <android/asset_manager.h>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	bool V3DFolder::IsExist(V3DAssetPathType path)
	{
		auto const dir = AAssetManager_openDir(static_cast<android_app*>(V3DEnvironment::GetApp())->activity->assetManager, V3DEnvironment::GetAssetPath(path));
		const bool result = AAssetDir_getNextFileName(dir);
		AAssetDir_close(dir);

		return result;
	}
	
	V3DDynamicArray<V3DString> V3DFolder::GetFileList(V3DAssetPathType path)
	{
		V3DDynamicArray<V3DString> result;

		auto const dir = AAssetManager_openDir(static_cast<android_app*>(V3DEnvironment::GetApp())->activity->assetManager, V3DEnvironment::GetAssetPath(path));

		while(const auto fileName = AAssetDir_getNextFileName(dir))
			result.Add(V3DString(fileName));
		
		return result;
	}
}
