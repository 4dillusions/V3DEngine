/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DObjectPoolNode.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngine::V3DCollections
{
	/**
		Linked list data structure with dynamic objects.
		Supports logically fast add/remove functions without memory allocation or free while iterate.

		Mainly use for iterating
		
		best/worst
		search:		O(n) O(n)
		add:		O(1) O(1) (without memory allocation)
		remove:		O(1) O(1) (without free memory)
		index:						no
		static remove/delete:		no
		continuously remove/delete: yes (logically)
	*/
	template<typename T, int poolSize> class V3DObjectPool final
	{
		V3DObjectPoolNode<T>* poolHead{}, * poolTail{}, * head{}, * tail{}, * current{};
		int length{};

		V3DObjectPoolNode<T>* CreateNode()
		{
			return V3DCore::V3DMemory::New<V3DObjectPoolNode<T>>(V3DFILE_INFO);
		}

		T* CreateData()
		{
			return V3DCore::V3DMemory::New<T>(V3DFILE_INFO);
		}

		V3DObjectPoolNode<T>* AddNewNodeWithData(V3DObjectPoolNode<T>* targetNode)
		{
			auto newNode = CreateNode();
			newNode->data = CreateData();

			targetNode->next = newNode;
			newNode->prev = targetNode;

			return newNode;
		}

		static void InsertNode(V3DObjectPoolNode<T>* prevNode, V3DObjectPoolNode<T>* nextNode, V3DObjectPoolNode<T>* node)
		{
			prevNode->next = node;
			nextNode->prev = node;

			node->prev = prevNode;
			node->next = nextNode;
		}

		static void LinkNodes(V3DObjectPoolNode<T>* prevNode, V3DObjectPoolNode<T>* nextNode)
		{
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
		}

		void InsertNodeToPool(V3DObjectPoolNode<T>* node)
		{
			if (poolTail->prev != nullptr)
				InsertNode(poolTail->prev, poolTail, node);
			else
				InsertNode(poolHead, poolTail, node);
		}

		void RemoveNodeFromPool(V3DObjectPoolNode<T>* node)
		{
			if (length < poolSize)
				LinkNodes(node->prev, node->next);
			else
			{
				poolHead->next = nullptr;
				poolTail->prev = nullptr;
			}
		}
		
		void InsertNodeToList(V3DObjectPoolNode<T>* node)
		{
			if (tail->prev != nullptr)
				InsertNode(tail->prev, tail, node);
			else
				InsertNode(head, tail, node);
		}
		
		void RemoveNodeFromList(V3DObjectPoolNode<T>* node)
		{
			if (length > 1)
				LinkNodes(node->prev, node->next);
			else
			{
				head->next = nullptr;
				tail->prev = nullptr;
			}
		}

		void DeleteLinkedNodes(V3DObjectPoolNode<T>* headNode)
		{
			if (headNode == nullptr || headNode->next == nullptr)
				return;

			auto currentHead = headNode->next;
			while (currentHead->data != nullptr)
			{
				auto nextNode = currentHead->next;
				V3DCore::V3DMemory::Delete(currentHead);
				currentHead = nextNode;
			}
		}

	public:
		V3DObjectPool<T, poolSize>(const V3DObjectPool<T, poolSize>&) = delete;
		V3DObjectPool(V3DObjectPool<T, poolSize>&&) = delete;
		V3DObjectPool<T, poolSize>& operator=(const V3DObjectPool<T, poolSize>&) = delete;
		V3DObjectPool<T, poolSize>& operator=(V3DObjectPool<T, poolSize>&&) = delete;

		V3DObjectPool()
		{
			poolHead = CreateNode();
			poolTail = CreateNode();
			head = CreateNode();
			tail = CreateNode();

			auto currentNode = AddNewNodeWithData(poolHead);
			
			for (int i = 0; i < poolSize - 1; i++)
				currentNode = AddNewNodeWithData(currentNode);

			currentNode->next = poolTail;
			poolTail->prev = currentNode;
		}

		~V3DObjectPool()
		{
			DeleteLinkedNodes(poolHead);
			DeleteLinkedNodes(head);

			V3DCore::V3DMemory::Delete(poolHead);
			V3DCore::V3DMemory::Delete(poolTail);
			V3DCore::V3DMemory::Delete(head);
			V3DCore::V3DMemory::Delete(tail);

			length = 0;
		}

		[[nodiscard]] int GetLength() const
		{
			return length;
		}

		void First()
		{
			current = head != nullptr ? head->next : nullptr;
		}

		void Next()
		{
			current = current->next;
		}

		bool IsDone()
		{
			return current != nullptr && current->data != nullptr;
		}

		T* GetCurrent()
		{
			if (current != nullptr)
				return current->data;

			return nullptr;
		}

		T* Add()
		{
			if (poolTail->prev != nullptr)
			{
				auto temp = poolTail->prev;
				temp->isAlive = true;
				RemoveNodeFromPool(temp);
				InsertNodeToList(temp);			
				length++;
			}

			return nullptr;
		}

		void RemoveCurrent()
		{
			auto temp = current;
			current = current->prev;
			
			temp->isAlive = false;
			RemoveNodeFromList(temp);
			InsertNodeToPool(temp);
			length--;
		}

		void RemoveAll()
		{
			if (length == 0)
				return;
			
			auto first = head->next;
			auto last = tail->prev;

			if (length == poolSize)
				LinkNodes(poolHead, first);
			else
				LinkNodes(poolTail->prev, last);

			LinkNodes(last, poolTail);
			
			head->next = nullptr;
			tail->prev = nullptr;

			length = 0;
		}
	};
}
