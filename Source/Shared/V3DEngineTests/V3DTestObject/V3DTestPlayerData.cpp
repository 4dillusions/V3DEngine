/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestPlayerData.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DTestObject
{
    V3DTestPlayerData::V3DTestPlayerData(V3DString name) :  name{std::move(name)}
    { }
	
    V3DTestPlayerData::V3DTestPlayerData(int id, V3DString name) : id{id}, name{std::move(name)}
    { }
	
    bool V3DTestPlayerData::operator==(const V3DTestPlayerData& value) const
    {
        return (id == value.id && name == value.name);
    }

    bool V3DTestPlayerData::operator!=(const V3DTestPlayerData& value) const
    {
        return (id != value.id || name != value.name);
    }
	
    int V3DTestPlayerData::GetId() const
    {
        return id;
    }
	
    void V3DTestPlayerData::SetId(int idValue)
    {
        id = idValue;
    }
	
    V3DString V3DTestPlayerData::GetName() const
    {
        return name;
    }
	
    void V3DTestPlayerData::SetName(const V3DString& nameValue)
    {
        name = nameValue;
    }
	
    bool V3DTestPlayerData::GetIsValid() const
    {
        return id > 0 && !name.IsEmpty() && name.GetTextLength() < 20;
    }
}
