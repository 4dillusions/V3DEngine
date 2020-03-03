/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#pragma warning(disable:4251) //'identifier' : class 'type' needs to have dll-interface to be used by clients of class 'type2'
#pragma warning(disable:4530) //C++ exception handler used, but unwind semantics are not enabled.Specify / EHsc

#define WIN32_LEAN_AND_MEAN
//#include <windows.h>

#ifdef V3DENGINE_EXPORTS
	#define V3DENGINE_API __declspec(dllexport)
#else
	#define V3DENGINE_API __declspec(dllimport)
#endif
