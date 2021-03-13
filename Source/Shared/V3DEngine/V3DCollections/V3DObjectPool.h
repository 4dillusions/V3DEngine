/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DObjectPoolNode.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngine::V3DCollections
{
	/*
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
	template<typename T> class V3DObjectPool final
	{
		const int PoolSize{};
		T* dataArray;
		V3DObjectPoolNode<T>* nodes;
		V3DObjectPoolNode<T>* poolHead{}, * poolTail{}, * head{}, * tail{}, * current{};
		int length{};

		void Init()
		{
			dataArray = V3DCore::V3DMemory::NewArray<T>(V3DFILE_INFO, PoolSize);
			nodes = V3DCore::V3DMemory::NewArray<V3DObjectPoolNode<T>>(V3DFILE_INFO, PoolSize + 4);

			poolHead = &nodes[PoolSize];
			poolTail = &nodes[PoolSize + 1];
			head = &nodes[PoolSize + 2];
			tail = &nodes[PoolSize + 3];

			int arrayIndex = 0;
			auto currentNode = AddNewNodeWithData(poolHead, arrayIndex);

			for (arrayIndex++; arrayIndex < PoolSize; arrayIndex++)
				currentNode = AddNewNodeWithData(currentNode, arrayIndex);

			currentNode->next = poolTail;
			poolTail->prev = currentNode;
		}
		
		V3DObjectPoolNode<T>* AddNewNodeWithData(V3DObjectPoolNode<T>* targetNode, int arrayIndex)
		{
			auto newNode = &nodes[arrayIndex];
			newNode->data = &dataArray[arrayIndex];

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
			if (length < PoolSize)
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

	public:
		V3DObjectPool<T>(const V3DObjectPool<T>&) = delete;
		V3DObjectPool<T>(V3DObjectPool<T>&&) = delete;
		V3DObjectPool<T>& operator=(const V3DObjectPool<T>&) = delete;
		V3DObjectPool<T>& operator=(V3DObjectPool<T>&&) = delete;

		V3DObjectPool()
		{
			Init();
		}

		V3DObjectPool(const int poolSize) : PoolSize { poolSize }
		{
			Init();
		}

		~V3DObjectPool()
		{
			V3DCore::V3DMemory::DeleteArray(nodes);
			V3DCore::V3DMemory::DeleteArray(dataArray);
			
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

		bool IsDone()
		{
			return current != nullptr && current->data != nullptr;
		}

		void Next()
		{
			current = current->next;
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
				RemoveNodeFromPool(temp);
				InsertNodeToList(temp);			
				length++;

				return temp->data;
			}

			return nullptr;
		}

		void RemoveCurrent()
		{
			auto temp = current;
			current = current->prev;
			
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

			if (length == PoolSize)
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
