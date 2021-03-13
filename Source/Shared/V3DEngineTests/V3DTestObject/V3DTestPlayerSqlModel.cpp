/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DTestPlayerSqlModel.h"

using namespace V3D::V3DEngine::V3DCore;

namespace V3D::V3DEngineTests::V3DTestObject
{
    V3DTestPlayerSqlModel::V3DTestPlayerSqlModel(const V3DString& name) :  name{name}
    { }
	
    V3DTestPlayerSqlModel::V3DTestPlayerSqlModel(int id, const V3DString& name) : id{id}, name{name}
    { }
	
    bool V3DTestPlayerSqlModel::operator==(const V3DTestPlayerSqlModel& value) const
    {
        return (id == value.id && name == value.name);
    }

    bool V3DTestPlayerSqlModel::operator!=(const V3DTestPlayerSqlModel& value) const
    {
        return (id != value.id || name != value.name);
    }
	
    int V3DTestPlayerSqlModel::GetId() const
    {
        return id;
    }
	
    void V3DTestPlayerSqlModel::SetId(int id)
    {
        this->id = id;
    }
	
    V3DString V3DTestPlayerSqlModel::GetName() const
    {
        return name;
    }
	
    void V3DTestPlayerSqlModel::SetName(const V3DString& name)
    {
        this->name = name;
    }
	
    bool V3DTestPlayerSqlModel::GetIsValid() const
    {
        return id > 0 && !name.IsEmpty() && name.GetTextLength() < 20;
    }
}
