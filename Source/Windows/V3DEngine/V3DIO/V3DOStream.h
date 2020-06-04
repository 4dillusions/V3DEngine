/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DIO/V3DIOStream.h"

#include <fstream>
#include <iostream>

namespace V3D::V3DEngine::V3DIO
{
	class V3DOstream final : public V3DIOstream
	{
		std::ofstream oStream;
		
	public:
		V3DOstream()
		{
			oStream = std::ofstream{ L"Log.txt" };
		}
		
		void WriteLineToFile(const char* log) override
		{
			oStream << log << std::endl;
		}

		void WriteLineToOutput(const char* log) override
		{
			std::cout << log << std::endl;
		}
	};
}
