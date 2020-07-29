/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DFile.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

#include <filesystem>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	V3DEnvironment* V3DFile::GetEnvironment()
	{
		static auto environment = V3DIoc<V3DEnvironment>::Get();
		return &environment;
	}
	
	bool V3DFile::IsExist(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(GetEnvironment()->GetAssetPath(path));
		fileFullName += fileName;

		return exists(std::filesystem::path(fileFullName.ToChar()));
	}
	
	void V3DFile::Create(const char* fileName)
	{
		auto* const file = std::fopen(fileName, "w+");
		std::fwrite(file, sizeof(char), 0, file);
		std::fclose(file);
	}
	
	void V3DFile::Delete(const char* fileName)
	{
		std::remove(fileName);
	}
}
