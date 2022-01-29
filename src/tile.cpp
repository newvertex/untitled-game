#include "tile.h"

#include "assets.h"

namespace MR
{

Tile::Tile(int x, int y, TileType tiletype)
    : Entity(x, y)
{
    int textureId = Assets::ENV_TILE_SOLID;
    if (tiletype == TileType::ICE)
    {
        textureId = Assets::ENV_TILE_ICE;
    }
    else if (tiletype == TileType::SNOW)
    {
        textureId = Assets::ENV_TILE_SNOW;
    }

    setSprite(new Sprite(2, x, y, 65, 65, textureId));
    setHitBoxRect({-32, -12, 64, 46});
    setGroupTag("GROUND");
}

void Tile::trigger(Entity *other)
{
}

}
