/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DIO/V3DLogger.h"

#include <fstream>
#include <iostream>

namespace V3D::V3DEngine::V3DIO
{
	void V3DLogger::WriteLineToFile(const char* log)
	{
		static auto oStream = std::ofstream{ L"Log.txt" };
		oStream << log << std::endl;
	}

	void V3DLogger::WriteLineToOutput(const char* log)
	{
		std::cout << log << std::endl;
	}
}
