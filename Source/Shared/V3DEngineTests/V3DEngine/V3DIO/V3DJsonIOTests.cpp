/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DJsonIOTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngineTests/V3DTestObject/V3DTestConfigData.h"
#include "V3DEngineTests/V3DTestObject/V3DTestConfigJsonRepository.h"

#include "ThirdParty/Json/json.hpp"
#include "V3DEngine/V3DIO/V3DJsonVariantTypes.h"
#include "V3DEngine/V3DIO/V3DJsonVariant.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngineTests/V3DTestObject/V3DJsonVariantHelper.h"
#include "V3DEngineTests/V3DTestObject/V3DTestUIControl.h"
#include "V3DEngineTests/V3DTestObject/V3DTestUIControlJsonRepository.h"

using namespace V3D::V3DEngine::V3DIO;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DData;
using namespace V3D::V3DEngineTests::V3DTestObject;

using json = nlohmann::json;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DJsonIOTests::JsonParseTest()
	{
		const auto jsonGoodObject = V3DJsonIO::GetJsonObject(R"({"test" : "good"})");
		V3DTest::AssertOk(!jsonGoodObject.empty(), V3DFILE_INFO);

		const auto jsonWrongObject = V3DJsonIO::GetJsonObject(R"({"test" : wrong"})");
		V3DTest::AssertOk(jsonWrongObject.empty(), V3DFILE_INFO);
	}
	
	void V3DJsonIOTests::BuildJsonFromCodeTest()
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

	void V3DJsonIOTests::ConfigLoadSaveTest()
	{
		const auto jsonText =
		R"(
			{
				"name": "Test 123",
				"width": 35,
				"testNumber" : 3.14
			}
		)";

		V3DITextRepository<V3DTestConfigData>* configJsonRepository = V3DMemory::New<V3DTestConfigJsonRepository>(V3DFILE_INFO);

		V3DTestConfigData data;
		configJsonRepository->ConvertDataFromText(jsonText, data);

		char* streamData = configJsonRepository->ConvertTextFromData(data);
		V3DTest::AssertOk(V3DString(streamData) == V3DString(R"({"name":"Test 123","testNumber":3.140000104904175,"width":35})"), V3DFILE_INFO);
		V3DMemory::DeleteArray(streamData);

		V3DMemory::Delete(configJsonRepository);
	}

	void V3DJsonIOTests::UIBuildTest()
	{
		const auto jsonText =
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

		V3DTestUIControl control;

		V3DITextRepository<V3DTestUIControl>* configJsonRepository = V3DMemory::New<V3DTestUIControlJsonRepository>(V3DFILE_INFO);
		configJsonRepository->ConvertDataFromText(jsonText, control);
		V3DMemory::Delete(configJsonRepository);

		V3DString out;
		control.WriteToString(out);
		auto outLines = out.Split('\n');
		V3DTest::AssertOk(*outLines[0] == V3DString("Main window00"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[1] == V3DString("-Settings window100100"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[2] == V3DString("--Start100"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[3] == V3DString("--Exit1050"), V3DFILE_INFO);
		V3DTest::AssertOk(*outLines[4] == V3DString("-Editor55"), V3DFILE_INFO);
	}

	void V3DJsonIOTests::TraversalAndSetTest()
	{
		const auto JsonString =
			R"(
			{
				"widgetName": "window",
				"width": 122,
				"list": [1, 2, 3],
				"objects":
				{
					"obj1":
					{
						"x": 10,
						"y": 20
					},
					"obj2":
					{
						"x": 30,
						"y": 40
					}
				}
			}
		)";

		const json JsonObj = V3DJsonIO::GetJsonObject(JsonString);
		V3DAction3<const V3DString&, const V3DString&, const V3DJsonVariant&> action;

		const auto OutputBefore = R"({"list":[1,2,3],"objects":{"obj1":{"x":10,"y":20},"obj2":{"x":30,"y":40}},"widgetName":"window","width":122})";
		V3DTest::AssertOk(V3DString(OutputBefore) == V3DString(JsonObj.dump().c_str()), V3DFILE_INFO);

		action.Set([&](const V3DString& parentName, const V3DString& name, const V3DJsonVariant& variant)
		{
			if (name == V3DString("widgetName"))
				*variant.text = "window1";

			if (variant.unsignedIntNumber != nullptr && *variant.unsignedIntNumber == 30)
				*variant.unsignedIntNumber = 32;

			if (variant.currentType == V3DJsonVariantTypes::Array)
			{
				const auto Array = static_cast<json::array_t*>(variant.array);
				Array->clear();
				Array->push_back(4);
				Array->push_back(5);
				Array->push_back(6);
			}
		});
		V3DJsonIO::TraversalJsonHierarchy(JsonObj, nullptr, action);
		const auto OutputAfter = R"({"list":[4,5,6],"objects":{"obj1":{"x":10,"y":20},"obj2":{"x":32,"y":40}},"widgetName":"window1","width":122})";
		V3DTest::AssertOk(V3DString(OutputAfter) == V3DString(JsonObj.dump().c_str()), V3DFILE_INFO);


		//dump custom hierarchy and json structure
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, true);
		action.Set([&](const V3DString& parentName, const V3DString& name, const V3DJsonVariant& variant)
		{
			V3DString dumpLine;
			dumpLine += V3DString("<") + parentName + "> " + V3DJsonVariantHelper::ToStringType(variant) + " " + name + " " + V3DJsonVariantHelper::ToStringValue(variant);
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, dumpLine);
		});
		V3DJsonIO::TraversalJsonHierarchy(JsonObj, nullptr, action);

		V3DLogger::Get().WriteOutput(V3DLogMessageType::Info, JsonObj.dump().c_str());
		V3DLogger::Get().SetOutputTypeFlag(V3DLogOutputType::ToOutput, false);
	}

	void V3DJsonIOTests::RunAllUnitTests()
	{
		JsonParseTest();
		BuildJsonFromCodeTest();
		ConfigLoadSaveTest();
		UIBuildTest();
		TraversalAndSetTest();
	}

	void V3DJsonIOTests::RegisterIntegrationTests()
	{
	}

	void V3DJsonIOTests::RegisterTimingTests()
	{
	}
}
