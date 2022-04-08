/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEngine/V3DCore/V3DEnvironment.h"
#include "V3DEngine/V3DCore/V3DAssetPathType.h"

#include <Windows.h>

namespace V3D::V3DEngine::V3DCore
{
	const char* V3DEnvironment::GetPlatformName()
	{
		#if defined(_MSVC_LANG)
			#if defined(_WIN64)
				return "Windows x64";
			#else
				return "Windows x86";
			#endif
		#endif
	}

	int V3DEnvironment::GetWindowWidth()
	{
		return windowWidth;
	}

	int V3DEnvironment::GetWindowHeight()
	{
		return windowHeight;
	}

	int V3DEnvironment::GetScreenWidth()
	{
		return GetSystemMetrics(SM_CXSCREEN);
	}

	int V3DEnvironment::GetScreenHeight()
	{
		return GetSystemMetrics(SM_CYSCREEN);
	}

	const char* V3DEnvironment::GetAssetPath(V3DAssetPathType assetPath)
	{
		switch (assetPath)
		{
			case V3DAssetPathType::Model: return R"(Assets\Content\Model\)";
			case V3DAssetPathType::Shader: return R"(Assets\Content\Shader\)";
			case V3DAssetPathType::Sound: return R"(Assets\Content\Sound\)";
			case V3DAssetPathType::Texture: return R"(Assets\Content\Texture\)";

			case V3DAssetPathType::Level: return R"(Assets\Data\Level\)";
			case V3DAssetPathType::Options: return R"(Assets\Data\Options\)";
			case V3DAssetPathType::Physics: return R"(Assets\Data\Physics\)";
			case V3DAssetPathType::UI: return R"(Assets\Data\UI\)";

			case V3DAssetPathType::AllFolderCount: return "AllFolderCount";

			case V3DAssetPathType::Internal: return "";

			//default: return "default";
		}

		return "default";
	}
}
