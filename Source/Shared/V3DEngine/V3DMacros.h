/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D
{
	#if defined(_MSVC_LANG)
		#if defined(_WIN64)
			#define V3DPLATFORM "Windows x64"
		#else
			#define V3DPLATFORM "Windows x86"
		#endif
	#endif

	#if defined(__clang__)
		#if defined(__aarch64__)
			#define V3DPLATFORM "Android ARM64"
		#endif
		#if defined(__arm__)
			#define V3DPLATFORM "Android ARM"
		#endif
		#if defined(__i386__)
			#define V3DPLATFORM "Android x86"
		#endif
	#endif

	#ifdef _DEBUG
		#define V3DRUN_MODE "DEBUG"
	#else
		#define V3DRUN_MODE "RELEASE"
	#endif

	#define V3DPLATFORM_INFO " (" V3DRUN_MODE " " V3DPLATFORM ")"
	
	//analyzer macro for UnitTest and MemoryManager
	#define V3DSTRINGIFY(x) #x
	#define V3DTOSTRING(x) V3DSTRINGIFY(x)
	#define V3DFILE_INFO __FILE__ ": " V3DTOSTRING(__LINE__)
}
