/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestConfigJsonRepository.h"
#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"

#include "V3DTestConfigData.h"

#include "ThirdParty/Json/json.hpp"

using json = nlohmann::json;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	bool V3DTestConfigJsonRepository::ConvertDataFromText(const char* text, V3DTestConfigData& dataOut) const
	{
		auto jsonObj = V3DJsonIO::GetJsonObject(text);
		if (!jsonObj.empty())
		{
			strcpy(dataOut.name, jsonObj.at("name").get<std::string>().c_str());
			dataOut.width = jsonObj["width"];
			dataOut.testNumber = jsonObj["testNumber"];

			return true;
		}

		return false;
	}
	
	char* V3DTestConfigJsonRepository::ConvertTextFromData(const V3DTestConfigData& data) const
	{
		json jsonObj;
		jsonObj["name"] = std::string(data.name);
		jsonObj["width"] = data.width;
		jsonObj["testNumber"] = data.testNumber;

		return V3DJsonIO::GetByteStream(jsonObj);
	}
}
