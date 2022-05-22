/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

// ReSharper disable CppClangTidyClangDiagnosticPadded
#pragma once

#include "V3DITestObject.h"
#include "V3DEngine/V3DCore/V3DAction.h"
#include "V3DEngine/V3DCore/V3DFunc.h"
#include "V3DEngine/V3DCore/V3DEvent.h"

namespace V3D::V3DEngineTests::V3DTestObject
{
	struct V3DArgsTest final { int x; };
	
	class V3DTestObjectB final : public V3DITestObject
	{
		static int referenceCounter;
		int id{};

		bool isAlive{ true };

	public:
		V3DTestObjectB() = default;
		V3DTestObjectB(const V3DTestObjectB&) = delete;
		V3DTestObjectB(V3DTestObjectB&&) = delete;
		~V3DTestObjectB() override = default;
		V3DTestObjectB& operator=(const V3DTestObjectB&) = delete;
		V3DTestObjectB& operator=(V3DTestObjectB&&) = delete;

		V3D::V3DEngine::V3DCore::V3DAction TestAction;
		V3D::V3DEngine::V3DCore::V3DAction1<int> TestAction1;
		V3D::V3DEngine::V3DCore::V3DAction2<int, int> TestAction2;
		V3D::V3DEngine::V3DCore::V3DAction3<int, int, int> TestAction3;
		V3D::V3DEngine::V3DCore::V3DFunc<int> TestFunc;
		V3D::V3DEngine::V3DCore::V3DFunc1<int, int> TestFunc1;
		V3D::V3DEngine::V3DCore::V3DFunc2<int, int, int> TestFunc2;
		V3D::V3DEngine::V3DCore::V3DFunc3<int, int, int, int> TestFunc3;
		V3D::V3DEngine::V3DCore::V3DEvent<void()> TestNoParamEvent;
		V3D::V3DEngine::V3DCore::V3DEvent<V3DArgsTest> TestParamEvent;
		//void PerformTestEvent(Args args);
		
		char GetTypeCode() override;
		int GetId() override;
		void SetId(int idValue) override;
		bool GetIsAlive() override;
		void SetIsAlive(bool isAliveValue) override;
	};
}
