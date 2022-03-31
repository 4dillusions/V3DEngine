/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DData
{
	template <typename TData, typename TStream> class V3DIStreamRepository
    {
    public:
        V3DIStreamRepository() = default;
        V3DIStreamRepository(const V3DIStreamRepository&) = default;
        V3DIStreamRepository(V3DIStreamRepository&&) = default;
        virtual ~V3DIStreamRepository() = default;
        V3DIStreamRepository& operator=(const V3DIStreamRepository&) = delete;
        V3DIStreamRepository& operator=(V3DIStreamRepository&&) = delete;

		virtual void ReadDataFromStream(TStream& stream, TData& dataOut) const = 0;
		virtual void WriteDataToStream(const TData& data, TStream& streamOut) const = 0;
    };
}
