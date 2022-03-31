/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAppDataSecurity.h"
#include "V3DEngine/V3DIO/V3DFolder.h"
#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DCryptography/V3DHashMethod.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCryptography;

namespace V3D::V3DEngine::V3DData
{
	bool V3DAppDataSecurity::GetIsAllAppDataValid(const V3DString& key, const V3DString& validHash)
	{
		V3DString textForHash;

		for (int assetPathType = 0; assetPathType < (int)V3DAssetPathType::AllFolderCount; assetPathType++)
		{
			auto fileList = V3DFolder::GetFileList((V3DAssetPathType)assetPathType);
			for (fileList.First(); fileList.IsDone(); fileList.Next())
			{
				textForHash += *fileList.GetCurrent();
				textForHash += (int)V3DFile::GetSize((V3DAssetPathType)assetPathType, fileList.GetCurrent()->ToChar()); //1 file max size: 2 billion bytes (2.147.483.647) ~ 2.047 Mb ~ 2 Gb
			}
		}

		const V3DHashMethod sha256Method(V3DHashType::SHA256);
		return sha256Method.CreateHMAC(textForHash, key) == validHash;
	}
}
