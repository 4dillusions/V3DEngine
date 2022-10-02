/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	enum class V3DAssetPathType : unsigned int
	{
		//Content
		Model,
		Shader,
		Sound,
		Texture,

		//Data
		Level,
		Options,
		Physics,
		UI,

		AllFolderCount,

		//root
		Internal,

		//special folder for editor only
		EditorContent
	};
}
