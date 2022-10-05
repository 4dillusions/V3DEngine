/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DFolderTests.h"
#include "V3DEngineTests/V3DTest.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DIO/V3DFolder.h"

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

namespace V3D::V3DEngineTests::V3DEngine::V3DIO
{
	void V3DFolderTests::FolderTest()
	{
		V3DTest::AssertOk(V3DFolder::IsExist(V3DAssetPathType::Options), V3DFILE_INFO);
		V3DTest::AssertOk(!V3DFolder::IsExist(static_cast<V3DAssetPathType>(-1)), V3DFILE_INFO); //negative test: "default" folder

		auto fileList = V3DFolder::GetFileList(V3DAssetPathType::Options);
		constexpr int FileListCout = 4;
		V3DTest::AssertOk(fileList.GetLength() == FileListCout, V3DFILE_INFO);

		if (fileList.GetLength() == FileListCout)
		{
			V3DTest::AssertOk(*fileList[0] == V3DString("GameOptions.json"), V3DFILE_INFO);
			V3DTest::AssertOk(*fileList[1] == V3DString("test.txt"), V3DFILE_INFO);
			V3DTest::AssertOk(*fileList[2] == V3DString("test2.txt"), V3DFILE_INFO);
			V3DTest::AssertOk(*fileList[3] == V3DString("testData.dat"), V3DFILE_INFO);
		}
	}

	void V3DFolderTests::RunAllUnitTests()
	{
		FolderTest();
	}

	void V3DFolderTests::RegisterIntegrationTests()
	{
	}

	void V3DFolderTests::RegisterTimingTests()
	{
	}
}
