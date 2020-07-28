/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEnvironment.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

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

	const char* V3DEnvironment::GetAssetPath(V3DAssetPathType assetPath) const
	{
		switch (assetPath)
		{
		case V3DAssetPathType::Sound: return "Assets\\Content\\Sound\\";
		case V3DAssetPathType::Texture: return "Assets\\Content\\Texture\\";
		case V3DAssetPathType::Shader: return "Assets\\Content\\Shader\\";
		case V3DAssetPathType::Level: return "Assets\\Data\\Level\\";
		case V3DAssetPathType::Options: return "Assets\\Data\\Options\\";
		case V3DAssetPathType::Physics: return "Assets\\Data\\Physics\\";
		case V3DAssetPathType::UI: return "Assets\\Data\\UI\\";;

		case V3DAssetPathType::Internal: return "";

		default: return "default";
		}
	}
}
