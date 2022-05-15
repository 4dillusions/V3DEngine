/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DGameComponent.h"
#include "V3DEngine/V3DCollections/V3DObjectPool.h"
#include "V3DString.h"

namespace V3D::V3DEngine::V3DCore
{
	template<typename TGameComponent> class V3DGameCompositeComponentPool : public V3DGameComponent
	{
	protected:
		V3DCollections::V3DObjectPool<TGameComponent> componentPool;

	public:
		V3DGameCompositeComponentPool(const V3DGameCompositeComponentPool&) = delete;
		V3DGameCompositeComponentPool(V3DGameCompositeComponentPool&&) = delete;
		~V3DGameCompositeComponentPool() override = default;
		V3DGameCompositeComponentPool& operator=(const V3DGameCompositeComponentPool&) = delete;
		V3DGameCompositeComponentPool& operator=(V3DGameCompositeComponentPool&&) = delete;
		
		explicit V3DGameCompositeComponentPool(int size) : V3DGameComponent(), componentPool{ size }
		{ }
		
		explicit V3DGameCompositeComponentPool(const char* name, int size) : V3DGameComponent{ name }, componentPool{ size }
		{ }
		
		virtual TGameComponent* Find(const char* name)
		{
			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
				if (V3DString((componentPool.GetCurrent())->GetName()) == V3DString(name))
					return componentPool.GetCurrent();

			return nullptr;
		}
		
		virtual TGameComponent* Find(const TGameComponent* gameComponent)
		{
			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
			{
				TGameComponent* current = componentPool.GetCurrent();

				if (*current == *gameComponent)
					return current;
			}

			return nullptr;
		}
		
		//bool IsLastVisible(const V3DString& name);
		
		int GetComponentsLength() const
		{
			return componentPool.GetLength();
		}

		virtual TGameComponent* Add()
		{
			return componentPool.Add();
		}
		
		virtual void Remove(TGameComponent* gameComponent) //After render only
		{
			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
			{
				if (*componentPool.GetCurrent() == *gameComponent)
				{
					componentPool.RemoveCurrent();
					break;
				}
			}
		}
		
		//V3DGameComponent abstractions
		void Update(double deltaTime) override
		{
			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
			{
				if (componentPool.GetCurrent()->GetIsAlive())
					componentPool.GetCurrent()->Update(deltaTime);
				else
					componentPool.RemoveCurrent();
			}
		}
		
		void SetIsAlive(bool isAliveValue) override
		{
			isAlive = isAliveValue;

			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
				componentPool.GetCurrent()->SetIsAlive(isAliveValue);
		}
		
		void SetIsVisible(bool isVisibleValue) override
		{
			isVisible = isVisibleValue;

			for (componentPool.First(); componentPool.IsDone(); componentPool.Next())
				componentPool.GetCurrent()->SetIsVisible(isVisibleValue);
		}
	};
}
