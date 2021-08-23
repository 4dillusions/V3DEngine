/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEnvironment.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

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
			#if defined (_M_X64)
				return "Android x64";
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

	const char* V3DEnvironment::GetAssetPath(V3DAssetPathType assetPath) const
	{
		switch (assetPath)
		{
		case V3DAssetPathType::Sound: return "Content/Sound";
		case V3DAssetPathType::Texture: return "Content/Texture";
		case V3DAssetPathType::Shader: return "Content/Shader";
		case V3DAssetPathType::Level: return "Data/Level";
		case V3DAssetPathType::Options: return "Data/Options";
		case V3DAssetPathType::Physics: return "Data/Physics";
		case V3DAssetPathType::UI: return "Data/UI";

		case V3DAssetPathType::Internal: return "";

		default: return "default";
		}
	}
}
