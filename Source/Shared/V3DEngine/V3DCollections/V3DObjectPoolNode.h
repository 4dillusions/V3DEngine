/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DObjectPoolNode final
	{
		T* data{};
		V3DObjectPoolNode* prev{}, * next{};
		bool isAlive{ true };
		
		V3DObjectPoolNode() = default;
		V3DObjectPoolNode<T>(const V3DObjectPoolNode<T>&) = delete;
		V3DObjectPoolNode(V3DObjectPoolNode<T>&&) = delete;
		V3DObjectPoolNode<T>& operator=(const V3DObjectPoolNode<T>&) = delete;
		V3DObjectPoolNode<T>& operator=(V3DObjectPoolNode<T>&&) = delete;
	};
}
