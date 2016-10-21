#include "TileContainner.h"



TileContainner::TileContainner()
    :TileContainner(10,10)
{
}

TileContainner::TileContainner(int colomn, int row)
{
    this->colomn = colomn;
    this->row = row;
    this->tilesLength = colomn * row;
    this->tiles = std::make_unique<std::shared_ptr<Tile>[]>(tilesLength);
}

TileContainner::TileContainner(Point point)
    :TileContainner(point.x, point.y)
{
}


TileContainner::~TileContainner()
{
}
