/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DTextRW.h"
#include "V3DEngine/V3DCore/V3DIoc.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

#include "V3DEngine/android_native_app_glue.h"

#include <android/asset_manager.h>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	V3DEnvironment* V3DTextRW::GetEnvironment()
	{
		static auto environment = V3DIoc<V3DEnvironment>::Get();
		return &environment;
	}

	V3DString V3DTextRW::Read(V3DAssetPathType path, const char* fileName)
	{
		V3DString result;
		V3DString fileFullName;
		const auto LogFileNotFound = [&fileFullName]()
		{
			V3DString log = V3DString("Couldn't open: ");
			log += fileFullName;

			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, log);
		};
		
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
			if (auto const file = fopen(fileFullName.ToChar(), "r"))
			{
				int letter;
				while ((letter = getc(file)) != EOF)
					result += static_cast<char>(letter);
				
				fclose(file);
			}
			else
			{
				LogFileNotFound();
			}

			return result;
		}

		if (auto const asset = AAssetManager_open(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->assetManager, fileFullName.ToChar(), AASSET_MODE_UNKNOWN))
		{
			const auto size = AAsset_getLength(asset);
			char* buffer = static_cast<char*>(malloc(sizeof(char) * size));

			AAsset_read(asset, buffer, size);

			buffer[size] = '\0';
			result += buffer;
			
			AAsset_close(asset);
			free(buffer);
		}
		else
		{
			LogFileNotFound();
		}
		
		return result;
	}
	
	void V3DTextRW::Write(const char* fileName, const V3DString& text)
	{
		V3DString fileFullName;
		fileFullName += V3DString(static_cast<android_app*>(GetEnvironment()->GetApp())->activity->internalDataPath);
		fileFullName += '/';
		fileFullName += fileName;

		auto const file = fopen(fileFullName.ToChar(), "w+");
		fprintf(file, "%s", text.ToChar());
		fclose(file);
	}
}
