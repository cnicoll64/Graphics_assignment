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

	return false; //allows building

}

bool Player::discardPiece(shape type)
{


	return false; //allows building

}

