/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DWatchHour.h"

namespace V3D::V3DEngine::V3DCore
{
	V3DWatchHour::V3DWatchHour(const V3DTimeHour& time, const V3DTimeHour& minTime, const V3DTimeHour& maxTime) : time{ time }, MinTime{ minTime }, MaxTime{ maxTime }
	{ }

	void V3DWatchHour::SetMinTimeAction(const V3DAction& minTimeActionValue)
	{
		minTimeAction.Set(minTimeActionValue);
	}

	void V3DWatchHour::SetMaxTimeAction(const V3DAction& maxTimeActionValue)
	{
		maxTimeAction.Set(maxTimeActionValue);
	}

	const V3DTimeHour& V3DWatchHour::GetTime() const
	{
		return time;
	}

	void V3DWatchHour::SetToZero()
	{
		time = V3DTimeHour{};
	}

	void V3DWatchHour::SetToMin()
	{
		time = MinTime;
	}

	void V3DWatchHour::SetToMax()
	{
		time = MaxTime;
	}

	void V3DWatchHour::ChangeTime()
	{
		if (time.second > 59)
		{
			time.second = 0;
			time.minute++;
		}
		else if (time.second < 0)
		{
			time.second = 59;
			time.minute--;
		}

		time.Clamp();

		if (time == MinTime)
			if (!minTimeAction.IsEmpty())
				minTimeAction.Invoke();

		if (time == MaxTime)
			if (!maxTimeAction.IsEmpty())
				maxTimeAction.Invoke();
	}

	void V3DWatchHour::IncreaseSeconds()
	{
		time.second++;
		ChangeTime();
	}

	void V3DWatchHour::DecreaseSeconds()
	{
		time.second--;
		ChangeTime();
	}
}
