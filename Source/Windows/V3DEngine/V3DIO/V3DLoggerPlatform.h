/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <fstream>
#include <iostream>

namespace V3D::V3DEngine::V3DIO
{
	using V3DOStream = std::ofstream;

	inline void InitOStream(V3DOStream& oStream)
	{
		oStream = std::ofstream{ L"Log.txt" };
	}

	inline void WriteLineToFile(V3DOStream& oStream, const char* log)
	{
		oStream << log << std::endl;
	}

	inline void WriteLineToOutput(const char* log)
	{
		std::cout << log << std::endl;
	}
}
