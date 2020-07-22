/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEnvironment.h"

#include <Windows.h>

namespace V3D::V3DEngine::V3DCore
{
	const char* V3DEnvironment::GetPlatformName() const
	{
		#if defined(_MSVC_LANG)
			#if defined(_WIN64)
				return "Windows x64";
			#else
				return "Windows x86";
			#endif
		#endif

		return "";
	}

	int V3DEnvironment::GetWindowWidth() const
	{
		return windowWidth;
	}

	int V3DEnvironment::GetWindowHeight() const
	{
		return windowHeight;
	}

	int V3DEnvironment::GetScreenWidth() const
	{
		return GetSystemMetrics(SM_CXSCREEN);
	}

	int V3DEnvironment::GetScreenHeight() const
	{
		return GetSystemMetrics(SM_CYSCREEN);
	}
}
