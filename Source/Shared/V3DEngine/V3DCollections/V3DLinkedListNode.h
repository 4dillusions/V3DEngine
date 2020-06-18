/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DMemory.h"

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DLinkedListNode final
	{
		T* data{};
		//T dataTemp; //fogja majd az objektum másolatát
		V3DLinkedListNode* prev{}, * next{};
		bool isAlive{ true };
		
		V3DLinkedListNode<T>() = default;
		V3DLinkedListNode<T>(const V3DLinkedListNode<T>&) = delete;
		V3DLinkedListNode(V3DLinkedListNode<T>&&) = delete;
		V3DLinkedListNode<T>& operator=(const V3DLinkedListNode<T>&) = delete;
		V3DLinkedListNode<T>& operator=(V3DLinkedListNode<T>&&) = delete;

		void SetData(T& item)
		{
			//data = &item;
		}
		
		void Delete()
		{ }
	};

	template<typename T> struct V3DLinkedListNode<T*> final
	{
		T* data{};
		V3DLinkedListNode* prev{}, * next{};
		bool isAlive{ true };

		V3DLinkedListNode<T*>() = default;
		V3DLinkedListNode<T*>(const V3DLinkedListNode<T*>&) = delete;
		V3DLinkedListNode<T*>(V3DLinkedListNode<T*>&&) = delete;
		V3DLinkedListNode<T*>& operator=(const V3DLinkedListNode<T*>&) = delete;
		V3DLinkedListNode<T*>& operator=(V3DLinkedListNode<T*>&&) = delete;

		void SetData(T& item)
		{
			//data = &item;
		}

		void Delete()
		{			
			V3DCore::V3DMemory::Delete(data);
		}
	};
}
