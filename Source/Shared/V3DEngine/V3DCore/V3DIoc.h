/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DMemory.h"
#include "V3DEngine/V3DMacros.h"

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	/*
		It is working only in one assembly:
			-execute, dynamic lib
			-execute + static lib
			
		Dynamic IOC for subsystems and other dynamic main objects
		Ioc implements prototype, factory and singleton patterns together, called Inversion Of Control and Dependency Injection pattern (DI)
		This Ioc supports one dynamic instance and one dynamic prototype implementation for singleton or transient objects
	*/
	template <typename TInstance> class V3DIoc final
	{
		static TInstance* instance;
		static std::function<TInstance * ()> prototype;

	public:
		V3DIoc() = delete;
		V3DIoc(const V3DIoc&) = delete;
		V3DIoc(V3DIoc&&) = delete;
		~V3DIoc() = delete;
		V3DIoc& operator=(const V3DIoc&) = delete;
		V3DIoc& operator=(V3DIoc&&) = delete;

		template <typename TType> static void Register()
		{
			if (prototype == nullptr && instance == nullptr)
				prototype = []() { return V3DMemory::New<TType>(V3DFILE_INFO); };
		}

		template <typename TType> static void Register(const std::function<TInstance * ()>& otherPrototype)
		{
			if (otherPrototype != nullptr && prototype == nullptr && instance == nullptr)
				prototype = otherPrototype;
		}

		static void CreateSingleton()
		{
			if (prototype != nullptr && instance == nullptr)
				instance = prototype();
		}

		static TInstance* CreateTransient()
		{
			return prototype();
		}

		static void DeleteSingletonAndRegister()
		{
			V3DMemory::Delete(instance);
			prototype = nullptr;
		}

		static void DeleteRegister()
		{
			prototype = nullptr;
		}

		static TInstance* GetSingleton()
		{
			return instance;
		}

		static bool IsSingletonExist()
		{
			return instance != nullptr;
		}
	};

	template <typename TInstance> TInstance* V3DIoc<TInstance>::instance = nullptr;
	template <typename TInstance> std::function<TInstance * ()> V3DIoc<TInstance>::prototype = nullptr;
}
