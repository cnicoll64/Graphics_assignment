#ifndef BOARD_H
#define BOARD_H

#include "std.h"
#include "Player.h"
#include "tile.h"

class Board
{
private:
	Tile game[20][20];

public:
	Board() {}
	bool fillTile(int x, int y, Player p);
	Tile getGameTile(int x, int y);
	int validCornerX(color c);
	int validCornerY(color c);
	bool placePiece(int xCenter, int yCenter, Player &p, shape s);
	bool validate(int xCenter, int yCenter, Player p, shape s);
	int redTiles();
	int blueTiles();
	int greenTiles();
	int yellowTiles();
};

#endif