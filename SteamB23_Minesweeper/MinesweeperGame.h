#pragma once
#include <random>
#include <time.h>
#include <functional>
#include "steamb23console.h"

#include "TileContainner.h"
#include "Tile.h"
#include "MineTile.h"
class MinesweeperGame
{
    TileContainner tileContainer;

    int CheckNearMineTile(int i, int j);
public:
    MinesweeperGame() : MinesweeperGame(10, 10) {};
    MinesweeperGame(int width, int height);
    
    void Run();

    void CreateTileMap(int difficult);
    void PrintTileMap(int left, int top);

    ~MinesweeperGame();
private:
    
};

