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

private:
    EntityId id{};
    Pos2 pos;
};
