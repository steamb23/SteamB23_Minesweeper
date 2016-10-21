#pragma once
#include <memory>
#include "Tile.h"
#include "Point.h"
class TileContainner
{
    std::unique_ptr<std::shared_ptr<Tile>[]> tiles;
    int tilesLength;
    int colomn;
    int row;

    // colomn = j = x;
    // row = i = y;
public:
    TileContainner();
    TileContainner(int colomn, int row);
    TileContainner(Point point);

    int GetColomn() const { return this->colomn; };
    int GetRow() const { return this->row; };
    Point GetColomnRow() const { return Point(this->colomn, this->row); };

    std::shared_ptr<Tile> GetTile(int colomn, int row) { return tiles[(row * this->colomn) + colomn]; };
    std::shared_ptr<Tile> GetTile(Point point) { return this->GetTile(point.x, point.y); };
    void SetTile(int colomn, int row, std::shared_ptr<Tile> value) { tiles[(row * this->colomn) + colomn] = value; };
    void SetTile(Point point, std::shared_ptr<Tile> value) { this->SetTile(point.x, point.y, value); };
    void SetTile(int colomn, int row, Tile* value) { this->SetTile(colomn, row, std::shared_ptr<Tile>(value)); };
    void SetTile(Point point, Tile* value) { this->SetTile(point, std::shared_ptr<Tile>(value)); };

    ~TileContainner();
};

