/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DDynamicArray.h"
#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEditor::V3DEdModel
{
	enum class V3DEdCommands;

	struct V3DEdMainModel final
	{
		V3DEdCommands command{};

		bool isSettingsViewActive{ false };

		V3DEngine::V3DCollections::V3DDynamicArray<V3DEngine::V3DCore::V3DString> engineLog;
		V3DEngine::V3DCollections::V3DDynamicArray<V3DEngine::V3DCore::V3DString> outputLog;
	};
}
