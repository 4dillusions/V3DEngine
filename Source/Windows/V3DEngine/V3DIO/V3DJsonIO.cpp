/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

#include "ThirdParty/Json/json.hpp"

using namespace V3D::V3DEngine::V3DCore;

using json = nlohmann::json;

namespace V3D::V3DEngine::V3DIO
{
	json V3DJsonIO::GetJsonObject(const char* jsonText)
	{
		json result;
		
		if (json::accept(jsonText))
			return json::parse(jsonText);
		
		#ifdef _DEBUG //don't handle exceptions in Release mode
			static const auto environment = V3DIoc<V3DEnvironment>::Get();  // NOLINT(readability-misleading-indentation)
			if (!environment.GetIsUnitTestMode())
			{
				try
				{
					result = json::parse(jsonText);
				}
				catch (json::exception& ex)
				{
					V3DIoc<V3DLogger>::Get().WriteOutput(V3DLogMessageType::Error, ex.what());
				}
			}
		#endif

		return result;
	}
	
	char* V3DJsonIO::GetByteStream(const json& jsonObj)
	{
		const auto jsonText = jsonObj.dump();
		char* result = new char[jsonText.length() + 1];
		strcpy(result, jsonText.c_str());

		return result;
	}
}
