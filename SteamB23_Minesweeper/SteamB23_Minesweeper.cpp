#include <iostream>
#include "MinesweeperGame.h"

using namespace SteamB23;
using namespace std;

MinesweeperGame game(15,12);
void main()
{
    game.CreateTileMap(20);
    game.PrintTileMap(0,0);
    SteamB23::Console::ReadKey();
}