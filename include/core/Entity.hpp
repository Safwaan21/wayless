#pragma once

#include "Pos2.hpp"
#include "Types.hpp"

class Entity
{
public:
    EntityId getId() const
    {
        return id;
    }
    Pos2 getPos() const
    {
        return pos;
    }
protected:
    Pos2 pos;
private:
    EntityId id{};
};
