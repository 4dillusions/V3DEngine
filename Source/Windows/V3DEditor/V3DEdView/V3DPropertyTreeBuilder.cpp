/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DPropertyTreeBuilder.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DIO/V3DJsonIO.h"
#include "V3DEngine/V3DMacros.h"

#include "ThirdParty/Json/json.hpp"

#include <QTreeWidget>
#include <QHeaderView>

using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DIO;

using json = nlohmann::json;

namespace V3D::V3DEditor::V3DEdView
{
	// ReSharper disable once CppMemberFunctionMayBeStatic
	void V3DPropertyTreeBuilder::InitTreeWidget(const QTreeWidget* treeWidget)
	{
		treeWidget->headerItem()->setText(0, "Property");
		treeWidget->headerItem()->setText(1, "Value");
		treeWidget->header()->resizeSections(QHeaderView::ResizeToContents);
	}

	json* V3DPropertyTreeBuilder::BuildTreeWidget(const char* jsonText, const QTreeWidget* treeWidget) const
	{
		const auto result = V3DMemory::New<json>(V3DFILE_INFO, V3DJsonIO::GetJsonObject(jsonText));

		return result;
	}
}
