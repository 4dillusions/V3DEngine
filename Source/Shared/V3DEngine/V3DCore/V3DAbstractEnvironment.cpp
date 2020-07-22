/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DAbstractEnvironment.h"

#include "V3DDateTime.h"
#include "V3DString.h"

namespace V3D::V3DEngine::V3DCore
{
	bool V3DAbstractEnvironment::isUnitTestMode = false;
	bool V3DAbstractEnvironment::isVsyncEnable = false;
	char* V3DAbstractEnvironment::renderer{};
	char* V3DAbstractEnvironment::gpuName{};
	int V3DAbstractEnvironment::maxTextureSize{};
	char* V3DAbstractEnvironment::gameName{};
	
	bool V3DAbstractEnvironment::GetIsRunModeDebug()
	{
		#ifdef _DEBUG
			return true;
		#else
			return false;
		#endif
	}
	
	const char* V3DAbstractEnvironment::GetRunMode()
	{
		return GetIsRunModeDebug() ? "DEBUG" : "RELEASE";
	}

	bool V3DAbstractEnvironment::GetIsUnitTestMode()
	{
		return isUnitTestMode;
	}

	const char* V3DAbstractEnvironment::GetEngineName()
	{
		return "V3D Engine";
	}

	const char* V3DAbstractEnvironment::GetEngineVersion()
	{
		return "1.0";
	}

	void V3DAbstractEnvironment::SetUnitTestMode()
	{
		isUnitTestMode = true;
	}
	
	bool V3DAbstractEnvironment::GetIsVSyncEnable()
	{
		return isVsyncEnable;
	}
	
	void V3DAbstractEnvironment::SetIsVSyncEnable(bool isVsyncEnable)
	{
		V3DAbstractEnvironment::isVsyncEnable = isVsyncEnable;
	}

	void V3DAbstractEnvironment::SetWindowSize(int width, int height)
	{
		windowWidth = width;
		windowHeight = height;
	}

	void V3DAbstractEnvironment::SetScreenSize(int width, int height)
	{
		screenWidth = width;
		screenHeight = height;
	}

	void V3DAbstractEnvironment::SetGPUData(char* renderer, char* gpuName, int maxTextureSize)
	{
		V3DAbstractEnvironment::renderer = renderer;
		V3DAbstractEnvironment::gpuName = gpuName;
		V3DAbstractEnvironment::maxTextureSize = maxTextureSize;
	}

	const char* V3DAbstractEnvironment::GetRenderMode()
	{
		return renderer;
	}

	const char* V3DAbstractEnvironment::GetGPUName()
	{
		return gpuName;
	}

	int V3DAbstractEnvironment::GetMaxTextureSize()
	{
		return maxTextureSize;
	}

	const char* V3DAbstractEnvironment::GetGameName()
	{
		return gameName;
	}

	void V3DAbstractEnvironment::SetGameName(char* gameName)
	{
		V3DAbstractEnvironment::gameName = gameName;
	}

	bool V3DAbstractEnvironment::GetIsWindowOrientationPortrait() const
	{
		return windowHeight > windowWidth;
	}

	const char *V3DAbstractEnvironment::GetSystemInfo() const
	{
		static V3DString result;
		result.Clear();
		
		const V3DString timeStamp = V3DDateTime::GetTimeStamp();

		result += V3DString("start ") + GetEngineName() + " " + GetEngineVersion() + '\n';
		result += timeStamp + V3DString("platform: ") + GetPlatformName() + '\n';
		result += timeStamp + V3DString("run mode: ") + GetRunMode() + '\n';
		result += timeStamp + V3DString("renderer: ") + GetRenderMode() + '\n';
		result += timeStamp + V3DString("GPU name: ") + GetGPUName() + '\n';
		result += timeStamp + V3DString("maximum texture size: ") + GetMaxTextureSize() + '\n';
		result += timeStamp + V3DString("screen size: ") + GetScreenWidth() + " X " + GetScreenHeight() + '\n';
		result += timeStamp + V3DString("window orientation mode: ") + (GetIsWindowOrientationPortrait() ? "portrait" : "landscape") + '\n';
		result += timeStamp + V3DString("window size: ") + windowWidth + " X " + windowHeight + '\n';
		result += timeStamp + V3DString("vsync: ") + (GetIsVSyncEnable() ? "true" : "false") + '\n';
		result += timeStamp + V3DString("game name: ") + GetGameName();

		return result.ToChar();
	}
}
