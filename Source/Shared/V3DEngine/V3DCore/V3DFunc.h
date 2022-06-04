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
		Encapsulates a method that has no parameters and returns a value of the type specified by the TResult parameter.
	*/
	template <typename TResult> class V3DFunc final
	{
		std::function<TResult()> func;

	public:
		V3DFunc() = default;

		explicit V3DFunc(const std::function<TResult()>& function) : func { function }
		{ }

		template<typename TObject> V3DFunc(TResult(TObject::* function)() const, TObject& object) : func{ std::bind(function, object) }
		{ }

		V3DFunc(const V3DFunc&) = delete;
		V3DFunc(V3DFunc&&) = delete;
		~V3DFunc() = default;

		V3DFunc& operator=(const V3DFunc& otherV3DFunc)
		{
			func = otherV3DFunc.func;
			return *this;
		}

		V3DFunc& operator=(V3DFunc&& otherV3DFunc) noexcept
		{
			func = std::move(otherV3DFunc.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<TResult()>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(TResult(TObject::* function)() const, TObject& object)
		{
			func = std::bind(function, object);  // NOLINT(modernize-avoid-bind)
		}

		void Set(const V3DFunc& function)
		{
			func = function.func;
		}
		
		TResult Invoke() const
		{
			return func();
		}
	};

	/*
		Encapsulates a method that has one parameter and returns a value of the type specified by the TResult parameter.
	*/
	template <typename TParam, typename TResult> class V3DFunc1 final
	{
		std::function<TResult(TParam param)> func;

	public:
		V3DFunc1() = default;

		explicit V3DFunc1(const std::function<TResult(TParam param)>& function) : func{ function }
		{ }

		template<typename TObject> V3DFunc1(TResult(TObject::* function)(TParam param) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1) }
		{ }

		V3DFunc1(const V3DFunc1&) = delete;
		V3DFunc1(V3DFunc1&&) = delete;
		~V3DFunc1() = default;

		V3DFunc1& operator=(const V3DFunc1& otherV3DFunc)
		{
			func = otherV3DFunc.func;
			return *this;
		}

		V3DFunc1& operator=(V3DFunc1&& otherV3DFunc) noexcept
		{
			func = std::move(otherV3DFunc.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<TResult(TParam param)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(TResult(TObject::* function)(TParam param) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1); // NOLINT(modernize-avoid-bind)
		}

		void Set(const V3DFunc1& function)
		{
			func = function.func;
		}

		TResult Invoke(TParam param) const
		{
			return func(param);
		}
	};

	/*
		Encapsulates a method that has two parameters and returns a value of the type specified by the TResult parameter.
	*/
	template <typename TParam1, typename TParam2, typename TResult> class V3DFunc2 final
	{
		std::function<TResult(TParam1 param1, TParam2 param2)> func;

	public:
		V3DFunc2() = default;

		explicit V3DFunc2(const std::function<TResult(TParam1 param1, TParam2 param2)>& function) : func{ function }
		{ }

		template<typename TObject> V3DFunc2(TResult(TObject::* function)(TParam1 param1, TParam2 param2) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1, std::placeholders::_2) }
		{ }

		V3DFunc2(const V3DFunc2&) = delete;
		V3DFunc2(V3DFunc2&&) = delete;
		~V3DFunc2() = default;
		
		V3DFunc2& operator=(const V3DFunc2& otherV3DFunc)
		{
			func = otherV3DFunc.func;
			return *this;
		}

		V3DFunc2& operator=(V3DFunc2&& otherV3DFunc) noexcept
		{
			func = std::move(otherV3DFunc.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<TResult(TParam1 param1, TParam2 param2)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(TResult(TObject::* function)(TParam1 param1, TParam2 param2) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1, std::placeholders::_2); // NOLINT(modernize-avoid-bind)
		}

		void Set(const V3DFunc2& function)
		{
			func = function.func;
		}

		TResult Invoke(TParam1 param1, TParam2 param2) const
		{
			return func(param1, param2);
		}
	};

	/*
		Encapsulates a method that has three parameters and returns a value of the type specified by the TResult parameter.
	*/
	template <typename TParam1, typename TParam2, typename TParam3, typename TResult> class V3DFunc3 final
	{
		std::function<TResult(TParam1 param1, TParam2 param2, TParam3 param3)> func;

	public:
		V3DFunc3() = default;

		explicit V3DFunc3(const std::function<TResult(TParam1 param1, TParam2 param2, TParam3 param3)>& function) : func{ function }
		{ }

		template<typename TObject> V3DFunc3(TResult(TObject::* function)(TParam1 param1, TParam2 param2, TParam3 param3) const, TObject& object) : func{ std::bind(function, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3) }
		{ }

		V3DFunc3(const V3DFunc3&) = delete;
		V3DFunc3(V3DFunc3&&) = delete;
		~V3DFunc3() = default;
		
		V3DFunc3& operator=(const V3DFunc3& otherV3DFunc)
		{
			func = otherV3DFunc.func;
			return *this;
		}

		V3DFunc3& operator=(V3DFunc3&& otherV3DFunc) noexcept
		{
			func = std::move(otherV3DFunc.func);
			return *this;
		}

		bool IsEmpty() const
		{
			return func == nullptr;
		}

		void Set(const std::function<TResult(TParam1 param1, TParam2 param2, TParam3 param3)>& function)
		{
			func = function;
		}

		template<typename TObject> void Set(TResult(TObject::* function)(TParam1 param1, TParam2 param2, TParam3 param3) const, TObject& object)
		{
			func = std::bind(function, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3); // NOLINT(modernize-avoid-bind)
		}

		void Set(const V3DFunc3& function)
		{
			func = function.func;
		}

		TResult Invoke(TParam1 param1, TParam2 param2, TParam3 param3) const
		{
			return func(param1, param2, param3);
		}
	};
}
