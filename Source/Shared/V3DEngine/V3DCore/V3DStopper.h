/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DStopper final
	{
		long long lastTime{}, currentTime{}, deltaTime{};

		static long long GetActualTimeMsec();
		
	public:
		V3DStopper();
		V3DStopper(const V3DStopper&) = delete;
		V3DStopper(V3DStopper&&) = delete;
		~V3DStopper() = default;
		V3DStopper& operator=(const V3DStopper&) = delete;
		V3DStopper& operator=(V3DStopper&&) = delete;	

		long long GetDeltaTimeMsec();
		
		void Reset();
	};
}
