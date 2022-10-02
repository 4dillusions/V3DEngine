/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DData/V3DITextRepository.h"

namespace V3D::V3DEditor::V3DEdData
{
    struct V3DEdCameraModel;

    class V3DEdCameraJsonRepository final : public V3D::V3DEngine::V3DData::V3DITextRepository<V3DEdCameraModel>
    {
    public:
        bool ConvertDataFromText(const char* text, V3DEdCameraModel& dataOut) const override;
        char* ConvertTextFromData(const V3DEdCameraModel& data) const override;
    };
}
