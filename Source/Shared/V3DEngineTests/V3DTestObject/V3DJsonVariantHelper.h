/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DCore/V3DString.h"

namespace V3D::V3DEngine::V3DIO
{
	class V3DJsonVariant;
}

namespace V3D::V3DEngineTests::V3DTestObject
{
	class V3DJsonVariantHelper final
	{
	public:
		static V3D::V3DEngine::V3DCore::V3DString ToStringType(const V3D::V3DEngine::V3DIO::V3DJsonVariant& variant);
		static V3D::V3DEngine::V3DCore::V3DString ToStringValue(const V3D::V3DEngine::V3DIO::V3DJsonVariant& variant);
	};
}
