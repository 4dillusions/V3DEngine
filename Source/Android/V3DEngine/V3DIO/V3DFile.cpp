/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/


#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

#include "V3DEngine/android_native_app_glue.h"

#include <android/asset_manager.h>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	V3DEnvironment* V3DFile::GetEnvironment()
	{
		static auto environment = V3DIoc<V3DEnvironment>::Get();
		return &environment;
	}
	
	bool V3DFile::IsExist(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;

		if (path == V3DAssetPathType::Internal)
		{
			fileFullName += static_cast<V3DString>(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
			fileFullName += '/';
		}
		else
		{
			fileFullName += static_cast<V3DString>(GetEnvironment()->GetAssetPath(path));
		}
		
		fileFullName += fileName;

		if (path == V3DAssetPathType::Internal)
		{
			return std::fopen(fileFullName.ToChar(), "r+");
		}

		auto* const asset = AAssetManager_open(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->assetManager, fileFullName.ToChar(), AASSET_MODE_UNKNOWN);
		return asset != nullptr;
	}
	
	void V3DFile::Create(const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += static_cast<V3DString>(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;

		auto* const file = std::fopen(fileFullName.ToChar(), "w+");
		std::fwrite(file, sizeof(char), 0, file);
		std::fclose(file);
	}
	
	void V3DFile::Delete(const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += static_cast<V3DString>(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;
		
		std::remove(fileFullName.ToChar());
	}
}
