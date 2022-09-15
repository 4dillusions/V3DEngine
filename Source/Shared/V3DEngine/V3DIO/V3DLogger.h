/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DLogMessageType.h"
#include "V3DLogOutputType.h"
#include "V3DEngine/V3DCore/V3DAction.h"

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DIO
{
    class V3DENGINE_API V3DLogger final  // NOLINT(clang-diagnostic-padded)
    {
        V3DCore::V3DAction1<const V3DCore::V3DString&> logTrigger;
        bool outputTypes[static_cast<unsigned int>(V3DLogOutputType::Count)]{};
        int warnings = 0, errors = 0;
        
        V3DCore::V3DString* buffer{};  // NOLINT(clang-diagnostic-padded)
        
        static void WriteLineToFile(const char* log);
        static void WriteLineToOutput(const char* log);

    public:
        V3DLogger();
        ~V3DLogger();

        const char* const LogFileName = "Log.txt";

        const char* const InfoTag = "[Info]";
        const char* const WarningTag = "[Warning]";
        const char* const ErrorTag = "[Error]";

        V3DLogger(const V3DLogger&) = delete;
        V3DLogger(V3DLogger&&) = delete;
        V3DLogger& operator=(const V3DLogger&) = delete;
        V3DLogger& operator=(V3DLogger&&) = delete;

        static V3DLogger& Get();
        
        void SetOutputTypeFlag(V3DLogOutputType outputType, bool isEnable);

        //Log trigger helps show logs another environment for example in editor
        void SetLogTrigger(const V3DCore::V3DAction1<const V3DCore::V3DString&>& otherLogTrigger);

        V3DCore::V3DString* GetBuffer() const;

        V3DCore::V3DString GetWarnings() const;
        V3DCore::V3DString GetErrors() const;
        int GetWarningCount() const;
        int GetErrorCount() const;

        void WriteOutput(const V3DCore::V3DString& log) const;
        void WriteOutput(V3DLogMessageType messageType, const V3DCore::V3DString& log);
        void WriteOutput(V3DLogMessageType messageType, const char* log);
        void WriteOutput(const char* log) const;
    };
}
