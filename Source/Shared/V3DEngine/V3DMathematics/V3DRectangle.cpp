/*
V3D Game Engine
Copyright (c) 2020 by 4D Illusions. All rights reserved.
Released under the terms of the GNU General Public License version 3 or later.
*/

#include "V3DRectangle.h"
#include "V3DMath.h"

namespace V3D::V3DEngine::V3DMathematics
{
    V3DRectangle::V3DRectangle(float x, float y, float width, float height) : position{ x, y }, width{ width }, height{ height }
    { }

    V3DRectangle::V3DRectangle(const V3DVector2D& pos, const V3DVector2D& size) : position{ pos.x, pos.y }, width{ size.x }, height{ size.y }
    { }

    bool V3DRectangle::operator==(const V3DRectangle& value) const
    {
        return (position == value.position && V3DMath::IsEqual(width, value.width) && V3DMath::IsEqual(height, value.height));
    }

    bool V3DRectangle::operator!=(const V3DRectangle& value) const
    {
        return (position != value.position || !V3DMath::IsEqual(width, value.width) || !V3DMath::IsEqual(height, value.height));
    }

    float V3DRectangle::GetLeft() const
    {
        return position.x;
    }

    float V3DRectangle::GetRight() const
    {
        return (position.x + width);
    }

    float V3DRectangle::GetTop() const
    {
        return position.y;
    }

    float V3DRectangle::GetBottom() const
    {
        return (position.y + height);
    }

    void V3DRectangle::SetPosition(float x, float y)
    {
        position.x = x;
        position.y = y;
    }

    void V3DRectangle::SetPosition(const V3DVector2D& pos)
    {
        position = pos;
    }

    V3DVector2D& V3DRectangle::GetPosition()
    {
        return position;
    }

    V3DVector2D V3DRectangle::GetSize() const
    {
        return {width, height};
    }

    void V3DRectangle::SetSize(const V3DVector2D& size)
    {
        width = size.x;
        height = size.y;
    }

    V3DVector2D V3DRectangle::GetCenter() const
    {
        return {position.x + (width / 2), position.y + (height / 2)};
    }

    bool V3DRectangle::Contains(float x, float y) const
    {
        return ((((position.x <= x) && (x < (position.x + width))) && (position.y <= y)) && (y < (position.y + height)));
    }

    bool V3DRectangle::Contains(const V3DVector2D& pofloat) const
    {
        return ((((position.x <= pofloat.x) && (pofloat.x < (position.x + width))) && (position.y <= pofloat.y)) && (pofloat.y < (position.y + height)));
    }

    bool V3DRectangle::Contains(const V3DRectangle& value) const
    {
        return ((((position.x <= value.position.x) && ((value.position.x + value.width) <= (position.x + width))) &&
            (position.y <= value.position.y)) && ((value.position.y + value.height) <= (position.y + height)));
    }

    bool V3DRectangle::Intersects(const V3DRectangle& value) const
    {
        return ((((value.position.x < (position.x + width)) && (position.x < (value.position.x + value.width))) &&
            (value.position.y < (position.y + height))) && (position.y < (value.position.y + value.height)));
    }
}
