/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdEnvironment.h"
#include "V3DEdAssetPathType.h"
#include "V3DEngine/V3DCore/V3DString.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEditor::V3DEdCore
{
	const char* V3DEdEnvironment::GetEditorStyleFileName()
	{
		return "V3DEditorStyle.json";
	}

	const char* V3DEdEnvironment::GetAssetPath(V3DEdAssetPathType assetPath)
	{
		switch (assetPath)
		{
			case V3DEdAssetPathType::EditorLogo: return "Assets/EditorContent/V3DLogoLarge.png";
			case V3DEdAssetPathType::EditorSkinStyle: return "Assets/EditorContent/darkorange.qss";
		}

		return "default";
	}

	const char* V3DEdEnvironment::GetFileFullName(V3DAssetPathType path, const char* fileName)
	{
		V3DString fileFullName;
		fileFullName += V3DString(V3DEnvironment::GetAssetPath(path));
		fileFullName += fileName;

		return fileFullName.ToChar();
	}

}
