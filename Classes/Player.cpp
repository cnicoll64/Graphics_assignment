#include "Player.h"

Player::Player()
{


}

color Player::getColor()
{
	return playerColor;
}

bool Player::setColor(color newColor)
{
	playerColor = newColor;
	return true;
}

bool Player::hasPiece(shape type)
{


}

bool Player::discardPiece(shape type)
{


}