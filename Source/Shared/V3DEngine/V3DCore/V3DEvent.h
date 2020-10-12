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
	template <typename TArgs> class V3DEvent final
	{
		V3DCollections::V3DLinkedList<std::function<void(const TArgs& args)>> functionList;

	public:
		V3DEvent() = default;
		V3DEvent(const V3DEvent&) = delete;
		V3DEvent(V3DEvent&&) = delete;
		~V3DEvent() = default;
		V3DEvent& operator=(const V3DEvent&) = delete;
		V3DEvent& operator=(V3DEvent&&) = delete;

		void operator += (const std::function<void(const TArgs& args)>& function)
		{
			functionList.Add(function);
		}
		
		void operator -= (const std::function<void(const TArgs& args)>& function)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				if (functionList.GetCurrent()->template target<void(const TArgs & args)>() == function.template target<void(const TArgs & args)>())
				{
					functionList.RemoveCurrent();
					break;
				}
		}
		
		void operator () (const TArgs& args)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				(*functionList.GetCurrent())(args);
		}
	};

	template <> class V3DEvent<void()> final
	{
		V3DCollections::V3DLinkedList<std::function<void()>> functionList;

	public:
		V3DEvent() = default;
		V3DEvent(const V3DEvent&) = delete;
		V3DEvent(V3DEvent&&) = delete;
		~V3DEvent() = default;
		V3DEvent& operator=(const V3DEvent&) = delete;
		V3DEvent& operator=(V3DEvent&&) = delete;

		void operator += (const std::function<void()>& function)
		{
			functionList.Add(function);
		}

		void operator -= (const std::function<void()>& function)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				if (functionList.GetCurrent()->target<void()>() == function.target<void()>())
				{
					functionList.RemoveCurrent();
					break;
				}
		}

		void operator () ()
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				(*functionList.GetCurrent())();
		}
	};
}
