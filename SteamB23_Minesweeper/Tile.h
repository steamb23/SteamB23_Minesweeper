#pragma once
//#include "TileContainner.h"
#include <memory>
#include "TileInfo.h"
enum class TileState
{
    None,
    Flag,
    Mark,
    Open
};
class Tile
{
    int nearCount = 0;
    TileState tileState;
public:
    Tile();

    void AddNearCount() { this->nearCount++; };
    int GetNearCount() const { return this->nearCount; };
    void SetNearCount(int value) { this->nearCount = value; };
    TileState GetTileState() const { return this->tileState; };
    void SetTileState(TileState tileState) { this->tileState = tileState; };

    TileInfo GetTileStateChar();
    virtual TileInfo GetTileValueChar();

    virtual ~Tile();
};

