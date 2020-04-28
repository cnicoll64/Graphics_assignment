#include "Player.h"

Player::Player(color newPlayerColor)
{
	playerColor = newPlayerColor;
}

color Player::getColor()
{
	return playerColor;
}

BlokusShape Player::getShape(int shapeNum)
{
	return pieces[shapeNum];
}

bool Player::hasPiece(shape type)
{
	for (int index = 0; index < 21; ++index)
	{
		if (pieces[index].getTypeInt() == (int)type)
		{
			if (pieces[index].getStatus())
			{
				return true;
			}
		}
	}
	return false;

}

bool Player::discardPiece(shape type)
{
	if (hasPiece(type))
	{
		for (int index = 0; index < 21; ++index)
		{
			if (pieces[index].getTypeInt() == (int)type)
			{
				pieces[index].placed();
				return true;
			}
		}
	}

	return false;
}