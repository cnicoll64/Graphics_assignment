#include "BlokusShape.h"

BlokusShape::BlokusShape()
{
	status = true;
	flipped = false;
	orientation = North;

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
	if (flipped == true)
	{
		flipped = false;
		return 1;
	}
	flipped = true;
	return 1;
}

bool BlokusShape::setType(shape newType)
{
	type = newType;
	return true;
}

bool BlokusShape::rotate(bool clockwise)
{
	if (clockwise)
	{
		if ((int)getOrientation() < 3) // if orientation is not West
		{
			orientation = (direction)(orientation + 1); // rotate clockwise
			return true; //exit
		}
		orientation = North; // else set equal to North
		return true; //exit
	}
	if ((int)getOrientation() > 1) // if  orientation is not North
	{
		orientation = (direction)(orientation - 1);// rotate counterclockwise
		return true; //exit
	}
	orientation = West; // else set equal to West
	return true; //exit
}

bool BlokusShape::placed()
{
	status = false;
	return true;
}