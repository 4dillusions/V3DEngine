/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngineTests::V3DEngine::V3DCollections
{
	class V3DCollectionsTests final
	{
	public:
		V3DCollectionsTests() = delete;
		V3DCollectionsTests(const V3DCollectionsTests&) = delete;
		V3DCollectionsTests(V3DCollectionsTests&&) = delete;
		~V3DCollectionsTests() = delete;
		V3DCollectionsTests& operator=(const V3DCollectionsTests&) = delete;
		V3DCollectionsTests& operator=(V3DCollectionsTests&&) = delete;

		static void RunAllTests();
	};
}
