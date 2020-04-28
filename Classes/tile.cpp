#include "tile.h"

Tile::Tile()
{
	occupied = false;
}

bool Tile::isOccupied()
{
	return occupied;
}

color Tile::getPlayerColor()
{
	return playerColor;
}

bool Tile::setOccupied()
{
	occupied = true;
	return true;
}

bool Tile::setPlayerColor(color newPlayer)
{
	playerColor = newPlayer;
	return true;
}