/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DWatch.h"

namespace V3D::V3DEngine::V3DCore
{
	V3DWatch::V3DWatch(const V3DTime& time, const V3DTime& minTime, const V3DTime& maxTime) : time{ time }, minTime{ minTime }, maxTime{ maxTime }
	{
		changerTime = V3DTime{};
	}

	void V3DWatch::SetAlarmEvent(const std::function<void()>& alarmEvent)
	{
		this->alarmEvent = alarmEvent;
	}

	const V3DTime& V3DWatch::GetTime() const
	{
		return time;
	}

	void V3DWatch::Reset()
	{
		time = V3DTime{};
		changerTime = V3DTime{};
	}

	void V3DWatch::ChangeTime(const V3DTime& value)
	{
		time += value;

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

		if (time == minTime || time == maxTime)
			if (alarmEvent != nullptr)
				alarmEvent();
	}

	V3DWatch& V3DWatch::operator++(int)
	{
		changerTime.second = 1;
		ChangeTime(changerTime);

		return *this;
	}

	V3DWatch& V3DWatch::operator--(int)
	{
		changerTime.second = -1;
		ChangeTime(changerTime);

		return *this;
	}

	bool V3DWatch::IsMin() const
	{
		return time == minTime;
	}

	bool V3DWatch::IsMax() const
	{
		return time == maxTime;
	}
}
