/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DStopper.h"

#include <chrono>

using namespace std::chrono;

namespace V3D::V3DEngine::V3DCore
{
	V3DStopper::V3DStopper()
	{
		Reset();
	}

	long long V3DStopper::GetActualTimeMsec()
	{
		return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
	}

	long long V3DStopper::GetDeltaTimeMsec()
	{
		currentTime = GetActualTimeMsec();

		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		return deltaTime;
	}

	void V3DStopper::Reset()
	{
		lastTime = GetActualTimeMsec();

		currentTime = 0;
		deltaTime = 0;
	}
}