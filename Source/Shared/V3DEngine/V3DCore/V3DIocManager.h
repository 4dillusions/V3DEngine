/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	/*
		IocManager can automatically manage all registered objects' lifetime
	*/
	class V3DIocManager final
	{
		//definition will be implement in client program startup .cpp
		static void RegisterAndCreateSingletons();

		//definition will be implement in client program startup .cpp
		static void DeleteSingletonsAndRegisters();

	public:
		V3DIocManager(const V3DIocManager&) = delete;
		V3DIocManager(V3DIocManager&&) = delete;
		V3DIocManager& operator=(const V3DIocManager&) = delete;
		V3DIocManager& operator=(V3DIocManager&&) = delete;

		V3DIocManager()
		{
			RegisterAndCreateSingletons();
		}
		
		~V3DIocManager()
		{
			DeleteSingletonsAndRegisters();
		}
	};
}
