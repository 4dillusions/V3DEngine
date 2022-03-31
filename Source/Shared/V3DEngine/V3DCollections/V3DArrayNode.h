/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DArrayNode final
	{
		T data{};

		V3DArrayNode<T>() = default;
		V3DArrayNode<T>(const V3DArrayNode<T>&) = delete;
		V3DArrayNode<T>(V3DArrayNode<T>&&) = delete;
		~V3DArrayNode<T>() = default;
		V3DArrayNode<T>& operator=(const V3DArrayNode<T>&) = delete;
		V3DArrayNode<T>& operator=(V3DArrayNode<T>&&) = delete;
	};
}
