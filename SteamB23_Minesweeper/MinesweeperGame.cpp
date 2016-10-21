#include "MinesweeperGame.h"



int MinesweeperGame::CheckNearMineTile(int j, int i)
{
    int result = 0;
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            int ik = i + k;
            int jl = j + l;

            if (!(k == 0 && l == 0) &&
                (ik >= 0 && ik < tileContainer.GetRow()) &&
                (jl >= 0 && jl < tileContainer.GetColomn())&&
                (typeid(*(tileContainer.GetTile(jl,ik).get())) == typeid(MineTile)))
            {
                result++;
            }
            bool a = true;
        }
    }
    return result;
}

MinesweeperGame::MinesweeperGame(int width, int height)
    :tileContainer(width, height)
{
}

void MinesweeperGame::CreateTileMap(int difficult)
{
    if (difficult > 100)
        difficult = 100;

    std::knuth_b random(time(0));
    std::uniform_int_distribution<int> distribution(0, 100);
    auto generator = bind(distribution, random);

    // 타일 배치
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            int gen = generator();
            if (difficult <= gen)
            {
                tileContainer.SetTile(j, i, new Tile());
            }
            else
            {
                tileContainer.SetTile(j, i, new MineTile());
            }
        }
    }
    // 타일 추적
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            tileContainer.GetTile(j, i)->SetNearCount(CheckNearMineTile(j, i));
        }
    }
}

void MinesweeperGame::PrintTileMap(int left, int top)
{
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            auto temp = tileContainer.GetTile(j, i)->GetTileStateChar();
            SteamB23::Console::SetCursorPosition(j, i);
            SteamB23::Console::SetBackgroundColor(temp.backgroundColor);
            SteamB23::Console::SetForegroundColor(temp.foregroundColor);
            std::cout << temp.value;
            SteamB23::Console::ResetColor();
        }
    }
}


MinesweeperGame::~MinesweeperGame()
{
}
