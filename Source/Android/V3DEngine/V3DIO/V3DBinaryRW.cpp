/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DCore/V3DString.h"

#include "V3DEngine/android_native_app_glue.h"

#include <android/asset_manager.h>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	char* V3DBinaryRW::Read(V3DAssetPathType path, const char* fileName)
	{
		char* result{};
		V3DString fileFullName;
		const auto LogFileNotFound = [&fileFullName]()
		{
			V3DString log = V3DString("Couldn't open: ");
			log += fileFullName;

			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, log);
		};

		if (path == V3DAssetPathType::Internal)
		{
			fileFullName += V3DString(static_cast<android_app*>(V3DEnvironment::GetApp())->activity->internalDataPath);
			fileFullName += '/';
		}
		else
		{
			fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		}

		fileFullName += fileName;

		if (path == V3DAssetPathType::Internal)
		{
			if (auto const file = std::fopen(fileFullName.ToChar(), "rb"))
			{
				fseek(file, 0, SEEK_END);
				const auto size = ftell(file);
				fseek(file, 0, SEEK_SET);

				result = V3DMemory::NewArray<char>(V3DFILE_INFO, static_cast<unsigned int>(sizeof(char) * size));
				fread(result, size, 1, file);
				fclose(file);
			}
			else
			{
				LogFileNotFound();
			}

			return result;
		}

		if (auto const asset = AAssetManager_open(static_cast<android_app*>(V3DEnvironment::GetApp())->activity->assetManager, fileFullName.ToChar(), AASSET_MODE_UNKNOWN))
		{
			const auto size = AAsset_getLength(asset);
			char* buffer = V3DMemory::NewArray<char>(V3DFILE_INFO, (sizeof(char) * size) + 1);

			AAsset_read(asset, buffer, size);
			result[size] = '\0';
			
			AAsset_close(asset);
		}
		else
		{
			LogFileNotFound();
		}
		
		return nullptr;
	}
	
	void V3DBinaryRW::Write(const char* fileName, char* data, long size, long offset)
	{
		V3DString fileFullName;
		fileFullName += V3DString(static_cast<android_app*>(V3DEnvironment::GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;

		const char* mode = offset == 0 ? "wb+" : "ab+";
		auto const file = std::fopen(fileFullName.ToChar(), mode);
		fseek(file, static_cast<long>(offset), SEEK_SET);
		fwrite(data, size, 1, file);
		std::fclose(file);
	}
}
