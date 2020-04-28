#include "BlokusShape.h"

BlokusShape::BlokusShape()
{


}

int BlokusShape::getTileNum()
{
	return tileNum;
}

shape BlokusShape::getType()
{
	return type;
}

int BlokusShape::getTypeInt()
{
	return (int)type;
}

direction BlokusShape::getOrientation()
{
	return orientation;
}

bool BlokusShape::getStatus()
{
	return status;
}

bool BlokusShape::isFlipped()
{
	return flipped;
}

bool BlokusShape::flip()
{
	if (flipped = true)
	{
		flipped = false;
		return 1;
	}
	flipped = true;
	return 1;
}

bool BlokusShape::setTileNum(int newNum)
{
	tileNum = newNum;
	return true;
}

bool BlokusShape::setType(shape newType)
{
	type = newType;
	return true;
}

bool BlokusShape::rotate(bool clockwise)
{
	if (clockwise) // does not allow for counterclockwise rotation in north orientation or clockwise in west orientation
	{
		orientation = (direction)(orientation + 1);
		return true;
	}
	orientation = (direction)(orientation - 1);
	return true; 
}

bool BlokusShape::placed()
{
	status = false;
	return true;
}