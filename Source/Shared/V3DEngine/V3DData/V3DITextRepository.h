/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DData
{
	template <typename TData> class V3DITextRepository
    {
    public:
        V3DITextRepository() = default;
        V3DITextRepository(const V3DITextRepository&) = default;
        V3DITextRepository(V3DITextRepository&&) = default;
        virtual ~V3DITextRepository() = default;
        V3DITextRepository& operator=(const V3DITextRepository&) = delete;
        V3DITextRepository& operator=(V3DITextRepository&&) = delete;

		virtual bool ConvertDataFromText(const char* text, TData& dataOut) const = 0;
		virtual char* ConvertTextFromData(const TData& data) const = 0;
    };
}
