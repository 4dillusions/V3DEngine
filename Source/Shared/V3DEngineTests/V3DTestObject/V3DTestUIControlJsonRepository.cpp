/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestUIControlJsonRepository.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DMacros.h"

#include "ThirdParty/Json/json.hpp"

#include "V3DTestUIControl.h"

using json = nlohmann::json;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DTestObject
{
	bool V3DTestUIControlJsonRepository::ConvertDataFromText(const char* text, V3DTestUIControl& dataOut) const
	{
		auto jsonObj = V3DJsonIO::GetJsonObject(text);

		if (!jsonObj.empty())
		{
			strcpy(dataOut.name, jsonObj.at("name").get<std::string>().c_str());
			dataOut.x = jsonObj["x"];
			dataOut.y = jsonObj["y"];

			if (!jsonObj["controls"].is_null())
			{
				for (const auto& controlJson : jsonObj["controls"])
				{
					auto control = V3DMemory::New<V3DTestUIControl>(V3DFILE_INFO);
					control->hierarchyCode = dataOut.hierarchyCode + 1;
					auto jsonStream = V3DJsonIO::GetByteStream(controlJson);
					ConvertDataFromText(jsonStream, *control);
					dataOut.controls.push_back(control);
					V3DMemory::DeleteArray(jsonStream);
				}
			}

			return true;
		}

		return false;
	}
	
	char* V3DTestUIControlJsonRepository::ConvertTextFromData(const V3DTestUIControl& data) const
	{
		return nullptr;
	}
}
