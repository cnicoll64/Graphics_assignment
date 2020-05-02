#ifndef BLOKUSSHAPE_H
#define BLOKUSSHAPE_H

#include "std.h"

enum shape{One, Two, ThreeL, ThreeLine, Cube, FourT, FourLine, FourL, FourS, FiveL, FiveT, FiveEvenL, FiveLongS, FiveZ, FiveLine,
	FiveCubeNub, FiveSnake, FiveC, FiveSNub, FiveCross, FiveLineNub};

enum direction{North, East, South, West}; // north orientation is defined by blokusOrientationReference.png

//class Tile                 -class used for pointer-to-tiles method
//{
//protected:
//	bool centerTile;
//	direction fromCenter;
//	Tile* northTile;
//	Tile* southTile;
//	Tile* eastTile;
//	Tile* westTile;
//
//public:
//	Tile();
//	bool isCenter();
//	Tile* getNorth();
//	Tile* getSouth();
//	Tile* getEast();
//	Tile* getWest();
//	bool setNorth(Tile newTile);
//	bool setSouth(Tile newTile);
//	bool setEast(Tile newTile);
//	bool setWest(Tile newTile);
//};

class BlokusShape
{
private:
	shape type;
	direction orientation;
	bool flipped; // if true, shape is flipped horizontally (only allows for different shapes for a few pieces)
	bool status; // if true, shape is avalible to be placed

public:
	BlokusShape();
	shape getType();
	int getTypeInt();
	direction getOrientation();
	bool isFlipped();
	bool getStatus();
	bool setType(shape newType);
	bool rotate(bool clockwise); // 1 is clockwise, 0 is counterclockwise
	bool placed();
	bool flip();
};


#endif