/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DQueueNode final
	{
		T data{};

		V3DQueueNode<T>() = default;
		V3DQueueNode<T>(const V3DQueueNode<T>&) = delete;
		V3DQueueNode<T>(V3DQueueNode<T>&&) = delete;
		~V3DQueueNode<T>() = default;
		V3DQueueNode<T>& operator=(const V3DQueueNode<T>&) = delete;
		V3DQueueNode<T>& operator=(V3DQueueNode<T>&&) = delete;
	};
}
