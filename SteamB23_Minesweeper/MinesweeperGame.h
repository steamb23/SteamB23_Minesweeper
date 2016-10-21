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
    Point point;
    int mineCount;

    bool isTileMapCreated;
    bool isPrinted;
    bool* openedTiles;
    bool isGameover;
public:
    MinesweeperGame() : MinesweeperGame(15, 12, 20) {};
    MinesweeperGame(int width, int height, int mineCount);
    
    void Run();

    void CreateTileMap(int mineCount);
    void PrintTileMap(int left, int top);

    ~MinesweeperGame();
private:
    int CheckNearMineTile(int i, int j);
    // 방향키 관련 메서드
    void CursorMove(SteamB23::ConsoleKey key);
    // Z,X,C키 관련 메서드
    void GameKey(SteamB23::ConsoleKey key);

    void AllMineOpen();
    void Open(int x, int y);
    void InternalOpen(int x, int y);
};

