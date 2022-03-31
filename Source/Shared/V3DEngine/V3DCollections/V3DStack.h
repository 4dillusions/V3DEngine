/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DArrayNode.h"
#include "V3DEngine/V3DMacros.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

namespace V3D::V3DEngine::V3DCollections
{
	/*
		Stack LIFO data structure with static array

		best/worst
		search:		no/no
		add:		O(1) O(1)
		remove:		O(1) O(1) (without free data memory)
		index:		no/no
		static remove/delete: no/no
		continuously remove/delete: no/no
	*/
	template<typename T> class V3DStack final
	{
		const int stackSize{};
		V3DArrayNode<T>** stackArray{};
		int top{}, currentTop{};

		void CreateStackArray()
		{
			stackArray = V3DCore::V3DMemory::NewPointerArray<V3DArrayNode<T>>(V3DFILE_INFO, stackSize);

			for (int i = 0; i < stackSize; i++)
				stackArray[i] = V3DCore::V3DMemory::New<V3DArrayNode<T>>(V3DFILE_INFO);
		}
		
		void DeleteStackArray()
		{
			if (stackArray != nullptr)
			{
				for (int i = 0; i < stackSize; i++)
					V3DCore::V3DMemory::Delete(stackArray[i]);

				V3DCore::V3DMemory::DeletePointerArray(stackArray);
			}
		}

	public:
		V3DStack(int size) : stackSize(size), top{ -1 }
		{
			CreateStackArray();
		}

		V3DStack<T>(const V3DStack<T>& value) = delete;
		V3DStack<T>(V3DStack<T>&& value) = delete;
		
		~V3DStack()
		{
			DeleteStackArray();
		}

		V3DStack<T>& operator=(const V3DStack<T>& value) noexcept  // NOLINT(bugprone-unhandled-self-assignment)
		{
			if (this != &value)
			{
				DeleteStackArray();

				stackSize = value.stackSize;
				top = value.top;
				
				CreateStackArray();
				for (int i = 0; i < stackSize; i++)
					stackArray[i]->data = value.stackArray[i]->data;
			}

			return *this;
		}

		V3DStack<T>& operator=(V3DStack<T>&& value) noexcept
		{
			if (this != &value)
			{
				DeleteStackArray();

				stackSize = value.stackSize;
				stackArray = value.stackArray;
				top = value.top;
				
				value.stackSize = 0;
				value.stackArray = nullptr;
				value.top = -1;
			}

			return *this;
		}

		bool IsEmpty() const
		{
			return top == -1;
		}

		bool IsFull() const
		{
			return top == stackSize - 1;
		}

		bool Add(const T& item) //push
		{
			if (IsFull())
				return false;

			if (IsEmpty())
				top = 0;
			else
				top++;

			stackArray[top]->data = item;
			return true;
		}

		T* Take() //pop
		{
			if (IsEmpty())
				return nullptr;

			currentTop = top;
			top--;

			return &stackArray[currentTop]->data;
		}
	};
}
