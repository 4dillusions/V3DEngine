/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdControllerLocator.h"
#include "V3DEditor/V3DEdController/V3DEdMainController.h"
#include "V3DEngine/V3DCore/V3DIoc.h"

using namespace V3D::V3DEditor::V3DEdController;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEditor::V3DEdLocator
{
	V3DEdMainController* V3DEdControllerLocator::CreateOrGetMainController()
	{
		if (mainController == nullptr)
			mainController = V3DIoc<V3DEdMainController>::CreateTransient();

		return mainController;
	}

	void V3DEdControllerLocator::ReleaseMainController()
	{
		V3DMemory::Delete(mainController);
	}
}
