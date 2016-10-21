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
                (jl >= 0 && jl < tileContainer.GetColomn()) &&
                (typeid(*(tileContainer.GetTile(jl, ik).get())) == typeid(MineTile)))
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

void MinesweeperGame::Run()
{
}

void MinesweeperGame::CreateTileMap(int mineCount)
{
    int tileContainnerLength = tileContainer.GetColomn() * tileContainer.GetRow();
    if (mineCount > tileContainnerLength - 10)
        mineCount = tileContainnerLength - 10;


    // 타일 초기화
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            tileContainer.SetTile(j, i, new Tile());
        }
    }
    // 지뢰 배치
    std::knuth_b random(time(0));
    std::uniform_int_distribution<int> distribution(0, tileContainnerLength);
    auto generator = bind(distribution, random);
    for (int i = 0; i < mineCount; i++)
    {
        int x = generator() % tileContainer.GetColomn();
        int y = generator() % tileContainer.GetRow();
        tileContainer.SetTile(x, y, new MineTile());
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
