/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEnvironment.h"

namespace V3D::V3DEngine::V3DCore
{
	const char* V3DEnvironment::GetPlatformName() const
	{
		#if defined(__clang__)
			#if defined(__aarch64__)
				return "Android ARM64";
			#endif
			#if defined(__arm__)
				return "Android ARM";
			#endif
			#if defined(__i386__)
				return "Android x86";
			#endif
		#endif

		return "";
	}

	int V3DEnvironment::GetWindowWidth() const
	{
		return GetScreenWidth();
	}
	
	int V3DEnvironment::GetWindowHeight() const
	{
		return GetScreenHeight();
	}
	
	int V3DEnvironment::GetScreenWidth() const
	{
		return screenWidth;
	}
	
	int V3DEnvironment::GetScreenHeight() const
	{
		return screenHeight;
	}
}
