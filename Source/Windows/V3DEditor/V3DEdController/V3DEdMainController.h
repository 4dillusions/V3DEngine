/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEditor::V3DEdService
{
	class V3DEdMainService;
}

namespace V3D::V3DEngine
{
    namespace V3DIO
    {
        class V3DLogger;
    }

    namespace V3DCore
    {
        class V3DString;
    }
}

namespace V3D::V3DEditor::V3DEdController
{
    class V3DEdMainController final
    {
        V3DEdService::V3DEdMainService* mainService;

    public:
        V3DEdMainController(V3DEdService::V3DEdMainService* mainService, V3DEngine::V3DIO::V3DLogger* engineLogger);

        void OnToolBarAboutEditor() const;
        void OnToolBarAboutQt() const;
        
        void OnEngineLogTrigger(const V3DEngine::V3DCore::V3DString& log) const;

        void OnEngineLogDeleteAll() const;
        void OnOutputLogDeleteAll() const;
    };
}
