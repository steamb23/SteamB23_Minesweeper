#include "MinesweeperGame.h"



MinesweeperGame::MinesweeperGame(int width, int height)
    :tileContainer(width, height)
{
    // 타일 초기화
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            tileContainer.SetTile(j, i, new Tile());
        }
    }
}

void MinesweeperGame::Run()
{
    PrintTileMap(0, 0);
    SteamB23::Console::SetCursorPosition(point.x, point.y);
    while (!isGameover)
    {
        SteamB23::ConsoleKey key = SteamB23::Console::ReadKey().Key;
        CursorMove(key);
        GameKey(key);
        if (!isPrinted)
            PrintTileMap(0, 0);
        SteamB23::Console::SetCursorPosition(point.x, point.y);
    }
    // 키입력까지 대기
    SteamB23::Console::ReadKey();
}

void MinesweeperGame::CreateTileMap(int mineCount)
{
    int tileContainnerLength = tileContainer.GetColomn() * tileContainer.GetRow();
    if (mineCount > tileContainnerLength - 10)
        mineCount = tileContainnerLength - 10;

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
    SteamB23::Console::SetCursorPosition(0, 0);
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
    isPrinted = true;
}


MinesweeperGame::~MinesweeperGame()
{
}

int MinesweeperGame::CheckNearMineTile(int j, int i)
{
    int result = 0;
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            int ik = i + k;
            int jl = j + l;

            if (!(k == 0 && l == 0))
            {
                if (ik >= 0 && ik < tileContainer.GetRow())
                {
                    if (jl >= 0 && jl < tileContainer.GetColomn())
                    {
                        if (typeid(*(tileContainer.GetTile(jl, ik).get())) == typeid(MineTile))
                        {
                            result++;
                        }
                    }
                }
            }
        }
    }
    return result;
}

void MinesweeperGame::CursorMove(SteamB23::ConsoleKey key)
{
    int x, y;
    switch (key)
    {
    case SteamB23::ConsoleKey::UpArrow:
        x = point.x;
        y = point.y--;
        if (point.y < 0)
            point.y = y;
        break;
    case SteamB23::ConsoleKey::DownArrow:
        x = point.x;
        y = point.y++;
        if (point.y >= tileContainer.GetRow())
            point.y = y;
        break;
    case SteamB23::ConsoleKey::RightArrow:
        x = point.x++;
        y = point.y;
        if (point.x >= tileContainer.GetColomn())
            point.x = x;
        break;
    case SteamB23::ConsoleKey::LeftArrow:
        x = point.x--;
        y = point.y;
        if (point.x < 0)
            point.x = x;
        break;
    }
}

void MinesweeperGame::GameKey(SteamB23::ConsoleKey key)
{
    switch (key)
    {
        // Open
    case SteamB23::ConsoleKey::Z:
        if (!isTileMapCreated)
        {
            CreateTileMap(20);
            isTileMapCreated = true;
        }
        Open(point.x, point.y);
        break;
    }
}
void MinesweeperGame::AllMineOpen()
{
    for (int i = 0; i < tileContainer.GetRow(); i++)
    {
        for (int j = 0; j < tileContainer.GetColomn(); j++)
        {
            if (typeid(*(tileContainer.GetTile(j, i).get())) == typeid(MineTile))
                tileContainer.GetTile(j, i)->SetTileState(TileState::Open);
        }
    }
}
void MinesweeperGame::Open(int x, int y)
{
    int length = tileContainer.GetRow() * tileContainer.GetColomn();
    openedTiles = new bool[length];
    ZeroMemory(openedTiles, length);

    // 모든 방향 한칸에 지뢰가 없으면 연쇄적으로 오픈
    tileContainer.GetTile(x, y)->SetTileState(TileState::Open);
    openedTiles[y*tileContainer.GetColomn() + x] = true;
    if (typeid(*(tileContainer.GetTile(x, y).get())) == typeid(MineTile))
    {
        AllMineOpen();
        isGameover = true;
    }
    else if (tileContainer.GetTile(x, y)->GetNearCount() == 0)
    {
        InternalOpen(x, y);
    }
    delete[] openedTiles;
    isPrinted = false;
}

void MinesweeperGame::InternalOpen(int i, int j)
{
    for (int k = -1; k <= 1; k++)
    {
        for (int l = -1; l <= 1; l++)
        {
            int ik = i + k;
            int jl = j + l;

            if (!(k == 0 && l == 0))
            {
                if (ik >= 0 && ik < tileContainer.GetColomn())
                {
                    if (jl >= 0 && jl < tileContainer.GetRow())
                    {
                        // 열려있지 않을 경우
                        if (!openedTiles[jl * tileContainer.GetColomn() + ik])
                        {
                            tileContainer.GetTile(ik, jl)->SetTileState(TileState::Open);
                            openedTiles[(jl * tileContainer.GetColomn()) + ik] = true;

                            if (tileContainer.GetTile(ik, jl)->GetNearCount() == 0)
                            {
                                InternalOpen(ik, jl);
                            }
                        }
                    }
                }
            }
        }
    }
}
