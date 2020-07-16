/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DLinkedList.h"

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DDelegate final
	{
		V3DCollections::V3DLinkedList<std::function<void()>> functionList;
		
	public:
		V3DDelegate() = default;
		V3DDelegate(const V3DDelegate&) = delete;
		V3DDelegate(V3DDelegate&&) = delete;
		~V3DDelegate() = default;
		V3DDelegate& operator=(const V3DDelegate&) = delete;
		V3DDelegate& operator=(V3DDelegate&&) = delete;

		void operator += (const std::function<void()>& function);
		void operator -= (const std::function<void()>& function);
		void operator () ();
	};
}
