/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCollections/V3DStack.h"
#include "V3DAction.h"

namespace V3D::V3DEngine::V3DCore
{
	/*
		IocContainer is base class with remove actions container for Ioc
	*/
	class V3DENGINE_API V3DIocContainer
	{
	protected:
		static V3D::V3DEngine::V3DCollections::V3DStack<V3DAction>* removeActionsContainer;

	public:
		V3DIocContainer() = default;
		V3DIocContainer(const V3DIocContainer&) = delete;
		V3DIocContainer(V3DIocContainer&&) = delete;
		virtual ~V3DIocContainer() = default;
		V3DIocContainer& operator=(const V3DIocContainer&) = delete;
		V3DIocContainer& operator=(V3DIocContainer&&) = delete;

		//initialize remove actions container
		static void Init(int size);

		//cleanup Ioc containers by type
		static void Clean();
	};
}
