/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#ifdef WINCLASSIC
	#define WIN32_LEAN_AND_MEAN
	//#include <windows.h>

	#ifdef V3DENGINE_EXPORTS
		#define V3DENGINE_API __declspec(dllexport)
	#else
		#define V3DENGINE_API __declspec(dllimport)
	#endif
#else
	#define V3DENGINE_API /**/
#endif

namespace V3DEngine
{
	class V3DENGINE_API V3DEngineTest
	{
	public:
		int Test(int a, int b);
	};
}
