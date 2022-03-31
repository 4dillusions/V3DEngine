/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DITextRepository.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DTestUIControl;
	
    class V3DTestUIControlJsonRepository final : public V3D::V3DEngine::V3DData::V3DITextRepository<V3DTestUIControl>
    {
    public:
        bool ConvertDataFromText(const char* text, V3DTestUIControl& dataOut) const override;
        char* ConvertTextFromData(const V3DTestUIControl& data) const override;
    };
}
