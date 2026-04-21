#pragma once

#include "Entity.hpp"
#include "Types.hpp"
#include <unordered_map>

class World
{
public:
    EntityId createEntity()
    {
        EntityId id = ++nextId;
        entities[id] = Entity();
        return id;
    }

private:
    std::unordered_map<EntityId, Entity> entities;
    EntityId nextId{0};
};
