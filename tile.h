#ifndef TILE_H
#define TILE_H

#include "std.h"
#include "Player.h"

class Tile
{
private:
	bool occupied;
	color playerColor;

public:
	Tile();
	bool isOccupied();
	color getPlayerColor();
	bool setOccupied();
	bool setPlayerColor(color newPlayer);
};
#endif