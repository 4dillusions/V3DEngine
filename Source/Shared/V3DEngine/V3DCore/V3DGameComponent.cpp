/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DGameComponent.h"

namespace V3D::V3DEngine::V3DCore
{
	V3DGameComponent::V3DGameComponent() : V3DGameComponent(nullptr)
	{ }
	
	V3DGameComponent::V3DGameComponent(const char* name) : Name{ name }, Id{ reinterpret_cast<unsigned long long int>(this) }
	{ }
	
	bool V3DGameComponent::operator<(const V3DGameComponent& value) const
	{
		return Id < value.Id;
	}

	bool V3DGameComponent::operator==(const V3DGameComponent& value) const
	{
		return Id == value.Id;
	}

	bool V3DGameComponent::operator!=(const V3DGameComponent& value) const
	{
		return Id != value.Id;
	}

	unsigned long long int V3DGameComponent::GetId() const
	{
		return Id;
	}

	const char* V3DGameComponent::GetName() const
	{
		return Name;
	}
	
	bool V3DGameComponent::GetIsAlive() const
	{
		return isAlive;
	}

	void V3DGameComponent::SetIsAlive(bool isAlive)
	{
		this->isAlive = isAlive;
	}

	bool V3DGameComponent::GetIsVisible() const
	{
		return isVisible;
	}

	void V3DGameComponent::SetIsVisible(bool isVisible)
	{
		this->isVisible = isVisible;
	}
}
