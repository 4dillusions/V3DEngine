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

#include <cstdio>

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
			fileFullName += V3DString(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		}
		else
		{
			fileFullName += V3DString(GetEnvironment()->GetAssetPath(path));
		}

		fileFullName += '/';
		fileFullName += fileName;

		if (path == V3DAssetPathType::Internal)
		{
			if (auto* const file = fopen(fileFullName.ToChar(), "r"))
			{
				fclose(file);
				return true;
			}

			return false;
		}

		if (auto* const asset = AAssetManager_open(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->assetManager, fileFullName.ToChar(), AASSET_MODE_UNKNOWN))
		{
			AAsset_close(asset);
			return true;
		}
		
		return false;
	}

	long V3DFile::GetSize(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;

		if (path == V3DAssetPathType::Internal)
		{
			fileFullName += V3DString(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		}
		else
		{
			fileFullName += V3DString(GetEnvironment()->GetAssetPath(path));
		}

		fileFullName += '/';
		fileFullName += fileName;

		if (path == V3DAssetPathType::Internal)
		{
			if (auto* const file = fopen(fileFullName.ToChar(), "r"))
			{
				fseek(file, 0, SEEK_END);
				const auto length = ftell(file);
				fseek(file, 0, SEEK_SET);
				fclose(file);

				return length;
			}

			return -1;
		}

		if (auto* const asset = AAssetManager_open(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->assetManager, fileFullName.ToChar(), AASSET_MODE_UNKNOWN))
		{
			const long size = AAsset_getLength(asset);
			AAsset_close(asset);

			return size;
		}
		
		return -1;
	}
	
	void V3DFile::Create(const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;

		auto* const file = fopen(fileFullName.ToChar(), "w+");
		fwrite(file, sizeof(char), 0, file);
		fclose(file);
	}
	
	void V3DFile::Delete(const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;
		
		remove(fileFullName.ToChar());
	}
}
