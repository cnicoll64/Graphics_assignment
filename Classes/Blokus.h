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

	//graphics functions
	void printGrid();
	void placeShape(Player& input, shape currentpeice);
	bool highlightTexture(sf::Sprite& input, sf::RenderWindow &window);

	//pure virtual declaration
	virtual void playGame() = 0;


protected:
	bool HighlighTextField(sf::RectangleShape& input, sf::RenderWindow& window);
	Board *GameBoard;
	Player* player1;
	Player* player2;
	bool isNum(string& input);

	//graphic stuff below
	sf::RenderWindow* GameWindow;
	sf::Font* gameFont;
	sf::Texture* placebtn, * endbtn, *CW, *CCW;

	sf::Text* text, *rotation;
	sf::RectangleShape* square;
	sf::Sprite* Place_Shape, * EndTurn, *ROT_CW, *ROT_CCW;

	//add sprites and textures here
};


//derived 1v1 game

class TwoPlayer_Game : public Blokus
{

public:
	TwoPlayer_Game();
	void playGame();

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

