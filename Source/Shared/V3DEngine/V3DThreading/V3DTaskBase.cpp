/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTaskBase.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace std;

namespace V3D::V3DEngine::V3DThreading
{
	V3DTaskBase::~V3DTaskBase()
	{
		if (jobThread != nullptr)
		{
			if (jobThread->joinable())
			{
				isActive.store(false);
				Continue();
				jobThread->join();

				V3DCore::V3DMemory::Delete(jobThread);
			}
		}
	}
	
	bool V3DTaskBase::GetIsWorking()
	{
		unique_lock lock(conditionMutex);
		return isWorking.load();
	}
	
	void V3DTaskBase::Wait()
	{
		unique_lock locker(conditionMutex);
		isWorking.store(false);
		condition.wait(locker, [&] { return !isNeedWait.load(); });
		isNeedWait.store(true);
	}
	
	void V3DTaskBase::Continue()
	{
		isNeedWait.store(false);
		isWorking.store(true);
		condition.notify_all();
	}
}
