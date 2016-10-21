#include <iostream>
#include "MinesweeperGame.h"

using namespace SteamB23;
using namespace std;

void main()
{
    SteamB23::Console::SetTitle(TEXT("Áö·ÚÃ£±â"));
    MinesweeperGame game;
    game.Run();
}