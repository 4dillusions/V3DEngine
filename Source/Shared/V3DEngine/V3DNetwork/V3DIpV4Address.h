/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngine::V3DNetwork
{
	struct V3DENGINE_API V3DIpV4Address final
	{
		int addr1{ 0 }, addr2{ 0 }, addr3{ 0 }, addr4{ 0 };

		V3DIpV4Address(int addr1, int addr2, int addr3, int addr4);
		explicit V3DIpV4Address (const V3DCore::V3DString& ipAddress);

		V3DCore::V3DString ToString() const;
	};
}
