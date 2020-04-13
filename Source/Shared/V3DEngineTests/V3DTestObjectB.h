/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DITestObject.h"

namespace V3D::V3DEngineTests
{
	class Args final
	{
	public:
		int x;
	};
	
	class V3DTestObjectB final : public V3DITestObject
	{
		static int referenceCounter;
		int id{};

	public:
		V3DTestObjectB() = default;
		V3DTestObjectB(const V3DTestObjectB&) = default;
		V3DTestObjectB(V3DTestObjectB&&) = default;
		virtual ~V3DTestObjectB() = default;
		V3DTestObjectB& operator=(const V3DTestObjectB&) = delete;
		V3DTestObjectB& operator=(V3DTestObjectB&&) = delete;

		//LF3Engine::LFEngine::LFCore::LFCommon::LFEvent<Args> TestEvent;
		//void PerformTestEvent(Args args);
		
		char GetTypeCode() override;
		int GetId() override;
		void SetId(int id) override;
	};
}
