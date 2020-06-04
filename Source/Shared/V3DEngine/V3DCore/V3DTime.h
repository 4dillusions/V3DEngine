/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DTime final
	{
	public:
		int minute{}, second{};

		V3DTime() = default;
		V3DTime(int minute, int second);

		void operator+=(const V3DTime& value);
		bool operator==(const V3DTime& value) const;
	};
}
