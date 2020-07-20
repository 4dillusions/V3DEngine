/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DOstream.h"

#include <fstream>
#include <iostream>

using namespace std;

namespace V3D::V3DEngine::V3DIO
{
	V3DOstream::V3DOstream()
	{
		oStream = std::ofstream{ L"Log.txt" };
	}

	void V3DOstream::WriteLineToFile(const char* log)
	{
		oStream << log << std::endl;
	}

	void V3DOstream::WriteLineToOutput(const char* log)
	{
		std::cout << log << std::endl;
	}
}
