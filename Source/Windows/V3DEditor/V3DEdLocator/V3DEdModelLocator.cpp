/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdModelLocator.h"
#include "V3DEditor/V3DEdModel/V3DEdMainModel.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEditor::V3DEdLocator
{
	V3DEdMainModel* V3DEdModelLocator::CreateOrGetMainModel()
	{
		if (mainModel == nullptr)
			mainModel = V3DMemory::New<V3DEdMainModel>(V3DFILE_INFO);

		return mainModel;
	}

	void V3DEdModelLocator::ReleaseMainModel()
	{
		V3DMemory::Delete(mainModel);
	}
}
