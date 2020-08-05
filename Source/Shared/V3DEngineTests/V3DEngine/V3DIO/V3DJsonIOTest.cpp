/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DJsonIOTest.h"

#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngineTests/V3DTestObject/V3DTestJsonConfigData.h"

#include "ThirdParty/Json/json.hpp"
#include "V3DEngineTests/V3DTestObject/V3DTestJSonUIControl.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngineTests::V3DTestObject;

using json = nlohmann::json;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DJsonIOTest::JsonParseTest()
	{
		const auto jsonGoodObject = V3DJsonIO::GetJsonObject(R"({"test" : "good"})");
		V3DTest::AssertOk(!jsonGoodObject.empty(), V3DFILE_INFO);

		const auto jsonWrongObject = V3DJsonIO::GetJsonObject(R"({"test" : wrong"})");
		V3DTest::AssertOk(jsonWrongObject.empty(), V3DFILE_INFO);
	}
	
	void V3DJsonIOTest::BuildJsonFromCodeTest()
	{
		json jsonObject;
		jsonObject["server ip"] = "1.187.23.56";
		jsonObject["playerCount"] = 23;

		json player1;
		player1["name"] = "player1";
		player1["score"] = 122;

		json player2;
		player2["name"] = "player2";
		player2["score"] = 123;

		jsonObject["playerList"] += player1;
		jsonObject["playerList"] += player2;

		V3DTest::AssertOk(V3DString(jsonObject.dump().c_str()) == V3DString(R"({"playerCount":23,"playerList":[{"name":"player1","score":122},{"name":"player2","score":123}],"server ip":"1.187.23.56"})"), V3DFILE_INFO);
	}

	void V3DJsonIOTest::ConfigLoadSaveTest()
	{
		const auto* const jsonText =
			R"(
				{
					"name": "Test 123",
					"width": 35,
					"testNumber" : 3.14
				}
			)";

		V3DTestJsonConfigData data;
		data.Load(jsonText);

		char* streamData = data.Save();
		V3DTest::AssertOk(V3DString(streamData) == V3DString(R"({"name":"Test 123","testNumber":3.140000104904175,"width":35})"), V3DFILE_INFO);
		V3DMemory::DeleteArray(streamData);
	}

	void V3DJsonIOTest::UIBuildTest()
	{
		const auto* const jsonText =
			R"(
				{
					"type": "window",
					"name": "Main window",
					"x" : 0,
					"y" : 0,
					"controls" :
						[
							{
								"type": "window",
								"name": "Settings window",
								"x" : 100,
								"y" : 100,
								"controls" :
									[
										{
											"type": "button",
											"name": "Start",
											"x" : 10,
											"y" : 0,
											"controls" : null
										},
										{
											"type": "button",
											"name": "Exit",
											"x" : 10,
											"y" : 50,
											"controls" : null
										}
									]
							},
							{
								"type": "button",
								"name": "Editor",
								"x" : 5,
								"y" : 5,
								"controls" : null
							}
						]
				}
			)";

		const auto jsonObject = V3DJsonIO::GetJsonObject(jsonText);

		V3DTestJSonUIControl control;
		control.Load(jsonObject);

		V3DString out;
		control.WriteToString(out);
		auto outLines = out.Split('\n');
		V3DTest::AssertOk(*outLines[0] == V3DString("Main window00"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[1] == V3DString("-Settings window100100"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[2] == V3DString("--Start100"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[3] == V3DString("--Exit1050"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[4] == V3DString("-Editor55"), V3DFILE_INFO);
	}

	void V3DJsonIOTest::RunAllTests()
	{
		JsonParseTest();
		BuildJsonFromCodeTest();
		ConfigLoadSaveTest();
		UIBuildTest();
	}
}
