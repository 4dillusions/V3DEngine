/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	enum class V3DMemoryAllocatorType : unsigned int;

	struct V3DMemoryInfo final
	{
		const char* info;
		V3DMemoryAllocatorType allocType;
	};
}
