/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename TKey, typename TItem> class V3DDecimalTreeNode final
	{
		bool isMarked{ false };
		V3DDecimalTreeNode* current{};
		
	public:
		static const int childSize = 10;
		TKey key{};
		TItem data{};
		TItem* dataFlag{};
		V3DDecimalTreeNode* children[childSize]{};

		V3DDecimalTreeNode() = default;
		V3DDecimalTreeNode<TKey, TItem>(const V3DDecimalTreeNode<TKey, TItem>&) = delete;
		V3DDecimalTreeNode(V3DDecimalTreeNode<TKey, TItem>&&) = delete;
		V3DDecimalTreeNode<TKey, TItem>& operator=(const V3DDecimalTreeNode<TKey, TItem>&) = delete;
		V3DDecimalTreeNode<TKey, TItem>& operator=(V3DDecimalTreeNode<TKey, TItem>&&) = delete;

		void First(bool isSetMarkDefault = true)
		{
			if (isSetMarkDefault)
				isMarked = false;
			
			for (int i = 0; i < childSize; i++)
				if (children[i] != nullptr)
					children[i]->First(isSetMarkDefault);
		}
		
		V3DDecimalTreeNode* GetFirst()
		{
			for (int currentIndex = 0; currentIndex < childSize; currentIndex++)
			{
				if (children[currentIndex] != nullptr)
				{
					if (children[currentIndex]->dataFlag != nullptr && children[currentIndex]->isMarked == false)
					{
						children[currentIndex]->isMarked = true;
						return children[currentIndex];
					}

					current = children[currentIndex]->GetFirst();
					if (current != nullptr)
						return current;
				}
			}

			return nullptr;
		}

		V3DDecimalTreeNode* GetNext()
		{
			First(false);
			
			return GetFirst();
		}

		void RemoveAllChildrenData()
		{
			for (int i = 0; i < childSize; i++)
				if (children[i] != nullptr)
				{
					children[i]->dataFlag = nullptr;
					children[i]->RemoveAllChildrenData();
				}
		}

		void DeleteAllChildrenNode()
		{
			for (int i = 0; i < childSize; i++)
			{
				if (children[i] != nullptr)
					children[i]->DeleteAllChildrenNode();

				V3DCore::V3DMemory::Delete(children[i]);
			}	
		}
	};
}
