/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTimeHour.h"

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DWatchHour final
	{
		V3DTimeHour time;
		const V3DTimeHour MinTime, MaxTime;
		std::function<void()> minTimeEvent = nullptr;
		std::function<void()> maxTimeEvent = nullptr;

		void ChangeTime();

	public:
		V3DWatchHour(const V3DWatchHour&) = delete;
		V3DWatchHour(V3DWatchHour&&) = delete;
		~V3DWatchHour() = default;
		V3DWatchHour& operator=(const V3DWatchHour&) = delete;
		V3DWatchHour& operator=(V3DWatchHour&&) = delete;
		
		explicit V3DWatchHour(const V3DTimeHour& currentTime, const V3DTimeHour& minTime = V3DTimeHour{}, const V3DTimeHour& maxTime = V3DTimeHour{});

		void SetMinTimeEvent(const std::function<void()>& minTimeEvent);
		void SetMaxTimeEvent(const std::function<void()>& maxTimeEvent);
		const V3DTimeHour& GetTime() const;
		
		void SetToZero();
		void SetToMin();
		void SetToMax();
		void IncreaseSeconds();
		void DecreaseSeconds();
	};
}
