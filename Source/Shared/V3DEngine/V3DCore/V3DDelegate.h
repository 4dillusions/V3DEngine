/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	template <typename TArgs> class V3DDelegate final
	{
		std::function<void(const TArgs& args)> func;

	public:
		V3DDelegate() = default;
		V3DDelegate(const V3DDelegate&) = delete;
		V3DDelegate(V3DDelegate&&) = delete;
		~V3DDelegate() = default;
		V3DDelegate& operator=(const V3DDelegate&) = delete;
		V3DDelegate& operator=(V3DDelegate&&) = delete;

		V3DDelegate<TArgs>& operator=(const std::function<void(const TArgs& args)>& function)
		{
			func = function;
			return *this;
		}

		void operator () (const TArgs& args)
		{
			if (func != nullptr)
				func(args);
		}
	};

	template <> class V3DDelegate<void()> final
	{
		std::function<void()> func;

	public:
		V3DDelegate() = default;
		V3DDelegate(const V3DDelegate&) = delete;
		V3DDelegate(V3DDelegate&&) = delete;
		~V3DDelegate() = default;
		V3DDelegate& operator=(const V3DDelegate&) = delete;
		V3DDelegate& operator=(V3DDelegate&&) = delete;

		V3DDelegate<void()>& operator=(const std::function<void()>& function)
		{
			func = function;
			return *this;
		}

		void operator () () const
		{
			if (func != nullptr)
				func();
		}
	};
}
