/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DEnvironment.h"
#include "V3DDateTime.h"
#include "V3DString.h"

#include <thread>

namespace V3D::V3DEngine::V3DCore
{
	void* V3DEnvironment::app{};
	bool V3DEnvironment::isUnitTestMode = false;
	bool V3DEnvironment::isVsyncEnable = false;
	char* V3DEnvironment::renderer{};
	char* V3DEnvironment::gpuName{};
	int V3DEnvironment::maxTextureSize{};
	char* V3DEnvironment::gameName{};
	int V3DEnvironment::windowWidth{};
	int V3DEnvironment::windowHeight{};
	int V3DEnvironment::screenWidth{};
	int V3DEnvironment::screenHeight{};
	
	bool V3DEnvironment::GetIsRunModeDebug()
	{
		#ifdef _DEBUG
			return true;
		#else
			return false;
		#endif
	}
	
	const char* V3DEnvironment::GetRunMode()
	{
		return GetIsRunModeDebug() ? "DEBUG" : "RELEASE";
	}

	bool V3DEnvironment::GetIsUnitTestMode()
	{
		return isUnitTestMode;
	}

	const char* V3DEnvironment::GetEngineName()
	{
		return "V3D Engine";
	}

	const char* V3DEnvironment::GetEngineVersion()
	{
		return "1.0";
	}

	void V3DEnvironment::SetUnitTestMode()
	{
		isUnitTestMode = true;
	}
	
	bool V3DEnvironment::GetIsVSyncEnable()
	{
		return isVsyncEnable;
	}
	
	void V3DEnvironment::SetIsVSyncEnable(bool isVsyncEnableValue)
	{
		isVsyncEnable = isVsyncEnableValue;
	}

	void V3DEnvironment::SetApp(void* application)
	{
		app = application;
	}

	void* V3DEnvironment::GetApp()
	{
		return app;
	}

	void V3DEnvironment::SetWindowSize(int width, int height)
	{
		windowWidth = width;
		windowHeight = height;
	}

	void V3DEnvironment::SetScreenSize(int width, int height)
	{
		screenWidth = width;
		screenHeight = height;
	}

	void V3DEnvironment::SetGPUData(char* rendererValue, char* gpuNameValue, int maxTextureSizeValue)
	{
		renderer = rendererValue;
		gpuName = gpuNameValue;
		maxTextureSize = maxTextureSizeValue;
	}

	int V3DEnvironment::GetCpuCoreCount()
	{
		static int res{ static_cast<int>(std::thread::hardware_concurrency()) };

		return res;
	}

	const char* V3DEnvironment::GetRenderMode()
	{
		return renderer;
	}

	const char* V3DEnvironment::GetGPUName()
	{
		return gpuName;
	}

	int V3DEnvironment::GetMaxTextureSize()
	{
		return maxTextureSize;
	}

	const char* V3DEnvironment::GetGameName()
	{
		return gameName;
	}

	void V3DEnvironment::SetGameName(char* gameNameValue)
	{
		gameName = gameNameValue;
	}

	bool V3DEnvironment::GetIsWindowOrientationPortrait()
	{
		return windowHeight > windowWidth;
	}

	V3DString V3DEnvironment::GetSystemInfo()
	{
		V3DString result;
		
		const V3DString timeStamp = V3DDateTime::GetTimeStamp();

		result += V3DString("start ") + GetEngineName() + " " + GetEngineVersion() + '\n';
		result += timeStamp + V3DString("platform: ") + GetPlatformName() + '\n';
		result += timeStamp + V3DString("run mode: ") + GetRunMode() + '\n';
		result += timeStamp + V3DString("CPU core count: ") + GetCpuCoreCount() + '\n';
		result += timeStamp + V3DString("renderer: ") + GetRenderMode() + '\n';
		result += timeStamp + V3DString("GPU name: ") + GetGPUName() + '\n';
		result += timeStamp + V3DString("maximum texture size: ") + GetMaxTextureSize() + '\n';
		result += timeStamp + V3DString("screen size: ") + GetScreenWidth() + " X " + GetScreenHeight() + '\n';
		result += timeStamp + V3DString("window orientation mode: ") + (GetIsWindowOrientationPortrait() ? "portrait" : "landscape") + '\n';
		result += timeStamp + V3DString("window size: ") + windowWidth + " X " + windowHeight + '\n';
		result += timeStamp + V3DString("vsync: ") + (GetIsVSyncEnable() ? "true" : "false") + '\n';
		result += timeStamp + V3DString("game name: ") + GetGameName();

		return result;
	}

	const char* V3DEnvironment::GetGameOptionsName()
	{
		return "GameOptions.json";
	}
}
