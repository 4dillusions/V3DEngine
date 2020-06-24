/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

#include "V3DITestObject.h"

namespace V3D::V3DEngineTests
{
	class V3DTestObjectA final : public V3DITestObject
	{
		static int referenceCounter;
		int id{};
		bool isAlive{ true };

	public:
		V3DTestObjectA();
		explicit V3DTestObjectA(int id);
		V3DTestObjectA(const V3DTestObjectA&);
		V3DTestObjectA(V3DTestObjectA&&) = default;
		~V3DTestObjectA() override;
		V3DTestObjectA& operator=(const V3DTestObjectA&) = default;
		V3DTestObjectA& operator=(V3DTestObjectA&&) = default;

		char GetTypeCode() override;
		int GetId() override;
		void SetId(int id) override;
		bool GetIsAlive() override;
		void SetIsAlive(bool isAlive) override;

		static int GetReferenceCounter();
		static void SetReferenceCounter(int counter);
	};
}
