/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DIocContainer.h"
#include "V3DMemory.h"
#include "V3DFunc.h"

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
	template <typename TInstance> class V3DIoc final : public V3DIocContainer
	{
		static TInstance* instance;
		static V3DFunc<TInstance*> prototype;

		template <typename TType> static void Register()
		{
			if (prototype.IsEmpty() && instance == nullptr)
			{
				prototype.Set([] { return V3DMemory::New<TType>(V3DFILE_INFO); });
				removeActionsContainer->Add(V3DAction([] { V3DIoc<TInstance>::Remove(); }));
			}
		}

		template <typename TType> static void Register(const V3DFunc<TInstance*>& otherPrototype)
		{
			if (!otherPrototype.IsEmpty() && prototype.IsEmpty() && instance == nullptr)
			{
				prototype.Set(otherPrototype);
				removeActionsContainer->Add(V3DAction([] { V3DIoc<TInstance>::Remove(); }));
			}
		}

		static void CreateSingleton()
		{
			if (!prototype.IsEmpty() && instance == nullptr)
				instance = prototype.Invoke();
		}

	public:
		V3DIoc() = delete;
		V3DIoc(const V3DIoc&) = delete;
		V3DIoc(V3DIoc&&) = delete;
		~V3DIoc() = default;
		V3DIoc& operator=(const V3DIoc&) = delete;
		V3DIoc& operator=(V3DIoc&&) = delete;

		template <typename TType> static void RegisterTransient()
		{
			Register<TType>();
		}

		template <typename TType> static void RegisterTransient(const V3DFunc<TInstance*>& otherPrototype)
		{
			Register<TType>(otherPrototype);  // NOLINT(clang-diagnostic-microsoft-template)
		}

		template <typename TType> static void RegisterAndCreateSingleton()
		{
			Register<TType>();
			CreateSingleton();
		}

		template <typename TType> static void RegisterAndCreateSingleton(const V3DFunc<TInstance*>& otherPrototype)
		{
			Register<TType>(otherPrototype);
			CreateSingleton();
		}

		static TInstance* CreateTransient()
		{
			if (instance != nullptr || prototype.IsEmpty())
				return nullptr;

			return prototype.Invoke();
		}

		static void Remove()
		{
			V3DMemory::Delete(instance);
			prototype.Set(nullptr);
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
	template <typename TInstance> V3DFunc<TInstance*> V3DIoc<TInstance>::prototype;
}
