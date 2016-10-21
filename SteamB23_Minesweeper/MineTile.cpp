#include "MineTile.h"



MineTile::MineTile()
{
}

TileInfo MineTile::GetTileValueChar()
{
    return TileInfo('*', SteamB23::ConsoleColor::Black, SteamB23::ConsoleColor::Gray);
}

MineTile::~MineTile()
{
}
