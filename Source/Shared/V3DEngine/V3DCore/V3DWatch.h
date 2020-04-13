/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTime.h"

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DWatch final
	{
		V3DTime time, minTime, maxTime, changerTime;
		std::function<void()> alarmEvent = nullptr;

		void ChangeTime(const V3DTime& value);

	public:
		V3DWatch(const V3DWatch&) = delete;
		V3DWatch(V3DWatch&&) = delete;
		~V3DWatch() = default;
		V3DWatch& operator=(const V3DWatch&) = delete;
		V3DWatch& operator=(V3DWatch&&) = delete;
		
		explicit V3DWatch(const V3DTime& time, const V3DTime& min = V3DTime{}, const V3DTime& max = V3DTime{});

		void SetAlarmEvent(const std::function<void()>& alarmEvent);
		[[nodiscard]] const V3DTime& GetTime() const;

		void Reset();
		//increase seconds
		V3DWatch& operator++(int);

		//decrease seconds
		V3DWatch& operator--(int);

		[[nodiscard]] bool IsMin() const;
		[[nodiscard]] bool IsMax() const;
	};
}
