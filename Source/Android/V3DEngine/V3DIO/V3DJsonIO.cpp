/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "ThirdParty/Json/json.hpp"
#include "ThirdParty/Json/JsonAndroidHelper.h"

using namespace V3D::V3DEngine::V3DCore;
using json = nlohmann::json;

namespace V3D::V3DEngine::V3DIO
{
	json V3DJsonIO::GetJsonObject(const char* jsonText)
	{
		json result;

		if (json::accept(jsonText))
			return json::parse(jsonText);
		
		return result;
	}
	
	char* V3DJsonIO::GetByteStream(const json& jsonObj)
	{
		char* result{};

		const auto jsonText = jsonObj.dump();
		result = V3DMemory::NewArray<char>(V3DFILE_INFO, jsonText.length() + 1);
		strcpy(result, jsonText.c_str());

		return result;
	}
}
