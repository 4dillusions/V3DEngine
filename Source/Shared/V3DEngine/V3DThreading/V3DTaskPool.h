/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include  "V3DTask.h"

namespace V3D::V3DEngine::V3DThreading
{
	/*
		Based on static array datastructure for Tasks
		Set job funcion starts newer job on free slot of Task array
		After the job finish the Task slot wait for next job
	*/
	template <typename TParam = void*> class V3DTaskPool final
	{
		V3DTask<TParam>** data{};
		const int PoolSize{ 0 };

	public:
		V3DTaskPool() = delete;
		V3DTaskPool(const V3DTaskPool&) = delete;
		V3DTaskPool(V3DTaskPool&&) = delete;
		V3DTaskPool& operator=(const V3DTaskPool&) = delete;
		V3DTaskPool& operator=(V3DTaskPool&&) = delete;

		explicit V3DTaskPool(const int poolSize) : data(V3DCore::V3DMemory::NewPointerArray<V3DTask<TParam>>(V3DFILE_INFO, poolSize)), PoolSize{ poolSize }
		{
			for (int i = 0; i < poolSize; i++)
			{
				data[i] = V3DCore::V3DMemory::New<V3DTask<TParam>>(V3DFILE_INFO);
			}
		}

		~V3DTaskPool()
		{
			for (int i = 0; i < PoolSize; i++)
			{
				V3DCore::V3DMemory::Delete(data[i]);
			}

			V3DCore::V3DMemory::DeletePointerArray(data);
		}

	private:
		int GetAvailableTaskIndex() const
		{
			int index = 0;
			while (data[index]->GetIsWorking())
			{
				index++;
				if (index == PoolSize)
					index = 0;
			}

			return index;
		}

	public:
		void SetJobFunction(const std::function<void()>& jobFunction) const
		{
			int index = GetAvailableTaskIndex();
			data[index]->SetJobFunction(jobFunction);
		}

		void SetJobFunction(const std::function<void(TParam)>& jobFunction, const TParam& param) const
		{
			int index = GetAvailableTaskIndex();
			data[index]->SetJobFunction(jobFunction, param);
		}
	};
}
