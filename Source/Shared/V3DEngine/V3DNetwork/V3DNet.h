/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DNetwork
{
	//definitions will be implement in platform specific .cpp
	class V3DENGINE_API V3DNet final
	{
	public:
		V3DNet() = delete;
		V3DNet(const V3DNet&) = delete;
		V3DNet(V3DNet&&) = delete;
		~V3DNet() = delete;
		V3DNet& operator=(const V3DNet&) = delete;
		V3DNet& operator=(V3DNet&&) = delete;

		static bool Init();
		static void Cleanup();
	};
}
