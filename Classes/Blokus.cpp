#include "Blokus.h"
#include "menu.h"

//default constructor for Game objects
Blokus::Blokus()
{

	//data structures that belong to all diverived game class'
	GameBoard = new Board;
	
	player1 = new Player(Blue);
	player2 = new Player(Red);

	//initializes GameWindow
	GameWindow = new sf::RenderWindow(sf::VideoMode(Window_Width, Window_Height), "Blokus", sf::Style::Default);
	GameWindow->setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);

	GameWindow->setFramerateLimit(120);

	//Create Game Font
	gameFont = new sf::Font;
	if (!gameFont->loadFromFile("Righteous-Regular.ttf"));

	//set for player-turn 
	text = new sf::Text;
	text->setCharacterSize(15);
	text->setString("");

}

void Blokus::printGrid()
{
	//initial size
	int x = (Window_Width - 25 * 20) / 2;
	int y = 200;

	//sets a grid of rectangles
	for (int i = 0; i < 20; i++) {

		for (int j = 0; j < 20; j++) {

			//prints blank grid

			square = new sf::RectangleShape(sf::Vector2f(25, 25));
			square->setOutlineColor(sf::Color::Black);
			square->setOutlineThickness(5);
			square->setPosition(sf::Vector2f(25 * i + x, 25 * j + y));

			//sets interior to right color
			if (GameBoard->getGameTile(i, j).getPlayerColor() == Green) {
				square->setFillColor(sf::Color::Green);
			} 
			else if (GameBoard->getGameTile(i, j).getPlayerColor() == Blue) {
				square->setFillColor(sf::Color::Blue);
			}
			else if (GameBoard->getGameTile(i, j).getPlayerColor() == Red) {
				square->setFillColor(sf::Color::Red);
			}
			else if (GameBoard->getGameTile(i, j).getPlayerColor() == Yellow) {
				square->setFillColor(sf::Color::Yellow);
			}
			else if (GameBoard->getGameTile(i, j).getPlayerColor() == None) {
				square->setFillColor(sf::Color::White);
			}




			GameWindow->draw(*square);

		}
	}
}

//TwoPlayer definitons here

TwoPlayer_Game::TwoPlayer_Game()
{
	

	GameBoard->placePiece(10, 15, *player1, FiveL);

	GameBoard->placePiece(5, 10, *player2, FiveC);

	while (GameWindow->isOpen()) {
	
		sf::Event* event = new sf::Event;

		while (GameWindow->pollEvent(*event)) {

			if (event->type == sf::Event::Closed) {
				GameWindow->close();

			}

			GameWindow->clear(sf::Color::Color(214, 214, 214, 255));

			printGrid();




			GameWindow->display();
		}
	}
}

void TwoPlayer_Game::playGame()
{

	//add game def here
	
	
}

//three player defs here

ThreePlayer_Game::ThreePlayer_Game()
{
	player3 = new Player(Green);

	//add AI
}

void ThreePlayer_Game::playGame()
{


	//add thre player def here
}

//definitions for FourPlayer Game here

FourPlayer_Game::FourPlayer_Game()
{
	player3 = new Player(Green);
	player4 = new Player(Yellow);
}

void FourPlayer_Game::playGame()
{

	//more game stuff
}
