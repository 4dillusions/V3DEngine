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
#include "V3DEngine/V3DCollections/V3DLinkedList.h"

#include <QListWidget>
#include <QMap>

using namespace V3D::V3DEditor::V3DEdModel;
using namespace V3D::V3DEngine::V3DCore;
using namespace V3D::V3DEngine::V3DCollections;

namespace V3D::V3DEditor::V3DEdView
{
	using BindingList = V3DDecimalTree<V3DEdCommands, V3DTuple2<V3DEdBindingModel, V3DAction2<void* /*widget*/, void* /*data*/>>>;

	using CanExecuteLinkedList = V3DLinkedList<V3DTuple2<V3DEdBindingModel, V3DAction2<void* /*widget*/, void* /*data*/>>>;
	using CanExecuteMap = QMap<void*, CanExecuteLinkedList*>;

	V3DEdViewBindings::V3DEdViewBindings()
	{
		bindings = V3DMemory::New<BindingList>(V3DFILE_INFO);
		canExecutes = V3DMemory::New<CanExecuteMap>(V3DFILE_INFO);
	}

	V3DEdViewBindings::~V3DEdViewBindings()
	{
		auto bindingList = static_cast<BindingList*>(bindings);
		V3DMemory::Delete(bindingList);

		auto canExecuteMap = static_cast<CanExecuteMap*>(canExecutes);
		V3DMemory::Delete(canExecuteMap);
	}

	void V3DEdViewBindings::AddBinding(V3DEdCommands command, const V3DEdBindingModel& bindingModel) const
	{
		const auto BindingsTree = static_cast<BindingList*>(bindings);
		V3DAction2<void*, void*> bindingAction;

		const auto CanExecutesMap = static_cast<CanExecuteMap*>(canExecutes);
		V3DAction2<void*, void*> canExecuteAction;
		
		switch (command)
		{
			case V3DEdCommands::AddEngineLogItem:
			case V3DEdCommands::AddOutputLogItem:
				bindingAction.Set([this](void* widget, void* data) { UpdateAddLogItem(widget, data); });
				break;

			case V3DEdCommands::ClearEngineLogItem:
			case V3DEdCommands::ClearOutputLogItem:
				bindingAction.Set([this](void* widget, void* data) { static_cast<QListWidget*>(widget)->clear(); });
				canExecuteAction.Set([this](void* widget, void* data) { static_cast<QWidget*>(widget)->setEnabled(static_cast<V3DDynamicArray<V3DString>*>(data)->GetLength() > 0); });
				break;
		}

		if (!bindingAction.IsEmpty())
			BindingsTree->Add(command, V3DTuple::Create(bindingModel, bindingAction));

		if (!canExecuteAction.IsEmpty())
		{
			const auto CanExecuteTupleItem = CanExecutesMap->insert(bindingModel.data, V3DMemory::New<CanExecuteLinkedList>(V3DFILE_INFO));
			CanExecuteTupleItem.value()->Add(V3DTuple::Create(bindingModel, canExecuteAction));
		}
	}

	void V3DEdViewBindings::UpdateCanExecuteBindings(const void* view) const
	{
		const auto CanExecutesMap = static_cast<CanExecuteMap*>(canExecutes);
		for (CanExecuteMap::Iterator it = CanExecutesMap->begin(); it != CanExecutesMap->end(); ++it)
		{
			const auto CanExecuteLinkedList = it.value();
			for (CanExecuteLinkedList->First(); CanExecuteLinkedList->IsDone(); CanExecuteLinkedList->Next())
				if (CanExecuteLinkedList->GetCurrent()->item1.view == view)
					CanExecuteLinkedList->GetCurrent()->item2.Invoke(CanExecuteLinkedList->GetCurrent()->item1.executeWidget, CanExecuteLinkedList->GetCurrent()->item1.data);
		}
	}

	void V3DEdViewBindings::Update(V3DEdCommands command) const
	{
		const auto BindingsTuple = static_cast<BindingList*>(bindings)->GetItem(command);
		if (BindingsTuple != nullptr)
		{
			BindingsTuple->item2.Invoke(BindingsTuple->item1.dataWidget, BindingsTuple->item1.data);

			const auto CanExecutesMap = static_cast<CanExecuteMap*>(canExecutes);
			const auto CanExecuteItem = CanExecutesMap->find(BindingsTuple->item1.data);
			if (CanExecuteItem != CanExecutesMap->end())
				for (CanExecuteItem.value()->First(); CanExecuteItem.value()->IsDone(); CanExecuteItem.value()->Next())
					if (BindingsTuple->item1.data == CanExecuteItem.value()->GetCurrent()->item1.data)
						CanExecuteItem.value()->GetCurrent()->item2.Invoke(CanExecuteItem.value()->GetCurrent()->item1.executeWidget, CanExecuteItem.value()->GetCurrent()->item1.data);
		}
	}

	void V3DEdViewBindings::RemoveBindings(const void* view) const
	{
		const auto BindingsTree = static_cast<BindingList*>(bindings);
		for (BindingsTree->First(); BindingsTree->IsDone(); BindingsTree->Next())
			if (BindingsTree->GetCurrentItem()->item1.view == view)
				BindingsTree->RemoveCurrent();

		const auto CanExecutesMap = static_cast<CanExecuteMap*>(canExecutes);
		for (CanExecuteMap::Iterator it = CanExecutesMap->begin(); it != CanExecutesMap->end();)
		{
			it.value()->First();
			if (it.value()->GetCurrent()->item1.view == view)
			{
				V3DMemory::Delete(it.value());
				CanExecutesMap->remove(it++.key());
			}
			else
			{
				++it;
			}
		}
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
}
