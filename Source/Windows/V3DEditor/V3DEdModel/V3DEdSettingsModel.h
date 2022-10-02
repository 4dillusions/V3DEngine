/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "ThirdParty/Json/json_fwd.hpp"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}
namespace V3D::V3DEditor::V3DEdModel
{
	enum class V3DEdCommands;

	struct V3DEdSettingsModel final
	{
		V3DEdCommands command{};

		V3DEngine::V3DCore::V3DString *editorStyleJsonText{};
		nlohmann::json* editorStyleJson{};

		V3DEngine::V3DCore::V3DString *gameSettingsJsonText{};
		nlohmann::json* gameSettingsJson{};
	};
}
