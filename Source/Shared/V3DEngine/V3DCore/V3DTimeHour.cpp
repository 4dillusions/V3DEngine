/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTimeHour.h"
#include "V3DEngine/V3DMathematics/V3DMath.h"

using namespace V3D::V3DEngine::V3DMathematics;

namespace V3D::V3DEngine::V3DCore
{
	V3DTimeHour::V3DTimeHour(int minute, int second) : minute{ minute }, second{ second }
	{
		Clamp();
	}

	bool V3DTimeHour::operator==(const V3DTimeHour& value) const
	{
		return (minute == value.minute && second == value.second);
	}
	
	void V3DTimeHour::Clamp()
	{
		minute = V3DMath::Clamp(minute, 0, 59);
		second = V3DMath::Clamp(second, 0, 59);
	}
}
