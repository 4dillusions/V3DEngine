/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DTextRW.h"
#include "V3DEngine/V3DIO/V3DLogger.h"

#include <fstream>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DIO
{
	V3DString* V3DTextRW::Read(V3DAssetPathType path, const char* fileName)
	{
		const auto result = V3DMemory::New<V3DString>(V3DFILE_INFO);

		V3DString fileFullName;
		fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		fileFullName += fileName;
		
		std::ifstream stream(fileFullName.ToChar(), std::ios::in);
		if (stream.is_open())
		{
			std::string line;
			while (std::getline(stream, line))
				*result += V3DString(line.c_str()) + "\n";

			stream.close();
		}
		else
		{
			V3DString log = V3DString("Couldn't open file: ");
			log += fileFullName;
			
			V3DLogger::Get().WriteOutput(V3DLogMessageType::Error, log);
		}

		return result;
	}

	void V3DTextRW::Write(const char* fileName, const V3DString& text)
	{
		V3DString fileFullName;
		fileFullName += fileName;

		std::ofstream ofs(fileFullName.ToChar(), std::ofstream::out);
		ofs << text.ToChar();
		ofs.close();
	}
}
