#include "Tile.h"



Tile::Tile()
{
    tileState = TileState::Open;
}

TileInfo Tile::GetTileStateChar()
{
    // 타일 상태 체크하여 상태별 반환 값이 다르게함.
    // 타일이 열려있으면 GetTileValueChar()를 반환함.
    switch (this->tileState)
    {
    case TileState::None:
        return TileInfo(' ', SteamB23::ConsoleColor::Black, SteamB23::ConsoleColor::White);
    case TileState::Flag:
        return TileInfo('!', SteamB23::ConsoleColor::Red, SteamB23::ConsoleColor::White);
    case TileState::Mark:
        return TileInfo('?', SteamB23::ConsoleColor::Black, SteamB23::ConsoleColor::White);
    case TileState::Open:
        return GetTileValueChar();
    }
    return TileInfo('e', SteamB23::ConsoleColor::White, SteamB23::ConsoleColor::Gray);
}

TileInfo Tile::GetTileValueChar()
{

    SteamB23::ConsoleColor color;
    switch (nearCount)
    {
    case 1:
        color = SteamB23::ConsoleColor::Blue;
        break;
    case 2:
        color = SteamB23::ConsoleColor::DarkGreen;
        break;
    case 3:
        color = SteamB23::ConsoleColor::Red;
        break;
    case 4:
        color = SteamB23::ConsoleColor::DarkBlue;
        break;
    case 5:
        color = SteamB23::ConsoleColor::DarkRed;
        break;
    case 6:
        color = SteamB23::ConsoleColor::DarkCyan;
        break;
    case 7:
        color = SteamB23::ConsoleColor::Black;
        break;
    case 8:
        color = SteamB23::ConsoleColor::DarkGray;
        break;
    default:
        if (nearCount < 1)
            return TileInfo(' ', SteamB23::ConsoleColor::White, SteamB23::ConsoleColor::Gray);
        // 8보다 크면 error의 의미로 e를 표시
        if (nearCount > 8)
            return TileInfo('e', SteamB23::ConsoleColor::White, SteamB23::ConsoleColor::Black);
    }

    // 숫자를 문자형으로 변환후 반환
    char temp[10];
    _itoa_s(nearCount, temp, 10);
    return TileInfo(temp[0], color, SteamB23::ConsoleColor::Gray);
}

Tile::~Tile()
{
}
