/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DDynamicArrayNode.h"
#include "V3DEngine/V3DCore/V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

namespace V3D::V3DEngine::V3DCollections
{
	/*
		Dynamic array data structure with static and dynamic objects.
		Supports delete nodes while iterate, except RemoveAll

		Mainly use for iterating

		best/worst
		search:		O(n) O(n)
		add:		O(1) O(1)
		remove:		O(1) O(1) (without free data memory)
		index:						O(1) O(1)
		static remove/delete:		yes/no
		continuously remove/delete: yes/no
	*/
	template<typename T> class V3DDynamicArray final
	{
		const int MinDataSize { 100 };
		V3DDynamicArrayNode<T>** dataArray{};
		V3DDynamicArrayNode<T>* current{};
		int dataSize = MinDataSize;
		int currentIndex{};
		int length{};

		void Init()
		{
			dataArray = CreateDataArray(MinDataSize);

			for (int i = 0; i < dataSize; i++)
				dataArray[i] = nullptr;
		}

		V3DDynamicArrayNode<T>** CreateDataArray(int size)
		{
			return V3DCore::V3DMemory::NewPointerArray<V3DDynamicArrayNode<T>>(V3DFILE_INFO, size);
		}

		static void DeleteDataArray(V3DDynamicArrayNode<T>**& array)
		{
			V3DCore::V3DMemory::DeletePointerArray(array);
		}

		V3DDynamicArrayNode<T> *CreateNode()
		{
			return V3DCore::V3DMemory::New<V3DDynamicArrayNode<T>>(V3DFILE_INFO);
		}

		static void DeleteNode(V3DDynamicArrayNode<T>*& node)
		{
			V3DCore::V3DMemory::Delete(node);
		}

	public:
		V3DDynamicArray<T>()
		{
			Init();
		}
		
		explicit V3DDynamicArray<T>(const int minDataSize) : MinDataSize { minDataSize }
		{
			Init();
		}

		V3DDynamicArray<T>(const V3DDynamicArray<T>& value) = delete;
		
		V3DDynamicArray<T>(V3DDynamicArray<T>&& value) noexcept
		{
			*this = std::move(value);
		}

		~V3DDynamicArray()
		{
			RemoveAll();
			DeleteDataArray(dataArray);
		}

		V3DDynamicArray<T>& operator=(const V3DDynamicArray<T>& value) = delete;	

		V3DDynamicArray<T>& operator=(V3DDynamicArray<T>&& value) noexcept
		{
			if (this != &value)
			{
				RemoveAll();
				DeleteDataArray(dataArray);

				dataSize = value.dataSize;
				length = value.length;
				currentIndex = value.currentIndex;
				dataArray = value.dataArray;

				value.dataSize = MinDataSize;
				value.length = 0;
				value.currentIndex = 0;
				value.dataArray = nullptr;
			}

			return *this;
		}
		
		int GetLength() const
		{
			return length;
		}

		void First()
		{
			currentIndex = 0;
			current = dataArray[0];
		}

		bool IsDone()
		{
			return (current != nullptr);
		}

		void Next()
		{
			currentIndex++;

			if (currentIndex < length)
				current = dataArray[currentIndex];
			else
				current = nullptr;
		}

		T* GetCurrent()
		{
			if (current != nullptr)
				return &current->data;

			return nullptr;
		}

		T* operator [] (int index)
		{
			return &dataArray[index]->data;
		}

		void Add(const T& item)
		{
			if (length == dataSize)
			{
				dataSize *= 2;
				V3DDynamicArrayNode<T>** tempDataArray = CreateDataArray(dataSize);
				for (int i = 0; i < length; i++)
					tempDataArray[i] = dataArray[i];

				DeleteDataArray(dataArray);
				dataArray = tempDataArray;
			}

			auto temp = CreateNode();
			temp->data = item;

			dataArray[length] = temp;
			length++;
		}

		void RemoveAt(int index)
		{
			if (length > 0 && index >= 0 && index < length)
			{
				length--;
				DeleteNode(dataArray[index]);

				for (int i = index; i < length; i++)
					dataArray[i] = dataArray[i + 1];
			}
		}

		void RemoveCurrent()
		{
			RemoveAt(currentIndex);
		}

		void RemoveAll()
		{
			if (dataArray != nullptr)
				for (int i = 0; i < length; i++)
					if (dataArray[i] != nullptr)
						DeleteNode(dataArray[i]);

			length = 0;
		}
	};
}
