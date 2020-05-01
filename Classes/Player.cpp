#include "Player.h"
#include "board.h"

Player::Player(color newPlayerColor)
{
	playerColor = newPlayerColor;
	for (int index = 0; index < 20; ++index)
	{
		pieces[index].setType((shape)index);
	}
}

color Player::getColor()
{
	return playerColor;
}

BlokusShape Player::getShape(int shapeNum)
{
	return pieces[shapeNum];
}

int Player::shapeNum()
{
	int n = 0;
	for (int index = 0; index < 21; ++index)
	{
		if (pieces[index].getStatus())
		{
			++n;
		}
	}
	return n;
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