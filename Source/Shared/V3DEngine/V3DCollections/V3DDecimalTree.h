/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DDecimalTreeNode.h"

#include <cassert>

namespace V3D::V3DEngine::V3DCollections
{
	/*
		Decimal tree data structure with static and dynamic objects.
		Supports deleting nodes while iterate, except RemoveAll
		Keys are compared by using (explicit casted) integer

		Mainly use for searching

		best/worst
		search:		lg(n) lg(n)
		add:		lg(n) lg(n)
		remove:		lg(n) lg(n) (without free data memory)
		index:						no/no
		static remove/delete:		yes/no
		continuously remove/delete: yes/no
	*/
	template<typename TKey, typename TItem> class V3DDecimalTree final
	{
		static constexpr int DigitSize = 10;
		static constexpr int NumberSystemSize = 10;
		V3DDecimalTreeNode<TKey, TItem>* root{}, * current{}, ** currentAllItemArray{};
		int currentIndex{}, length{}, currentLength{};

		V3DDecimalTreeNode<TKey, TItem>* CreateNode()
		{
			return V3DCore::V3DMemory::New<V3DDecimalTreeNode<TKey, TItem>>(V3DFILE_INFO);
		}

		static void DeleteNode(V3DDecimalTreeNode<TKey, TItem>*& node)
		{
			V3DCore::V3DMemory::Delete(node);
		}

		V3DDecimalTreeNode<TKey, TItem>** CreateNodeArray(int size)
		{
			return V3DCore::V3DMemory::NewPointerArray<V3DDecimalTreeNode<TKey, TItem>>(V3DFILE_INFO, size);
		}

		static void DeleteNodeArray(V3DDecimalTreeNode<TKey, TItem>**& nodeArray)
		{
			V3DCore::V3DMemory::DeletePointerArray(nodeArray);
		}

		static void GetDigitArrayFromKey(const TKey& key, int* digitArray, int& digitCount)
		{
			auto currentNumber = static_cast<int>(key);
			for (int digitIndex = DigitSize - 1; digitIndex >= 0; digitIndex--)
			{
				digitCount++;
				
				if (currentNumber < NumberSystemSize)
				{
					digitArray[digitIndex] = currentNumber;
					break;
				}

				digitArray[digitIndex] = currentNumber % NumberSystemSize;
				currentNumber /= NumberSystemSize;
			}
		}

	public:
		V3DDecimalTree<TKey, TItem>(const V3DDecimalTree<TKey, TItem>&) = delete;
		V3DDecimalTree<TKey, TItem>(V3DDecimalTree<TKey, TItem>&&) = delete;
		V3DDecimalTree<TKey, TItem>& operator=(const V3DDecimalTree<TKey, TItem>&) = delete;
		V3DDecimalTree<TKey, TItem>& operator=(V3DDecimalTree<TKey, TItem>&&) = delete;

		V3DDecimalTree()
		{
			root = CreateNode();
		}

		~V3DDecimalTree()
		{
			if (root != nullptr)
			{
				root->DeleteAllChildrenNode();
				DeleteNode(root);
			}

			DeleteNodeArray(currentAllItemArray);
			length = 0;
		}

		int GetLength() const
		{
			return length;
		}

		void First()
		{
			if (length > 0)
			{
				currentIndex = 0;
				currentLength = length;
				
				if (currentAllItemArray != nullptr)
					DeleteNodeArray(currentAllItemArray);
				
				currentAllItemArray = CreateNodeArray(length);
				root->GetAllChildren(currentAllItemArray);
				current = currentAllItemArray[0];
			}
		}

		bool IsDone()
		{
			return current != nullptr; //& current->dataFlag != nullptr;
		}

		void Next()
		{
			currentIndex++;

			if (currentIndex < currentLength)
				current = currentAllItemArray[currentIndex];
			else
				current = nullptr;
		}

		TKey GetCurrentKey()
		{
			return current->key;
		}
		
		TItem* GetCurrentItem()
		{
			if (current != nullptr)
				return &current->data;

			return nullptr;
		}

		TItem* GetItem(const TKey& key)
		{
			int digitArray[DigitSize]{};
			int digitCount{};
			GetDigitArrayFromKey(key, digitArray, digitCount);

			current = root;
			for (int digitIndex = DigitSize - digitCount; digitIndex < DigitSize; digitIndex++)
			{
				current = current->children[digitArray[digitIndex]];
				if (current == nullptr)
					return nullptr;
			}
			
			return current->dataFlag != nullptr ? &current->data : nullptr;
		}
		
		bool Add(const TKey& key, const TItem& item)
		{
			assert(static_cast<int>(key) >= 0);
			
			int digitArray[DigitSize];
			int digitCount{};
			GetDigitArrayFromKey(key, digitArray, digitCount);

			current = root;
			for (int digitIndex = DigitSize - digitCount; digitIndex < DigitSize; digitIndex++)
			{
				if (current->children[digitArray[digitIndex]] == nullptr)
					current->children[digitArray[digitIndex]] = CreateNode();

				current = current->children[digitArray[digitIndex]];
			}

			if (current->dataFlag != nullptr)
				return false;

			current->key = key;
			current->data = item;
			current->dataFlag = &const_cast<TItem&>(item);
			length++;
			
			return true;
		}

		bool RemoveAt(const TKey& key)
		{
			GetItem(key);
			if (current->dataFlag == nullptr)
				return false;

			RemoveCurrent();
			
			return true;
		}

		void RemoveCurrent()
		{
			current->dataFlag = nullptr;
			length--;
		}

		void RemoveAll()
		{
			if (length == 0)
				return;

			root->RemoveAllChildrenData();
			
			length = 0;
		}
	};
}
