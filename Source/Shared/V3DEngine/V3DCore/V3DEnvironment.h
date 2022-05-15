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
	
	class V3DENGINE_API V3DEnvironment
	{
        static void* app;
        static bool isUnitTestMode;
		static bool isVsyncEnable;
        static char* renderer;
		static char *gpuName;
        static int maxTextureSize;
        static char* gameName;
        static int windowWidth;
        static int windowHeight;
        static int screenWidth;
        static int screenHeight;
		
	public:
        V3DEnvironment() = default;
        V3DEnvironment(const V3DEnvironment&) = default;
        V3DEnvironment(V3DEnvironment&&) = default;
        virtual ~V3DEnvironment() = default;
        V3DEnvironment& operator=(const V3DEnvironment&) = delete;
        V3DEnvironment& operator=(V3DEnvironment&&) = delete;

        static bool GetIsRunModeDebug();
        static const char* GetRunMode();
        static bool GetIsUnitTestMode();
        static const char* GetEngineName();
        static const char* GetEngineVersion();

        static void SetUnitTestMode();
        static bool GetIsVSyncEnable();
        static void SetIsVSyncEnable(bool isVsyncEnableValue);

        static void SetApp(void* application);
        static void* GetApp();
        static void SetWindowSize(int width, int height);
        static void SetScreenSize(int width, int height);
        static void SetGPUData(char* rendererValue, char* gpuNameValue, int maxTextureSizeValue);
        static int GetCpuCoreCount();
        static const char* GetRenderMode();
        static const char* GetGPUName();
        static int GetMaxTextureSize();
        static const char* GetGameName();
        static void SetGameName(char* gameNameValue);
        static bool GetIsWindowOrientationPortrait();
        static V3DString GetSystemInfo();

        //definitions will be implement in platform specific .cpp
        static const char* GetPlatformName();
        static int GetWindowWidth();
        static int GetWindowHeight();
        static int GetScreenWidth();
        static int GetScreenHeight();
        static const char* GetAssetPath(V3DAssetPathType assetPath);
	};
}
