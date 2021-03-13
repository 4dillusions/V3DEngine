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

        [[nodiscard]] static bool GetIsRunModeDebug();
        [[nodiscard]] static const char* GetRunMode();
        [[nodiscard]] static bool GetIsUnitTestMode();
        [[nodiscard]] static const char* GetEngineName();
        [[nodiscard]] static const char* GetEngineVersion();

        static void SetUnitTestMode();
        static bool GetIsVSyncEnable();
        static void SetIsVSyncEnable(bool isVsyncEnable);

        static void SetApp(void* application);
        [[nodiscard]] static void* GetApp();
        void SetWindowSize(int width, int height);
        void SetScreenSize(int width, int height);
        static void SetGPUData(char* renderer, char* gpuName, int maxTextureSize);
        [[nodiscard]] static const int GetCpuCoreCount();
        [[nodiscard]] static const char* GetRenderMode();
        [[nodiscard]] static const char* GetGPUName();
        [[nodiscard]] static int GetMaxTextureSize();
        [[nodiscard]] static const char* GetGameName();
        static void SetGameName(char* gameName);

        [[nodiscard]] virtual const char* GetPlatformName() const = 0;
        [[nodiscard]] virtual int GetWindowWidth() const = 0;
        [[nodiscard]] virtual int GetWindowHeight() const = 0;
        [[nodiscard]] virtual int GetScreenWidth() const = 0;
        [[nodiscard]] virtual int GetScreenHeight() const = 0;
        [[nodiscard]] virtual const char* GetAssetPath(V3DAssetPathType assetPath) const = 0;
		
        [[nodiscard]] bool GetIsWindowOrientationPortrait() const;
        [[nodiscard]] V3DString GetSystemInfo() const;
	};
}
