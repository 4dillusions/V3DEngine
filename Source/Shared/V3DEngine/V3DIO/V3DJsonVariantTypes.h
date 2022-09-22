/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DIO
{
    enum class V3DJsonVariantTypes : unsigned int
    {
		Null,
		Boolean,
		IntNumber,
		UnsignedIntNumber,
		DoubleNumber,
		Text,
		Object,
		Array
    };
}
