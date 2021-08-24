/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#pragma once

namespace V3D::V3DEngine::V3DData
{
	template <typename TData> class V3DISQLRepository
    {
    public:
        V3DISQLRepository() = default;
        V3DISQLRepository(const V3DISQLRepository&) = default;
        V3DISQLRepository(V3DISQLRepository&&) = default;
        virtual ~V3DISQLRepository() = default;
        V3DISQLRepository& operator=(const V3DISQLRepository&) = delete;
        V3DISQLRepository& operator=(V3DISQLRepository&&) = delete;

		virtual TData Select(const TData& data) const = 0;
        virtual bool Insert(TData& data) const = 0;
        virtual bool Update(const TData& data) const = 0;
	    virtual bool Delete(const TData& data) const = 0;
	    virtual bool DeleteAll() const = 0;
    };
}
