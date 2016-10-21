#pragma once
class Point
{
public:
    int x, y;
    Point() :Point(x, y) {};
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

