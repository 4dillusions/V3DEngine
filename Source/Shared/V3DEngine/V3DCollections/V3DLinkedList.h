/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DLinkedListNode.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngine::V3DCollections
{
	/*
		Linked list data structure with static and dynamic objects.
		Supports deleting nodes while iterate, except RemoveAll

		Mainly use for iterating

		best/worst
		search:		O(n) O(n)
		add:		O(1) O(1)
		remove:		O(1) O(1) (without free data memory)
		index:						no
		static remove/delete:		no
		continuously remove/delete: yes/no
	*/
	template<typename T> class V3DLinkedList final
	{
		V3DLinkedListNode<T>* head{}, * tail{}, * current{};
		int length{};

		V3DLinkedListNode<T>* CreateNode()
		{
			return V3DCore::V3DMemory::New<V3DLinkedListNode<T>>(V3DFILE_INFO);
		}

		static void InsertNode(V3DLinkedListNode<T>* prevNode, V3DLinkedListNode<T>* nextNode, V3DLinkedListNode<T>* node)
		{
			prevNode->next = node;
			nextNode->prev = node;

			node->prev = prevNode;
			node->next = nextNode;
		}

		static void LinkNodes(V3DLinkedListNode<T>* prevNode, V3DLinkedListNode<T>* nextNode)
		{
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}

		static void DeleteNode(V3DLinkedListNode<T>*& node)
		{
			V3DCore::V3DMemory::Delete(node);
		}

		void DeleteNodeFromList(V3DLinkedListNode<T>* node)
		{
			if (length > 1)
				LinkNodes(node->prev, node->next);
			else
			{
				head->next = nullptr;
				tail->prev = nullptr;
			}

			DeleteNode(node);
		}

	public:
		V3DLinkedList<T>(const V3DLinkedList<T>&) = delete;
		V3DLinkedList<T>(V3DLinkedList<T>&&) = delete;
		V3DLinkedList<T>& operator=(const V3DLinkedList<T>&) = delete;
		V3DLinkedList<T>& operator=(V3DLinkedList<T>&&) = delete;

		V3DLinkedList()
		{
			head = CreateNode();
			tail = CreateNode();
		}

		~V3DLinkedList()
		{
			RemoveAll();

			DeleteNode(head);
			DeleteNode(tail);
		}

		int GetLength() const
		{
			return length;
		}

		void First()
		{
			current = head != nullptr ? head->next : nullptr;
		}

		bool IsDone()
		{
			return current != nullptr && current->dataFlag != nullptr;
		}
		
		void Next()
		{
			current = current->next;
		}

		T* GetCurrent()
		{
			if (current != nullptr)
				return &current->data;

			return nullptr;
		}

		void Add(const T& item)
		{
			auto node = CreateNode();
			node->data = item;
			node->dataFlag = &const_cast<T&>(item);

			if (head->next == nullptr)
				InsertNode(head, tail, node);
			else
				InsertNode(tail->prev, tail, node);
			
			length++;
		}

		void RemoveCurrent()
		{
			auto temp = current;
			current = current->prev;

			DeleteNodeFromList(temp);
			length--;
		}

		void RemoveAll()
		{
			if (length == 0)
				return;
			
			auto node = head->next;
			V3DLinkedListNode<T>* temp;
			while(node->dataFlag != nullptr)
			{
				temp = node;
				node = node->next;
				DeleteNode(temp);
			}

			head->next = nullptr;
			tail->prev = nullptr;

			length = 0;
		}
	};
}
