/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DAudio
{
	class V3DAudioIntegrationTests final
	{
	public:
		V3DAudioIntegrationTests() = delete;
		V3DAudioIntegrationTests(const V3DAudioIntegrationTests&) = delete;
		V3DAudioIntegrationTests(V3DAudioIntegrationTests&&) = delete;
		~V3DAudioIntegrationTests() = delete;
		V3DAudioIntegrationTests& operator=(const V3DAudioIntegrationTests&) = delete;
		V3DAudioIntegrationTests& operator=(V3DAudioIntegrationTests&&) = delete;

		static void InitAudioTest();
		static void PlaySFXAudioTest();

		static void RunAllTests();
	};
}
