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

//TwoPlayer definitons here

TwoPlayer_Game::TwoPlayer_Game()
{
	player3 = new AIPlayer(Green);
	player4 = new AIPlayer(Yellow);
}

void TwoPlayer_Game::playGame()
{

	//add game def here
	
	
}

//three player defs here

ThreePlayer_Game::ThreePlayer_Game()
{
	player3 = new Player(Green);
	player4 = new AIPlayer(Yellow);
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
