#ifndef Blokus_H
#define Blokus_H

#include "std.h"
#include "Classes/board.h"
#include "Classes/tile.h"
#include "Scoreboard.h"

//Pure Virtual Game driver object
class Blokus
{
public:
	Blokus();

	//graphics functions
	void printGrid();
	void placeShape(Player& input, shape currentpeice);
	bool highlightTexture(sf::Sprite& input, sf::RenderWindow &window);
	shape drawPieces(Player& p, sf::Sprite spriteArr[21], sf::RenderWindow& window);

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
	sf::Texture* One_T, * Two_T, * Three_T, * Three_Line_T, * Four_Line_T, * Four_Square_T, * Four_L_T, * Four_T_T, * Four_Z_T;
	sf::Texture* Five_Straight_T, * Five_L_T, * Five_S_T, * Five_T_T, * Five_T_Peg_T, * Five_Z_T, * Five_Square_Peg_T;
	sf::Texture* Five_Cross_Long_T, * Five_C_T, * Five_Bat_T, * Five_Plus_T, * Five_Corner_T;

	sf::Text* text, *rotation;
	sf::RectangleShape* square;
	sf::Sprite* Place_Shape, * EndTurn, *ROT_CW, *ROT_CCW;
	sf::Sprite* One, * Two, * Three, * Three_Line, * Four_Square, * Four_L, *Four_Line, * Four_T, * Four_Z;
	sf::Sprite* Five_Straight, * Five_L, * Five_S, * Five_T, * Five_T_Peg, * Five_Z, * Five_Square_Peg;
	sf::Sprite* Five_Cross_Long, * Five_C, * Five_Bat, * Five_Plus, * Five_Corner;

	sf::Sprite spriteArray[21];

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

