#include "std.h"


int main(void)
{

	menu test; //displays intial game menu

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