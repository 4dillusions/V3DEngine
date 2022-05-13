/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCryptographyHelperTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCryptography/V3DCryptographyHelper.h"

using namespace V3D::V3DEngine::V3DCryptography;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DEngine::V3DCryptography
{
	void V3DCryptographyHelperTests::ConvertHexArrayToStringTest()
	{
		const unsigned char hexArray[] = { 0xFF, 0xEE, 0xDD, 0xCC, 0xBB, 0xAA, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22, 0x11, 0x00 };
		constexpr int hexArrayLen = std::size(hexArray); //sizeof(hexArray) / sizeof(*hexArray);
		const V3DString hexString("ffeeddccbbaa99887766554433221100");

		const auto hexStringResult = V3DCryptographyHelper::ConvertHexArrayToString(hexArray, hexArrayLen);
		V3DTest::AssertOk(hexStringResult == hexString, V3DFILE_INFO);
	}
	
	void V3DCryptographyHelperTests::RunAllTests()
	{	
		ConvertHexArrayToStringTest();
	}
}
