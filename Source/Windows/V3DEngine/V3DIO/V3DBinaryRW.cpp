/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DBinaryRW.h"
#include "V3DEngine/V3DIO/V3DLogger.h"
#include "V3DEngine/V3DCore/V3DString.h"

#include <fstream>

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DIO
{
	char* V3DBinaryRW::Read(V3DAssetPathType path, const char* fileName, unsigned int* lenghtOut)
	{
		char* result{};

		V3DString fileFullName;
		fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		fileFullName += fileName;

		std::ifstream stream(fileFullName.ToChar(), std::ios::binary);
		if (stream)
		{
			stream.seekg(0, std::ifstream::end);
			const auto length = stream.tellg();
			stream.seekg(0, std::ifstream::beg);

			if (lenghtOut != nullptr)
				*lenghtOut = static_cast<unsigned int>(length);

			result = V3DMemory::NewArray<char>(V3DFILE_INFO, static_cast<unsigned int>(length));
			stream.read(result, length);
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

	void V3DBinaryRW::Write(const char* fileName, const char* data, unsigned int size, unsigned int offset)
	{
		V3DString fileFullName;		
		fileFullName += fileName;

		const std::ofstream::openmode flags = offset == 0 ? std::ofstream::binary : std::ofstream::binary | std::ofstream::out | std::ofstream::app;
		std::ofstream outfile(fileFullName.ToChar(), flags);

		outfile.seekp(offset, std::ofstream::beg);
		outfile.write(data, size);
		outfile.close();
	}
}
