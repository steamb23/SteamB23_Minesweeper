#include <iostream>
#include "MinesweeperGame.h"

using namespace SteamB23;
using namespace std;

MinesweeperGame game(13,13);
void main()
{
    game.Run();
    SteamB23::Console::ReadKey();
}