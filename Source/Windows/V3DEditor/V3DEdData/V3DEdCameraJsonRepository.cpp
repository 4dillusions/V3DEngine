/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdCameraJsonRepository.h"
//#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"

//#include "V3DEdModel/V3DEdCameraModel.h"

#include "ThirdParty/Json/json.hpp"

using json = nlohmann::json;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEditor::V3DEdData
{
	bool V3DEdCameraJsonRepository::ConvertDataFromText(const char* text, V3DEdCameraModel& dataOut) const
	{
		auto jsonObj = V3DJsonIO::GetJsonObject(text);
		if (!jsonObj.empty())
		{
			//strcpy(dataOut.name, jsonObj.at("name").get<std::string>().c_str());
			//dataOut.position = jsonObj["position"];
			//dataOut.orientation = jsonObj["orientation"];

			return true;
		}

		return false;
	}
	
	char* V3DEdCameraJsonRepository::ConvertTextFromData(const V3DEdCameraModel& data) const
	{
		json jsonObj;
		//jsonObj["name"] = std::string(data.name);
		//jsonObj["position"] = data.position;
		//jsonObj["orientation"] = data.orientation;

		return V3DJsonIO::GetByteStream(jsonObj);
	}
}
