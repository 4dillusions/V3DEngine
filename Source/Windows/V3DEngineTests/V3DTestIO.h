/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngineTests/V3DITestIO.h"
#include <iostream>

namespace V3D::V3DEngineTests
{
	class V3DTestIO final : public V3DITestIO<V3DTestIO>
	{	
		std::string ConvertToString(int value) override
		{
			return std::to_string(value);
		}
		
		void WriteOutput(const std::string& text) override
		{
			std::cout << text << std::endl;
		}
	};
}
