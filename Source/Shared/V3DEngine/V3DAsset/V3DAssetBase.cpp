/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAssetBase.h"
#include "V3DAssetData.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DAsset
{
	V3DAssetBase::~V3DAssetBase()
	{
		V3DMemory::DeleteArray(assetData->binaryData);
		V3DMemory::Delete(assetData->textData);
		V3DMemory::Delete(assetData);
	}

	bool V3DAssetBase::GetIsStatic() const
	{
		return assetData->isStatic;
	}

	void V3DAssetBase::SetAssetData(V3DAssetData* asset)
	{
		if (assetData == nullptr && asset != nullptr)
			assetData = asset;
	}
}
