/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdMainService.h"

#include "V3DEditor/V3DEdCore/V3DEdIViewManager.h"

using namespace V3D::V3DEditor::V3DEdCore;

namespace V3D::V3DEditor::V3DEdService
{
	V3DEdMainService::V3DEdMainService(V3DEdIViewManager* viewManager) : viewManager{ viewManager }
	{ }

	void V3DEdMainService::AboutEditor() const
	{
		viewManager->ShowAboutEditorView();
	}

	void V3DEdMainService::AboutQt() const
	{
		viewManager->ShowAboutQtView();
	}
}
