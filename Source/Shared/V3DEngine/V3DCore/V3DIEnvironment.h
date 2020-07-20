/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DCore
{
	class V3DIEnvironment
	{
	public:
        V3DIEnvironment() = default;
        V3DIEnvironment(const V3DIEnvironment&) = default;
        V3DIEnvironment(V3DIEnvironment&&) = default;
        virtual ~V3DIEnvironment() = default;
        V3DIEnvironment& operator=(const V3DIEnvironment&) = delete;
        V3DIEnvironment& operator=(V3DIEnvironment&&) = delete;

        
	};
}
