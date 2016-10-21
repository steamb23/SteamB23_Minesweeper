#pragma once
#include "Tile.h"
class MineTile :
    public Tile
{
public:
    MineTile();

    virtual TileInfo GetTileValueChar() override;

    virtual ~MineTile();
};

