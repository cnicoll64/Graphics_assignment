#ifndef BLOKUSSHAPE_H
#define BLOKUSSHAPE_H

#include "std.h"

enum shape{Single, Double, ThreeL, ThreeLine, Cube, FourT, FourLine, FourL, FourS, FiveL, FiveT, FiveEvenL, FiveLongS, FiveZ, FiveLine,
	FiveCubeNub, FiveSnake, FiveC, FiveSNub, FiveCross, FiveLineNub};

enum direction{North, South, East, West};

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
protected:
	int tileNum;
	shape type;
	direction orientation;
	bool status;

public:
	BlokusShape();
	int getTileNum();
	shape getType();
	direction getOrientation();
	bool getStatus();
	bool setTileNum(int newNum);
	bool setType(shape newType);
	bool rotate(bool direction); //direction: 1 is clockwise, 0 is counterclockwise
	bool setStatus(bool newStatus);
};


#endif