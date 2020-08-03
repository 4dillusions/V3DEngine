/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestSimpleBinaryData.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	void V3DTestSimpleBinaryData::Load(V3DAssetPathType path, const char* fileName)
	{
		auto data = reinterpret_cast<V3DTestSimpleBinaryData*>(V3DBinaryRW::Read(path, fileName));
		*this = *data;

		V3DMemory::DeleteArray(data);
	}
	
	void V3DTestSimpleBinaryData::Save(const char* fileName)
	{
		V3DBinaryRW::Write(fileName, reinterpret_cast<char*>(this), sizeof(V3DTestSimpleBinaryData));
	}
}
