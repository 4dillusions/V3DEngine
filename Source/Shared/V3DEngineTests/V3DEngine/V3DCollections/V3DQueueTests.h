/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DQueueTests final
	{
	public:
		V3DQueueTests() = delete;
		V3DQueueTests(const V3DQueueTests&) = delete;
		V3DQueueTests(V3DQueueTests&&) = delete;
		~V3DQueueTests() = delete;
		V3DQueueTests& operator=(const V3DQueueTests&) = delete;
		V3DQueueTests& operator=(V3DQueueTests&&) = delete;

		static void CtorDtorTest();
		static void QueueStaticTest();
		static void QueueDynamicTest();

		static void RunAllUnitTests();
		static void RegisterIntegrationTests();
		static void RegisterTimingTests();
	};
}
