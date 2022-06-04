/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DIocContainer.h"

using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEngine::V3DCore
{
	V3DStack<V3DAction>* V3DIocContainer::removeActionsContainer = nullptr;

	void V3DIocContainer::Init(int size)
	{
		removeActionsContainer = V3DMemory::New<V3DStack<V3DAction>>(V3DFILE_INFO, size);
	}

	void V3DIocContainer::Clean()
	{
		while (auto action = removeActionsContainer->Take())
			if (!action->IsEmpty())
				action->Invoke();

		V3DMemory::Delete(removeActionsContainer);
	}
}
