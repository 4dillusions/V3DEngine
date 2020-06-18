/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DLinkedListNode.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngine::V3DCollections
{
	/**
		Linked list data structure with static and dynamic objects.
		Supports delete items while iterate, except RemoveAll/DeleteAll

		Mainly use for iterating

		best/worst
		search:		O(n) O(n)
		add:		O(1) O(1) (without memory allocation)
		remove:		O(1) O(1) (without free memory)
		index:						no
		static remove/delete:		no
		continuously remove/delete: no/yes
	*/
	template<typename T> class V3DLinkedList final
	{
		V3DLinkedListNode<T>* head{}, * tail{}, * current{};
		int length{};

		V3DLinkedListNode<T>* CreateNode()
		{
			return V3DCore::V3DMemory::New<V3DLinkedListNode<T>>(V3DFILE_INFO);
		}

	public:
		V3DLinkedList<T>(const V3DLinkedList<T>&) = delete;
		V3DLinkedList(V3DLinkedList<T>&&) = delete;
		V3DLinkedList<T>& operator=(const V3DLinkedList<T>&) = delete;
		V3DLinkedList<T>& operator=(V3DLinkedList<T>&&) = delete;

		V3DLinkedList()
		{
			head = CreateNode();
			tail = CreateNode();
		}

		~V3DLinkedList()
		{
			V3DCore::V3DMemory::Delete(head);
			V3DCore::V3DMemory::Delete(tail);

			DeleteAll();
		}

		[[nodiscard]] int GetLength() const
		{
			return length;
		}

		void Add(const T& item)
		{
			//TODO
			auto node = CreateNode();

			//node->data = item;
			//node->SetData(const_cast<T&>(item));

			node->data = nullptr;

			length++;
		}

		void DeleteCurrent()
		{
			//TODO
		}

		void DeleteAll()
		{
			if (length == 0)
				return;
			
			//TODO

			length = 0;
		}
	};
}