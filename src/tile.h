#pragma once

#include "entity.h"

namespace MR
{

enum class TileType
{
    SNOW,
    ICE,
    SOLID,
};

class Tile : public Entity
{
public:
    Tile(int x, int y, TileType tileType = TileType::SOLID);
    virtual void trigger(Entity *other) override;
};

}
