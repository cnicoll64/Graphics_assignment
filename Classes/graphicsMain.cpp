#include "std.h"
#include "menu.h"
#include "Blokus.h"
#include "piece.h"
#include "Player.h"
#include "tile.h"
#include "board.h"


	//chooseGame() member function will return either a 2, 3, or 4   - thease numbers stand for amount of users playing
	//after chooseGame the main Game object should be redefined to work with that amount of players, the rest show be computer players
	//ie if only two players are playing two computers should be generated
	//Note after menu has finished course, the window will be deleted, a new one should be created, constant Macros for size are in std.h file
int main() {
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

}

	//////////////////////////////////////////////////////////////////////////////////////end menu code



	int l = 20;
	int w = 20;
	int size = 43;
	int board[20][20];

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < w; j++)
		{
			board[i][j] = 0;
		}
	}

	//Create Title
	void setPlayerText(Player p, sf::RenderWindow window)
	{
		String playerColor = to_string(p.getColor());
		sf::Text textFront("", gameFont);
		text.setString(playerColor);
		text.setCharacterSize(15);
		sf::Text textEnd("", gameFont);
		playerNum.setString("Player's turn");
		text.setCharacterSize(15);

		text.setPosition(420, 890);
		playerNum.setPosition(430, 890);
		textEnd.setPosition(432, 890);

		window.draw(text);
		window.draw(playerNum);
		window.draw(textEnd);
	}


	//text.setColor(sf::Color::Red);

	sf::RectangleShape tile(sf::Vector2f(43, 43));
	tile.setFillColor(sf::Color::White);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);

	sf::RectangleShape tileSmall(sf::Vector2f(20, 20));
	tileSmall.setFillColor(sf::Color::Black);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(2);

	//Create pieces

	//Array of Sprites used for the pieces in the getPieces function
	sf::Sprite spriteArray[21];


	//draw and maybe tick?
	void drawBoard(Board * gameBoard)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				tile.setPosition((i * size) + 20, (j * size) + 20);
				Tile* temp = gameBoard->getGameTile(i, j);
				tile.setFillColor(temp->getPlayerColor);
				
				/*switch (temp->getPlayerColor())
				{
				case sf::Color::Red:
					tile.setFillColor(sf::Color::Red);
					break;
				case sf::Color::Blue:
					tile.setFillColor(sf::Color::Blue);
					break;
				case sf::Color::Green:
					tile.setFillColor(sf::Color::Green);
					break;
				case sf::Color::Yellow:
					tile.setFillColor(sf::Color::Yellow);
					break;
				default:
					tile.setFillColor(sf::Color::White);
					break;
				}*/
				window.draw(tile);
			}
		}
	}

	void drawPieces(BlokusShape piecesArray[21], Player& p, sf::Sprite spriteArr[21])
	{
		for (int i = 0; i < 21; i++)
		{
			//int tempArray[5][5] = piecesArray.getGeo(); <- fix me
			if (!(piecesArray[i].placed()))
			{
				spriteArr[i]->setPosition((20 * i) + 20, 600);
				window.draw(spriteArr[i]);
				//draw each piece
			}
			//print each piece for the player(scaled?)
		}
	}
