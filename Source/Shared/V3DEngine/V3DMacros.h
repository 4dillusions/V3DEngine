/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D
{
	//analyzer macro for UnitTest and MemoryManager
	#define V3DSTRINGIFY(x) #x
	#define V3DTOSTRING(x) V3DSTRINGIFY(x)
	#define V3DFILE_INFO __FILE__ ": " V3DTOSTRING(__LINE__)
}
