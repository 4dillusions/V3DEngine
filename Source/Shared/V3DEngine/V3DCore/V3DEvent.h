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
	/*
		It is a function list with TArgs param
	*/
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

		void Add(const std::function<void(const TArgs& args)>& function)
		{
			functionList.Add(function);
		}

		template<typename TObject> void Add(void(TObject::* func)(const TArgs& args) const, TObject& object)
		{
			Add(std::bind(func, object, std::placeholders::_1));  // NOLINT(modernize-avoid-bind)
		}
		
		void Remove(const std::function<void(const TArgs& args)>& function)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				if (functionList.GetCurrent()->template target<void(const TArgs & args)>() == function.template target<void(const TArgs & args)>())
				{
					functionList.RemoveCurrent();
					break;
				}
		}

		template<typename TObject> void Remove(void(TObject::* func)(const TArgs& args) const, TObject& object)
		{
			Remove(std::bind(func, object, std::placeholders::_1));  // NOLINT(modernize-avoid-bind)
		}
		
		void Invoke(const TArgs& args)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				(*functionList.GetCurrent())(args);
		}
	};

	/*
		It is a function list without param
	*/
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

		void Add(const std::function<void()>& function)
		{
			functionList.Add(function);
		}

		template<typename TObject> void Add(void(TObject::* func)() const, TObject& object)
		{
			Add(std::bind(func, object));  // NOLINT(modernize-avoid-bind)
		}

		void Remove(const std::function<void()>& function)
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				if (functionList.GetCurrent()->target<void()>() == function.target<void()>())
				{
					functionList.RemoveCurrent();
					break;
				}
		}

		template<typename TObject> void Remove(void(TObject::* func)() const, TObject& object)
		{
			Remove(std::bind(func, object));  // NOLINT(modernize-avoid-bind)
		}

		void Invoke()
		{
			for (functionList.First(); functionList.IsDone(); functionList.Next())
				(*functionList.GetCurrent())();
		}
	};
}
