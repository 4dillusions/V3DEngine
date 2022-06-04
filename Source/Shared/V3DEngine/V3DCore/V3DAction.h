/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	/*
		Encapsulates a method that has no parameters and does not return a value.
	*/
	class V3DAction final
	{
		std::function<void()> func;

	public:
		V3DAction() = default;

		explicit V3DAction(const std::function<void()>& function) : func{ function }
		{ }

		template<typename TObject> V3DAction(void(TObject::* function)() const, TObject& object) : func{ std::bind(function, object) }
		{ }

		V3DAction(const V3DAction&) = delete;
		V3DAction(V3DAction&&) = delete;
		~V3DAction() = default;
		
		V3DAction& operator=(const V3DAction& otherV3DAction)
		{
			func = otherV3DAction.func;
			return *this;
		}

		V3DAction& operator=(V3DAction&& otherV3DAction) noexcept
		{
			func = std::move(otherV3DAction.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<void()>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(void(TObject::* function)() const, TObject& object)
		{
			func = std::bind(function, object);
		}

		void Set(const V3DAction& function)
		{
			func = function.func;
		}

		void Invoke() const
		{
			func();
		}
	};

	/*
		Encapsulates a method that has a single parameter and does not return a value.
	*/
	template <typename TParam> class V3DAction1 final
	{
		std::function<void(TParam param)> func;

	public:
		V3DAction1() = default;

		explicit V3DAction1(const std::function<void(TParam param)>& function) : func{ function }
		{ }

		template<typename TObject> V3DAction1(void(TObject::* function)(TParam param) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1) }
		{ }
		
		V3DAction1(const V3DAction1&) = delete;
		V3DAction1(V3DAction1&&) = delete;
		~V3DAction1() = default;
		
		V3DAction1& operator=(const V3DAction1& otherV3DAction)
		{
			func = otherV3DAction.func;
			return *this;
		}

		V3DAction1& operator=(V3DAction1&& otherV3DAction) noexcept
		{
			func = std::move(otherV3DAction.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<void(TParam param)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(void(TObject::* function)(TParam param) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1);
		}

		void Set(const V3DAction1& function)
		{
			func = function.func;
		}

		void Invoke(TParam param) const
		{
			func(param);
		}
	};

	/*
		Encapsulates a method that has two parameters and does not return a value.
	*/
	template <typename TParam1, typename TParam2> class V3DAction2 final
	{
		std::function<void(TParam1 param1, TParam2 param2)> func;

	public:
		V3DAction2() = default;

		explicit V3DAction2(const std::function<void(TParam1 param1, TParam2 param2)>& function) : func{ function }
		{ }

		template<typename TObject> V3DAction2(void(TObject::* function)(TParam1 param1, TParam2 param2) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1, std::placeholders::_2) }
		{ }
		
		V3DAction2(const V3DAction2&) = delete;
		V3DAction2(V3DAction2&&) = delete;
		~V3DAction2() = default;
		
		V3DAction2& operator=(const V3DAction2& otherV3DAction)
		{
			func = otherV3DAction.func;
			return *this;
		}

		V3DAction2& operator=(V3DAction2&& otherV3DAction) noexcept
		{
			func = std::move(otherV3DAction.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<void(TParam1 param1, TParam2 param2)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(void(TObject::* function)(TParam1 param1, TParam2 param2) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1, std::placeholders::_2);
		}

		void Set(const V3DAction2& function)
		{
			func = function.func;
		}

		void Invoke(TParam1 param1, TParam2 param2) const
		{
			func(param1, param2);
		}
	};

	/*
		Encapsulates a method that has three parameters and does not return a value.
	*/
	template <typename TParam1, typename TParam2, typename TParam3> class V3DAction3 final
	{
		std::function<void(TParam1 param1, TParam2 param2, TParam3 param3)> func;

	public:
		V3DAction3() = default;

		explicit V3DAction3(const std::function<void(TParam1 param1, TParam2 param2, TParam3 param3)>& function) : func{ function }
		{ }

		template<typename TObject> V3DAction3(void(TObject::* function)(TParam1 param1, TParam2 param2, TParam3 param3) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) }
		{ }

		V3DAction3(const V3DAction3&) = delete;
		V3DAction3(V3DAction3&&) = delete;
		~V3DAction3() = default;
		
		V3DAction3& operator=(const V3DAction3& otherV3DAction)
		{
			func = otherV3DAction.func;
			return *this;
		}

		V3DAction3& operator=(V3DAction3&& otherV3DAction) noexcept
		{
			func = std::move(otherV3DAction.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<void(TParam1 param1, TParam2 param2, TParam3 param3)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(void(TObject::* function)(TParam1 param1, TParam2 param2, TParam3 param3) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
		}

		void Set(const V3DAction3& function)
		{
			func = function.func;
		}

		void Invoke(TParam1 param1, TParam2 param2, TParam3 param3) const
		{
			func(param1, param2, param3);
		}
	};
}
