/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAssetManager.h"
#include "V3DAssetBase.h"
#include "V3DAssetData.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DTextRW.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngine::V3DAsset
{
	V3DAssetManager::V3DAssetManager()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Init AssetManager");
	}

	V3DAssetManager::~V3DAssetManager()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "Release AssetManager");
		UnloadAll();
	}
	
	bool V3DAssetManager::Load(bool isStatic, V3DAssetBase* asset, V3DAssetPathType path, const char* name)
	{
		if (!V3DFile::IsExist(path, name))
		{
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, V3DString("Couldn't open asset: ") + name);
			V3DMemory::Delete(asset);

			return false;
		}

		const auto assetData = V3DMemory::New<V3DAssetData>(V3DFILE_INFO);
		assetData->isStatic = isStatic;
		assetData->path = path;
		assetData->name = name;
		
		if (asset->GetIsBinary())
		{
			unsigned int lenght = 0;
			assetData->binaryData = V3DBinaryRW::Read(path, name, &lenght);
			assetData->binaryDataLenght = lenght;
		}
		else
			assetData->textData = V3DTextRW::Read(path, name);

		asset->SetAssetData(assetData);
		asset->Load();

		assets.Add(assetData->name.GetHashCode(), asset);
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, V3DString("Load asset: ") + name);

		return true;
	}
	
	V3DAssetBase* V3DAssetManager::GetAsset(const char* name)
	{
		const int nameHashCode = V3DString::GetHashCode(name);
		if (const auto result = assets.GetItem(nameHashCode))
			return *result;

		return nullptr;
	}

	void V3DAssetManager::UnloadAll()
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, "AssetManager: UnloadAll assets");

		for (assets.First(); assets.IsDone(); assets.Next())
			V3DMemory::Delete(*assets.GetCurrentItem());

		assets.RemoveAll();
	}

	void V3DAssetManager::UnloadAll(bool isStatic)
	{
		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, V3DString("AssetManager: UnloadAll ") + (isStatic ? "static" : "non static") + " assets");

		for (assets.First(); assets.IsDone(); assets.Next())
			if ((*assets.GetCurrentItem())->GetIsStatic() == isStatic)
			{
				V3DMemory::Delete(*assets.GetCurrentItem());
				assets.RemoveCurrent();
			}
	}
}
