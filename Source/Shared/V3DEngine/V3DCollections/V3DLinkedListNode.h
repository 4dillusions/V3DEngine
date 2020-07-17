/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DLinkedListNode final
	{
		T data{};
		T* dataFlag{};
		V3DLinkedListNode* prev{}, * next{};

		V3DLinkedListNode<T>() = default;
		V3DLinkedListNode<T>(const V3DLinkedListNode<T>&) = delete;
		V3DLinkedListNode(V3DLinkedListNode<T>&&) = delete;
		V3DLinkedListNode<T>& operator=(const V3DLinkedListNode<T>&) = delete;
		V3DLinkedListNode<T>& operator=(V3DLinkedListNode<T>&&) = delete;
	};
}
