/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DENGINE_API V3DGameComponent
	{
	public:
		bool isAlive{ true }, isVisible{ true };
		const char* Name{};
		const unsigned long long int Id{};
		
		V3DGameComponent();
		explicit V3DGameComponent(const char* name);
		V3DGameComponent(const V3DGameComponent&) = delete;
		V3DGameComponent(V3DGameComponent&&) = delete;
		virtual ~V3DGameComponent() = default;
		V3DGameComponent& operator=(const V3DGameComponent&) = delete;
		V3DGameComponent& operator=(V3DGameComponent&&) = delete;

		bool operator<(const V3DGameComponent& value) const;
		bool operator==(const V3DGameComponent& value) const;
		bool operator!=(const V3DGameComponent& value) const;

		unsigned long long int GetId() const;
		const char* GetName() const;
		bool GetIsAlive() const;
		virtual void SetIsAlive(bool isAlive);
		bool GetIsVisible() const;
		virtual void SetIsVisible(bool isVisible);

		virtual void Update(double deltaTime) = 0;
	};
}
