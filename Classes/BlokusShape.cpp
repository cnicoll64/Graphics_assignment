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

direction BlokusShape::getOrientation()
{
	return orientation;
}

bool BlokusShape::getStatus()
{
	return status;
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

bool BlokusShape::rotate(bool direction)
{

	return false; //allows building
}

bool BlokusShape::setStatus(bool newStatus)
{
	status = newStatus;
	return true;
}