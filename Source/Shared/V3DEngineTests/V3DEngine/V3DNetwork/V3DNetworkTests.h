/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DNetwork
{
	class V3DNetworkTests final
	{
	public:
		V3DNetworkTests() = delete;
		V3DNetworkTests(const V3DNetworkTests&) = delete;
		V3DNetworkTests(V3DNetworkTests&&) = delete;
		~V3DNetworkTests() = delete;
		V3DNetworkTests& operator=(const V3DNetworkTests&) = delete;
		V3DNetworkTests& operator=(V3DNetworkTests&&) = delete;

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
