#ifndef PLAYER_H
#define PLAYER_H

#include "std.h"
#include "BlokusShape.h"

using namespace std;

enum color { Red, Blue, Green, Yellow };

class Player
{
protected:
	color playerColor;
	BlokusShape pieces[21];

public:
	Player();
	color getColor();
	bool setColor(color newColor);
	bool hasPiece(shape type);
	bool discardPiece(shape type);
};

#endif