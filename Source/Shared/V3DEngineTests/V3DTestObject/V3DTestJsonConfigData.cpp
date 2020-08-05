/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestJsonConfigData.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"

#include "ThirdParty/Json/json.hpp"

using json = nlohmann::json;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	bool V3DTestJsonConfigData::Load(const char* jsonText)
	{
		auto jsonObj = V3DJsonIO::GetJsonObject(jsonText);
		if (!jsonObj.empty())
		{
			strcpy(name, jsonObj.at("name").get<std::string>().c_str());
			width = jsonObj["width"];
			testNumber = jsonObj["testNumber"];

			return true;
		}
		
		return false;
	}
	
	char* V3DTestJsonConfigData::Save() const
	{
		json jsonObj;
		jsonObj["name"] = std::string(name);
		jsonObj["width"] = width;
		jsonObj["testNumber"] = testNumber;

		return V3DJsonIO::GetByteStream(jsonObj);
	}
}
