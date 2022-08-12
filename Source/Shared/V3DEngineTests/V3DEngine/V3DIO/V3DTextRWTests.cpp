/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTextRWTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DTextRW.h"
#include "V3DEngine/V3DIO/V3DFile.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DTextRWTests::TextRWTest()
	{
		const char* TestAsset = "test2.txt";
		const char* TestInternal = "test.txt";
		const V3DString TestString(R"(<img src="Doc/Doxygen/Res/V3DLogoLarge.png">)");

		V3DString* text1 = V3DTextRW::Read(V3DAssetPathType::Options, TestAsset);
		V3DTest::AssertOk(text1->Contains(TestString), V3DFILE_INFO);
		V3DMemory::Delete(text1);

		V3DTextRW::Write(TestInternal, TestString);
		V3DString* text2 = V3DTextRW::Read(V3DAssetPathType::Internal, TestInternal);
		V3DTest::AssertOk(text2->Contains(TestString), V3DFILE_INFO);
		V3DMemory::Delete(text2);
		V3DFile::Delete(TestInternal);
	}

	void V3DTextRWTests::RunAllUnitTests()
	{
		TextRWTest();
	}

	void V3DTextRWTests::RegisterIntegrationTests()
	{
	}

	void V3DTextRWTests::RegisterTimingTests()
	{
	}
}
