/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	class V3DAudioManualTests final
	{
	public:
		V3DAudioManualTests() = delete;
		V3DAudioManualTests(const V3DAudioManualTests&) = delete;
		V3DAudioManualTests(V3DAudioManualTests&&) = delete;
		~V3DAudioManualTests() = delete;
		V3DAudioManualTests& operator=(const V3DAudioManualTests&) = delete;
		V3DAudioManualTests& operator=(V3DAudioManualTests&&) = delete;

		static void InitAudioTest();
		static void PlaySFXAudioTest();

		static void RunAllTests();
	};
}
