/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DWatchHour.h"

namespace V3D::V3DEngine::V3DCore
{
	V3DWatchHour::V3DWatchHour(const V3DTimeHour& time, const V3DTimeHour& minTime, const V3DTimeHour& maxTime) : time{ time }, minTime{ minTime }, maxTime{ maxTime }
	{ }

	void V3DWatchHour::SetMinTimeEvent(const std::function<void()>& minTimeEvent)
	{
		this->minTimeEvent = minTimeEvent;
	}

	void V3DWatchHour::SetMaxTimeEvent(const std::function<void()>& maxTimeEvent)
	{
		this->maxTimeEvent = maxTimeEvent;
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
		time = minTime;
	}

	void V3DWatchHour::SetToMax()
	{
		time = maxTime;
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

		if (time == minTime)
			if (minTimeEvent != nullptr)
				minTimeEvent();

		if (time == maxTime)
			if (maxTimeEvent != nullptr)
				maxTimeEvent();
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
