/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DIO/V3DIOStream.h"
#include "V3DEngine/V3DEngineLibrary.h"
#include "V3DLogMessageType.h"
#include "V3DLogOutputType.h"

#include <functional>

namespace V3D::V3DEngine::V3DCore
{
	class V3DString;
}

namespace V3D::V3DEngine::V3DIO
{
    class V3DENGINE_API V3DLogger final
    {
        bool outputTypes[static_cast<unsigned int>(V3DLogOutputType::Count)]{};
        std::function<void(const V3DCore::V3DString& log)> logTrigger = nullptr;

        V3DIOstream* oStream;    	
        V3DCore::V3DString* buffer = nullptr;

        int warnings = 0, errors = 0;

    public:
        const char* const LogFileName = "Log.txt";

        const char* const InfoTag = "[Info]";
        const char* const WarningTag = "[Warning]";
        const char* const ErrorTag = "[Error]";

        V3DLogger();
        V3DLogger(const V3DLogger&) = delete;
        V3DLogger(V3DLogger&&) = delete;
        ~V3DLogger() = default;
        V3DLogger& operator=(const V3DLogger&) = delete;
        V3DLogger& operator=(V3DLogger&&) = delete;

        //Avoid buffer leak before detecting
        void DeleteBuffer();

        void SetOutputTypeFlag(V3DLogOutputType outputType, bool isEnable);

        //Log trigger helps show logs another environment for example in editor
        void SetLogTrigger(const std::function<void(const V3DCore::V3DString& log)>& logTrigger);

        [[nodiscard]] V3DCore::V3DString const* GetBuffer() const;

        [[nodiscard]] V3DCore::V3DString GetWarnings() const;
        [[nodiscard]] V3DCore::V3DString GetErrors() const;
        [[nodiscard]] int GetWarningCount() const;
        [[nodiscard]] int GetErrorCount() const;

        void WriteOutput(const V3DCore::V3DString& log);
        void WriteOutput(V3DLogMessageType messageType, const V3DCore::V3DString& log);
        void WriteOutput(V3DLogMessageType messageType, const char* log);
        void WriteOutput(const char* log);
    };
}