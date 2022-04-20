/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DCore/V3DString.h"

#include <filesystem>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	bool V3DFile::IsExist(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		fileFullName += fileName;

		return exists(std::filesystem::path(fileFullName.ToChar()));
	}

	long V3DFile::GetSize(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		fileFullName += fileName;

		if (!exists(std::filesystem::path(fileFullName.ToChar())))
			return -1;
		
		return std::filesystem::file_size(fileFullName.ToChar());  // NOLINT(bugprone-narrowing-conversions, cppcoreguidelines-narrowing-conversions, clang-diagnostic-shorten-64-to-32)
	}
	
	void V3DFile::Create(const char* fileName)
	{
		auto const file = fopen(fileName, "w+");
		fwrite(file, sizeof(char), 0, file);
		fclose(file);
	}
	
	void V3DFile::Delete(const char* fileName)
	{
		remove(fileName);
	}
}
