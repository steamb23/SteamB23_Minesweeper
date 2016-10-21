#pragma once
#include "steamb23console.h"
struct TileInfo
{
    char value = ' ';
    SteamB23::ConsoleColor foregroundColor = SteamB23::ConsoleColor::Gray;
    SteamB23::ConsoleColor backgroundColor = SteamB23::ConsoleColor::Black;

    TileInfo()
    {
    }
    TileInfo(char value)
    {
        this->value = value;
    }
    TileInfo(char value, SteamB23::ConsoleColor foreColor, SteamB23::ConsoleColor backColor)
    {
        this->value = value;
        this->foregroundColor = foreColor;
        this->backgroundColor = backColor;
    }
};

