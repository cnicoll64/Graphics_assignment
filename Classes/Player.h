#ifndef PLAYER_H
#define PLAYER_H

#include "std.h"
#include "BlokusShape.h"

enum color { None, Red, Blue, Green, Yellow };

class Player
{
protected:
	color playerColor;
	BlokusShape pieces[21];

public:
	Player(color newPlayerColor);
	color getColor();
	BlokusShape getShape(int shapeNum);
	bool hasPiece(shape type);
	bool discardPiece(shape type);
};

#endif