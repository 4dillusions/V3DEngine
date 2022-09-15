/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEdViewBindings.h"

#include "V3DEditor/V3DEdModel/V3DEdCommands.h"
#include "V3DEditor/V3DEdModel/V3DEdBindingModel.h"
#include "V3DEngine/V3DCore/V3DAction.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DCore/V3DTuple.h"
#include "V3DEngine/V3DCore/V3DString.h"
#include "V3DEngine/V3DCollections/V3DDecimalTree.h"
#include "V3DEngine/V3DCollections/V3DDynamicArray.h"

#include <QListWidget>

using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEditor::V3DEdView
{
	using BindingList = V3DDecimalTree<V3DEdCommands, V3DTuple2<V3DEdBindingModel, V3DAction2<void* /*widget*/, void* /*data*/>>>;

	V3DEdViewBindings::V3DEdViewBindings()
	{
		bindings = V3DMemory::New<BindingList>(V3DFILE_INFO);
	}

	V3DEdViewBindings::~V3DEdViewBindings()
	{
		V3DMemory::Delete(bindings);
	}

	void V3DEdViewBindings::AddBinding(V3DEdCommands command, const V3DEdBindingModel& bindingModel) const
	{
		const auto Tree = static_cast<BindingList*>(bindings);
		V3DAction2<void*, void*> action;
		
		switch (command)
		{
			case V3DEdCommands::AddEngineLogItem:
			case V3DEdCommands::AddOutputLogItem:
				action.Set([this](void* widget, void* data) { UpdateAddLogItem(widget, data); });
				break;

			case V3DEdCommands::ClearEngineLogItem:
			case V3DEdCommands::ClearOutputLogItem:
				action.Set([this](void* widget, void* data) { UpdateClearLogItem(widget, data); });
				break;
		}

		Tree->Add(command, V3DTuple::Create(bindingModel, action));
	}

	void V3DEdViewBindings::Update(V3DEdCommands command) const
	{
		const auto Tuple = static_cast<BindingList*>(bindings)->GetItem(command);
		if (Tuple != nullptr)
			Tuple->item2.Invoke(Tuple->item1.widget, Tuple->item1.data);
	}

	void V3DEdViewBindings::RemoveBindings(const void* view) const
	{
		const auto Tree = static_cast<BindingList*>(bindings);
		for (Tree->First(); Tree->IsDone(); Tree->Next())
			if (Tree->GetCurrentItem()->item1.view == view)
				Tree->RemoveCurrent();
	}

	void V3DEdViewBindings::UpdateAddLogItem(void* widget, void* data) const
	{
		const auto EngineLog = static_cast<V3DDynamicArray<V3DString>*>(data);
		const auto ListEngineLog = static_cast<QListWidget*>(widget);

		if (ListEngineLog->count() < EngineLog->GetLength())
		{
			const QString Log((*EngineLog)[EngineLog->GetLength() - 1]->ToChar());
			ListEngineLog->addItem(Log);

			if (Log.contains("Info"))
				ListEngineLog->item(ListEngineLog->count() - 1)->setForeground(QColor::fromRgb(255, 255, 255)); //white
			else if (Log.contains("Warning"))
				ListEngineLog->item(ListEngineLog->count() - 1)->setForeground(QColor::fromRgb(0, 255, 0)); //green
			else if (Log.contains("Error"))
				ListEngineLog->item(ListEngineLog->count() - 1)->setForeground(QColor::fromRgb(255, 180, 180)); //red
		}
	}

	// ReSharper disable once CppMemberFunctionMayBeStatic
	void V3DEdViewBindings::UpdateClearLogItem(void* widget, void* data) const
	{
		const auto EngineLog = static_cast<V3DDynamicArray<V3DString>*>(data);
		const auto ListEngineLog = static_cast<QListWidget*>(widget);

		if (EngineLog->GetLength() == 0)
			ListEngineLog->clear();
	}
}
