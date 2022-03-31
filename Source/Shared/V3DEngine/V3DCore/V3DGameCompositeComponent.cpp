/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DGameCompositeComponent.h"
#include "V3DIoc.h"
#include "V3DString.h"

#include <cassert>

namespace V3D::V3DEngine::V3DCore
{
	V3DGameCompositeComponent::V3DGameCompositeComponent() : V3DGameComponent()
	{ }

	V3DGameCompositeComponent::V3DGameCompositeComponent(const char* name) : V3DGameComponent{ name }
	{ }

	V3DGameCompositeComponent::~V3DGameCompositeComponent()
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
		{
				V3DMemory::Delete(*componentList.GetCurrent());
				componentList.RemoveCurrent();
		}
	}

	V3DGameComponent* V3DGameCompositeComponent::Find(const char* name)
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
			if (V3DString((*componentList.GetCurrent())->GetName()) == V3DString(name))
				return *componentList.GetCurrent();

		return nullptr;
	}

	V3DGameComponent* V3DGameCompositeComponent::Find(const V3DGameComponent* gameComponent)
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
		{
			V3DGameComponent* current = *componentList.GetCurrent();

			if (*current == *gameComponent)
				return current;
		}

		return nullptr;
	}

	int V3DGameCompositeComponent::GetComponentsLength() const
	{
		return componentList.GetLength();
	}

	void V3DGameCompositeComponent::Add(V3DGameComponent* gameComponent)
	{
		static bool isDebugMode{ V3DEnvironment::GetIsRunModeDebug() };
		static bool isTestMode{ V3DEnvironment::GetIsUnitTestMode() };
		if (isDebugMode || isTestMode)
		{
			const bool isfounded = Find(gameComponent);

			if (isTestMode && isfounded)
				return;
			
			assert(!isfounded);
		}
		
		componentList.Add(gameComponent);
	}

	void V3DGameCompositeComponent::Remove(V3DGameComponent* gameComponent)
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
		{
			if (**componentList.GetCurrent() == *gameComponent)
			{
				componentList.RemoveCurrent();
				break;
			}
		}
	}

	void V3DGameCompositeComponent::Delete(V3DGameComponent* gameComponent)
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
		{
			if (**componentList.GetCurrent() == *gameComponent)
			{
				V3DMemory::Delete(*componentList.GetCurrent());
				componentList.RemoveCurrent();
				
				break;
			}
		}
	}

	void V3DGameCompositeComponent::Update(double deltaTime)
	{
		for (componentList.First(); componentList.IsDone(); componentList.Next())
		{
			if ((*componentList.GetCurrent())->GetIsAlive())
				(*componentList.GetCurrent())->Update(deltaTime);
			else
			{
				V3DMemory::Delete(*componentList.GetCurrent());
				componentList.RemoveCurrent();
			}
		}
	}

	void V3DGameCompositeComponent::SetIsAlive(bool isAlive)
	{
		this->isAlive = isAlive;

		for (componentList.First(); componentList.IsDone(); componentList.Next())
			(*componentList.GetCurrent())->SetIsAlive(isAlive);
	}

	void V3DGameCompositeComponent::SetIsVisible(bool isVisible)
	{
		this->isVisible = isVisible;

		for (componentList.First(); componentList.IsDone(); componentList.Next())
			(*componentList.GetCurrent())->SetIsVisible(isVisible);
	}
}
