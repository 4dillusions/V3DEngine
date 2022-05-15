/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DGameComponent.h"
#include "V3DEngine/V3DCollections/V3DLinkedList.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DGameCompositeComponent : public V3DGameComponent
	{
	protected:
		V3DCollections::V3DLinkedList<V3DGameComponent*> componentList;  // NOLINT(clang-diagnostic-padded)

	public:
		V3DGameCompositeComponent();
		explicit V3DGameCompositeComponent(const char* name);
		V3DGameCompositeComponent(const V3DGameCompositeComponent&) = delete;
		V3DGameCompositeComponent(V3DGameCompositeComponent&&) = delete;
		~V3DGameCompositeComponent() override;
		V3DGameCompositeComponent& operator=(const V3DGameCompositeComponent&) = delete;
		V3DGameCompositeComponent& operator=(V3DGameCompositeComponent&&) = delete;

		virtual V3DGameComponent* Find(const char* name);
		virtual V3DGameComponent* Find(const V3DGameComponent* gameComponent);
		//bool IsLastVisible(const V3DString& name);
		int GetComponentsLength() const;

		virtual void Add(V3DGameComponent* gameComponent);
		virtual void Remove(V3DGameComponent* gameComponent); //After render only
		virtual void Delete(V3DGameComponent* gameComponent); //After render only
		
		//V3DGameComponent abstraction
		void Update(double deltaTime) override;
		void SetIsAlive(bool isAliveValue) override;
		void SetIsVisible(bool isVisibleValue) override;
	};
}
