/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DEngine/V3DEngineLibrary.h"

namespace V3D::V3DEngine::V3DCore
{
	enum class V3DAssetPathType : unsigned;
	class V3DString;
	
	class V3DENGINE_API V3DAbstractEnvironment
	{
        static void* app;
        static bool isUnitTestMode;
		static bool isVsyncEnable;
        static char* renderer;
		static char *gpuName;
        static int maxTextureSize;
        static char* gameName;

    protected:
        int windowWidth{}, windowHeight{}, screenWidth{}, screenHeight{};
		
	public:
        V3DAbstractEnvironment() = default;
        V3DAbstractEnvironment(const V3DAbstractEnvironment&) = default;
        V3DAbstractEnvironment(V3DAbstractEnvironment&&) = default;
        virtual ~V3DAbstractEnvironment() = default;
        V3DAbstractEnvironment& operator=(const V3DAbstractEnvironment&) = delete;
        V3DAbstractEnvironment& operator=(V3DAbstractEnvironment&&) = delete;

        static bool GetIsRunModeDebug();
        static const char* GetRunMode();
        static bool GetIsUnitTestMode();
        static const char* GetEngineName();
        static const char* GetEngineVersion();

        static void SetUnitTestMode();
        static bool GetIsVSyncEnable();
        static void SetIsVSyncEnable(bool isVsyncEnable);

        static void SetApp(void* application);
        static void* GetApp();
        void SetWindowSize(int width, int height);
        void SetScreenSize(int width, int height);
        static void SetGPUData(char* renderer, char* gpuName, int maxTextureSize);
        static int GetCpuCoreCount();
        static const char* GetRenderMode();
        static const char* GetGPUName();
        static int GetMaxTextureSize();
        static const char* GetGameName();
        static void SetGameName(char* gameName);

        virtual const char* GetPlatformName() const = 0;
        virtual int GetWindowWidth() const = 0;
        virtual int GetWindowHeight() const = 0;
        virtual int GetScreenWidth() const = 0;
        virtual int GetScreenHeight() const = 0;
        virtual const char* GetAssetPath(V3DAssetPathType assetPath) const = 0;
		
        bool GetIsWindowOrientationPortrait() const;
        V3DString GetSystemInfo() const;
	};
}
