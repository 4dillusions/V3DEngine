/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestJSonUIControl.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "ThirdParty/Json/json.hpp"

using namespace V3D::V3DEngine::V3DCore;
using json = nlohmann::json;

namespace V3D::V3DEngineTests::V3DTestObject
{
	V3DTestJSonUIControl::~V3DTestJSonUIControl()
	{
		for (auto* ptr : controls)
			V3DMemory::Delete(ptr);

		controls.clear();
	}
	
	void V3DTestJSonUIControl::Load(const json& jsonObj, int hierarchyNum)
	{
		strcpy(name, jsonObj.at("name").get<std::string>().c_str());
		hierarchyCode = hierarchyNum;
		x = jsonObj["x"];
		y = jsonObj["y"];

		if (!jsonObj["controls"].is_null())
			for (const auto& controlJson : jsonObj["controls"])
			{
				auto* control = V3DMemory::New<V3DTestJSonUIControl>(V3DFILE_INFO);
				controls.push_back(control);
				control->Load(controlJson, hierarchyNum + 1);
			}
	}
	
	void V3DTestJSonUIControl::WriteToString(V3DString& out)
	{
		for (int i = 0; i < hierarchyCode; i++)
			out += '-';

		for (auto letter : name)
			if (letter != '\0')
				out += letter;
		
		out += x;
		out += y;
		out += '\n';

		for (const auto& control : controls)
			control->WriteToString(out);
	}
}
