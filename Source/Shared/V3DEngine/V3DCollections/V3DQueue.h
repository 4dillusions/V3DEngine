/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DQueueNode.h"
#include "V3DEngine/V3DCore/V3DMemory.h"

namespace V3D::V3DEngine::V3DCollections
{
	// ReSharper disable once CommentTypo
	/*
		Queue FIFO data structure with "cirled" array

		best/worst
		search:		no/no
		add:		O(1) O(1)
		remove:		O(1) O(1) (without free data memory)
		index:		no/no
		static remove/delete: no/no
		continuously remove/delete: no/no
	*/
	template<typename T> class V3DQueue final
	{
		const int queueSize;
		V3DQueueNode<T>** queueArray;
		int front, currentFront, rear;

		void CreateQueueArray()
		{
			queueArray = V3DCore::V3DMemory::NewPointerArray<V3DQueueNode<T>>(V3DFILE_INFO, queueSize);

			for (int i = 0; i < queueSize; i++)
				queueArray[i] = V3DCore::V3DMemory::New<V3DQueueNode<T>>(V3DFILE_INFO);
		}
		
		void DeleteQueueArray()
		{
			if (queueArray != nullptr)
			{
				for (int i = 0; i < queueSize; i++)
					V3DCore::V3DMemory::Delete(queueArray[i]);

				V3DCore::V3DMemory::DeletePointerArray(queueArray);
			}
		}

	public:
		V3DQueue(int size) : queueSize(size), front{ -1 }, currentFront{}, rear{ -1 }
		{
			CreateQueueArray();
		}

		V3DQueue<T>(const V3DQueue<T>& value)
		{
			*this = value;
		}

		V3DQueue<T>(V3DQueue<T>&& value) noexcept
		{
			*this = std::move(value);
		}

		~V3DQueue()
		{
			DeleteQueueArray();
		}

		// ReSharper disable once CommentTypo
		V3DQueue<T>& operator=(const V3DQueue<T>& value) noexcept  // NOLINT(bugprone-unhandled-self-assignment)
		{
			if (this != &value)
			{
				DeleteQueueArray();

				queueSize = value.queueSize;
				front = value.front;
				rear = value.rear;
				
				CreateQueueArray();
				for (int i = 0; i < queueSize; i++)
					queueArray[i]->data = value.queueArray[i]->data;
			}

			return *this;
		}

		V3DQueue<T>& operator=(V3DQueue<T>&& value) noexcept
		{
			if (this != &value)
			{
				DeleteQueueArray();

				queueSize = value.queueSize;
				queueArray = value.queueArray;
				front = value.front;
				rear = value.rear;

				value.queueSize = 0;
				value.queueArray = nullptr;
				value.front = value.rear = -1;
			}

			return *this;
		}

		[[nodiscard]] bool IsEmpty() const
		{
			return front == -1 && rear == -1;
		}

		[[nodiscard]] bool IsFull() const
		{
			return rear == queueSize - 1;
		}

		bool Add(const T& item) //enqueue
		{
			if ((rear + 1) % queueSize == front)
				return false;

			if (IsEmpty())
				front = rear = 0;
			else
				rear = (rear + 1) % queueSize;

			queueArray[rear]->data = item;
			return true;
		}

		T* Take() //dequeue
		{
			if (IsEmpty())
				return nullptr;

			if (front == rear)
			{
				currentFront = front;
				front = rear = -1;
				
				return &queueArray[currentFront]->data;
			}

			currentFront = front;
			front = (front + 1) % queueSize;
			
			return &queueArray[currentFront]->data;
		}
	};
}
