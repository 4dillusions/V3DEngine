/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestSimpleFileRepository.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

#include "V3DTestSimpleData.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestSimpleData V3DTestSimpleFileRepository::Load(V3DAssetPathType path, const char* fileName) const
	{
		auto data = reinterpret_cast<V3DTestSimpleData*>(V3DBinaryRW::Read(path, fileName));
		const V3DTestSimpleData result = *data;
		V3DMemory::DeleteArray(data);
		
		return result;
	}
	
	void V3DTestSimpleFileRepository::Save(V3DTestSimpleData& data, const char* fileName) const
	{
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(&data), sizeof(V3DTestSimpleData));
	}
}
