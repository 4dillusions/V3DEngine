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
		V3DTest::AssertOk(!V3DFolder::IsExist(V3DAssetPathType::Internal), V3DFILE_INFO);

		auto fileList = V3DFolder::GetFileList(V3DAssetPathType::Options);
		V3DTest::AssertOk(fileList.GetLength() == 2, V3DFILE_INFO);

		if (fileList.GetLength() == 2)
		{
			V3DTest::AssertOk(*fileList[0] == V3DString("test.txt"), V3DFILE_INFO);
			V3DTest::AssertOk(*fileList[1] == V3DString("test2.txt"), V3DFILE_INFO);
		}
	}

	void V3DFolderTests::RunAllTests()
	{
		FolderTest();
	}
}
