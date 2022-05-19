/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename TKey, typename TItem> struct V3DDecimalTreeNode final
	{
		static constexpr int ChildSize = 10;
		TKey key{};
		TItem data{};
		TItem* dataFlag{};
		V3DDecimalTreeNode* children[ChildSize]{};

		V3DDecimalTreeNode<TKey, TItem>() = default;
		V3DDecimalTreeNode<TKey, TItem>(const V3DDecimalTreeNode<TKey, TItem>&) = delete;
		V3DDecimalTreeNode<TKey, TItem>(V3DDecimalTreeNode<TKey, TItem>&&) = delete;
		~V3DDecimalTreeNode<TKey, TItem>() = default;
		V3DDecimalTreeNode<TKey, TItem>& operator=(const V3DDecimalTreeNode<TKey, TItem>&) = delete;
		V3DDecimalTreeNode<TKey, TItem>& operator=(V3DDecimalTreeNode<TKey, TItem>&&) = delete;

		void RemoveAllChildrenData()
		{
			for (auto& i : children)
				if (i != nullptr)
				{
					i->dataFlag = nullptr;
					i->RemoveAllChildrenData();
				}
		}

		void DeleteAllChildrenNode()
		{
			for (auto& i : children)
			{
				if (i != nullptr)
					i->DeleteAllChildrenNode();

				V3DCore::V3DMemory::Delete(i);
			}	
		}

		void GetAllChildren(V3DDecimalTreeNode<TKey, TItem>** allItemArray, int&& index = 0)
		{
			if (dataFlag != nullptr)
			{
				allItemArray[index] = this;
				index++;
			}
			
			for (auto& i : children)
				if (i != nullptr)
					i->GetAllChildren(allItemArray, std::move(index));  // NOLINT(bugprone-use-after-move, performance-move-const-arg)
		}
	};
}
