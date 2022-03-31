/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DCryptographyHelper.h"
#include "V3DEngine/V3DCore/V3DString.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngine::V3DCryptography
{
	V3DString V3DCryptographyHelper::ConvertHexArrayToString(const unsigned char* hexArray, int arraySize)
	{
		V3DString result("");
		
		for (int i = 0; i < arraySize; i++)
		{
			const auto upper = static_cast<unsigned char>(hexArray[i] >> 4);
			result += static_cast<char>((upper < 10) ? (upper + '0') : (upper - 10 + 'a'));

			const unsigned char lower = hexArray[i] & 0xf;
			result += static_cast<char>((lower < 10) ? (lower + '0') : (lower - 10 + 'a'));
		}

		return result;
	}
}
