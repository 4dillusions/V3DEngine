/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

#include <thread>
#include <mutex>
#include <atomic>

namespace V3D::V3DEngine::V3DThreading
{
	/*
		Task starts a thread (jobThread), what runs its' job (jobFunction)		
		When the job finished, then wait for next job (spin lock)
	*/
	class V3DENGINE_API V3DTaskBase
	{
	protected:	
		std::atomic<bool> isActive{ true };
		std::atomic<bool> isNeedWait{ true };
		std::atomic<bool> isWorking{ true };

		std::thread* jobThread{};  // NOLINT(clang-diagnostic-padded)

		std::mutex conditionMutex;
		std::condition_variable condition;
		
		V3DTaskBase() = default;
		
	public:
		V3DTaskBase(const V3DTaskBase&) = delete;
		V3DTaskBase(V3DTaskBase&&) = delete;
		V3DTaskBase& operator=(const V3DTaskBase&) = delete;
		V3DTaskBase& operator=(V3DTaskBase&&) = delete;
		virtual ~V3DTaskBase();
	
		bool GetIsWorking();

	protected:
		void Wait();
		void Continue();
	};
}
