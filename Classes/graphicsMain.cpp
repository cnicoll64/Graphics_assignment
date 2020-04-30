#include "std.h"
#include "menu.h"
#include "Blokus.h"

int main(void)
{

	//chooseGame() member function will return either a 2, 3, or 4   - thease numbers stand for amount of users playing
	//after chooseGame the main Game object should be redefined to work with that amount of players, the rest show be computer players
	//ie if only two players are playing two computers should be generated
	//Note after menu has finished course, the window will be deleted, a new one should be created, constant Macros for size are in std.h file

	int gametype;
	menu Start_Screen; //displays intial game menu

	gametype = Start_Screen.chooseGame();

	
	switch (gametype) {

	case 2: { //two player Game w/ two AI
		TwoPlayer_Game Game_two;

		Game_two.playGame();

		break;
	}case 3: { //three player Game w/ one AI
		ThreePlayer_Game Game_three;

		Game_three.playGame();

		break;

	}case 4: { //four player Game no AI
		FourPlayer_Game Game_four;

		Game_four.playGame();

		break;

	}default:
			//end program
		break;

	}




	//////////////////////////////////////////////////////////////////////////////////////end menu code


	//Create Window
	sf::RenderWindow window(sf::VideoMode(900, 900), "Blokus");
	window.setFramerateLimit(120);

	//Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("Righteous-Regular.ttf");
	//Create Title
	sf::Text text("", gameFont);
	text.setString("Blokus");
	text.setCharacterSize(35);
	//text.setColor(sf::Color::Red);

	//Create Board
	sf::RectangleShape board(sf::Vector2f(850, 850));
	board.setFillColor(sf::Color::White);
	board.setPosition(25, 25);
	//how to create lines for a grid?? Probably very thin rectangles

	//Create each shape(all 21)
	//back-end will help determine what color shapes are


	//Render to screen
	window.clear();
	window.draw(board);
	window.draw(text);
	window.display();




	return 0;
}