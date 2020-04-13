/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTime.h"

namespace V3D::V3DEngine::V3DCore
{
	V3DTime::V3DTime(int minute, int second) : minute{ minute }, second{ second }
	{ }

	void V3DTime::operator+=(const V3DTime& value)
	{
		minute += value.minute;
		second += value.second;
	}

	bool V3DTime::operator==(const V3DTime& value) const
	{
		return (minute == value.minute && second == value.second);
	}
}
