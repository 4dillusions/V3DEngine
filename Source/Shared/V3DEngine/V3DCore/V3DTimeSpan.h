/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	struct V3DENGINE_API V3DTimeSpan
	{
		int year;
		int month;
		int day;
		int hour;
		int min;
		int sec;
		int millisec;
	};
}
