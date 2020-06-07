/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DTimeHour final
	{
	public:
		int minute{}, second{};

		V3DTimeHour() = default;
		V3DTimeHour(int minute, int second);

		bool operator==(const V3DTimeHour& value) const;

		void Clamp();
	};
}
