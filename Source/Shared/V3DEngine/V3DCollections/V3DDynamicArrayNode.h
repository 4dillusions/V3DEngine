/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCollections
{
	template<typename T> struct V3DDynamicArrayNode final
	{
		T data{};

		V3DDynamicArrayNode<T>() = default;
		V3DDynamicArrayNode<T>(const V3DDynamicArrayNode<T>&) = delete;
		V3DDynamicArrayNode<T>(V3DDynamicArrayNode<T>&&) = delete;
		V3DDynamicArrayNode<T>& operator=(const V3DDynamicArrayNode<T>&) = delete;
		V3DDynamicArrayNode<T>& operator=(V3DDynamicArrayNode<T>&&) = delete;
	};
}
