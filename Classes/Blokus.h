#ifndef Blokus_H
#define Blokus_H

#include "std.h"
#include "Classes/board.h"
#include "Classes/tile.h"

//Pure Virtual Game driver object
class Blokus
{
public:
	Blokus();

	//pure virtual declaration
	virtual void playGame() = 0;


private:
	Board *GameBoard;
	Player* player1;
	Player* player2;
	sf::RenderWindow* GameWindow;

	//add sprites and textures here
};


//derived 1v1 game

class TwoPlayer_Game : public Blokus
{

public:
	TwoPlayer_Game();
	void playGame();


private:
	Board* GameBoard;
	Player* player1;
	Player* player2;

	//add AI here

	sf::RenderWindow* GameWindow;
};


//derived ThreePlayer here

class ThreePlayer_Game : public Blokus {

public:
	ThreePlayer_Game();
	void playGame();


private:
	Board* GameBoard;
	Player* player1;
	Player* player2;
	Player* player3;

	//add AI here

	sf::RenderWindow* GameWindow;

};


//declairation of four player game here

class FourPlayer_Game : public Blokus {

public:
	FourPlayer_Game();
	void playGame();


private:
	Board* GameBoard;
	Player* player1;
	Player* player2;
	Player* player3;
	Player* player4;

	

	sf::RenderWindow* GameWindow;

};




#endif

