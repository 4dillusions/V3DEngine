/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DTaskBase.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

#include <functional>

namespace V3D::V3DEngine::V3DThreading
{
	/*
		Task with parameter
	*/
	template <typename TParam> class V3DTask final : public V3DTaskBase
	{
		TParam parameter{};
		std::function<void(TParam)> jobFunctionParametrized = [](const TParam& param) {};

		void Func()
		{
			while (isActive.load())
			{
				jobFunctionParametrized(parameter);
				Wait();
			}
		}

	public:
		V3DTask()
		{
			jobThread = V3DCore::V3DMemory::New<std::thread>(V3DFILE_INFO, &V3DTask::Func, this);
		}

		void SetJobFunction(const std::function<void(TParam)>& job, const TParam& param)
		{
			parameter = param;
			jobFunctionParametrized = job;
			Continue();
		}
	};

	/*
		Task without parameter
	*/
	template <> class V3DTask<void*> final : public V3DTaskBase
	{
		std::function<void()> jobFunction = [] {};

		void Func()
		{
			while (isActive.load())
			{
				jobFunction();
				Wait();
			}
		}

	public:
		V3DTask()
		{
			jobThread = V3DCore::V3DMemory::New<std::thread>(V3DFILE_INFO, &V3DTask::Func, this);
		}

		void SetJobFunction(const std::function<void()>& job)
		{
			jobFunction = job;
			Continue();
		}
	};
}
