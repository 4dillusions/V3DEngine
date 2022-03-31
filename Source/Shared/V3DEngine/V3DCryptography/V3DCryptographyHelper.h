/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DCryptography
{
	class V3DENGINE_API V3DCryptographyHelper final
	{
	public:
		V3DCryptographyHelper() = delete;
		V3DCryptographyHelper(const V3DCryptographyHelper&) = delete;
		V3DCryptographyHelper(V3DCryptographyHelper&&) = delete;
		~V3DCryptographyHelper() = delete;
		V3DCryptographyHelper& operator=(const V3DCryptographyHelper&) = delete;
		V3DCryptographyHelper& operator=(V3DCryptographyHelper&&) = delete;

		static V3DCore::V3DString ConvertHexArrayToString(const unsigned char* hexArray, int arraySize);
	};
}
