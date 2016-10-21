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

    bool isTileMapCreated;
    bool isPrinted;
    bool* openedTiles;
    bool isGameover;
public:
    MinesweeperGame() : MinesweeperGame(10, 10) {};
    MinesweeperGame(int width, int height);
    
    void Run();

    void CreateTileMap(int difficult);
    void PrintTileMap(int left, int top);

    ~MinesweeperGame();
private:
    int CheckNearMineTile(int i, int j);
    // ����Ű ���� �޼���
    void CursorMove(SteamB23::ConsoleKey key);
    // Z,X,CŰ ���� �޼���
    void GameKey(SteamB23::ConsoleKey key);

    void AllMineOpen();
    void Open(int x, int y);
    void InternalOpen(int x, int y);
};

