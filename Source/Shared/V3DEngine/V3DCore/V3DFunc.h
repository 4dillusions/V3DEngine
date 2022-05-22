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
		V3DFunc(const V3DFunc&) = delete;
		V3DFunc(V3DFunc&&) = delete;
		~V3DFunc() = default;
		V3DFunc& operator=(const V3DFunc&) = delete;
		V3DFunc& operator=(V3DFunc&&) = delete;

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
			Set(std::bind(function, object));
		}

		TResult Invoke()
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
		V3DFunc1(const V3DFunc1&) = delete;
		V3DFunc1(V3DFunc1&&) = delete;
		~V3DFunc1() = default;
		V3DFunc1& operator=(const V3DFunc1&) = delete;
		V3DFunc1& operator=(V3DFunc1&&) = delete;

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
			Set(std::bind(function, object, std::placeholders::_1));
		}

		TResult Invoke(TParam param)
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
		V3DFunc2(const V3DFunc2&) = delete;
		V3DFunc2(V3DFunc2&&) = delete;
		~V3DFunc2() = default;
		V3DFunc2& operator=(const V3DFunc2&) = delete;
		V3DFunc2& operator=(V3DFunc2&&) = delete;

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
			Set(std::bind(function, object, std::placeholders::_1, std::placeholders::_2));
		}

		TResult Invoke(TParam1 param1, TParam2 param2)
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
		V3DFunc3(const V3DFunc3&) = delete;
		V3DFunc3(V3DFunc3&&) = delete;
		~V3DFunc3() = default;
		V3DFunc3& operator=(const V3DFunc3&) = delete;
		V3DFunc3& operator=(V3DFunc3&&) = delete;

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
			Set(std::bind(function, object, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
		}

		TResult Invoke(TParam1 param1, TParam2 param2, TParam3 param3)
		{
			return func(param1, param2, param3);
		}
	};
}
