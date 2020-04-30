#include <SFML/Graphics.hpp>
#include <string>
#include "piece.h"

int main(void)
{
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

	//Create Window
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Blokus");
	window.setFramerateLimit(120);

	//Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("Righteous-Regular.ttf");
	//Create Title
	sf::Text text("", gameFont);
	text.setString("Player ");
	text.setCharacterSize(15);
	sf::Text playerNum("", gameFont);
	playerNum.setString(currentPlayer.getNum());
	text.setCharacterSize(15);
	sf::Text textEnd("", gameFont);
	playerNum.setString("'s turn");
	text.setCharacterSize(15);

	//text.setColor(sf::Color::Red);

	sf::RectangleShape tile(sf::Vector2f(43, 43));
	tile.setFillColor(sf::Color::White);
	tile.setOutlineColor(sf::Color::Black);
	tile.setOutlineThickness(5);

	sf::RectangleShape tileSmall(sf::Vector2f(20, 20));
	tileSmall.setFillColor(sf::Color::Black);
	tile.setOutlineColor(sf::Color:Black);
	tile.setOutlineThickness(2); 

	//Create pieces
	for (int i = 1; i <= 4; i++)
	{
		Piece p1 = new Piece(i);
		p1.setShape(1);
		Piece p2 = new Piece(i);
		p2.setShape(1, 2);
		Piece p3 = new Piece(i);
		p3.setShape(1, 2, 7);
		Piece p4 = new Piece(i);
		p4.setShape(1, 2, 3);
		Piece p5 = new Piece(i);
		p5.setShape(1, 2, 6, 7);
		Piece p6 = new Piece(i);
		p6.setShape(2, 6, 7, 8);
		Piece p7 = new Piece(i);
		p7.setShape(1, 2, 3, 4);
		Piece p8 = new Piece(i);
		p8.setShape(3, 6, 7, 8);
		Piece p9 = new Piece(i);
		p9.setShape(2, 3, 6, 7);
		Piece p10 = new Piece(i);
		p10.setShape(1, 6, 7, 8, 9);
		Piece p11 = new Piece(i);
		p11.setShape(2, 7, 11, 12, 13);
		Piece p12 = new Piece(i);
		p12.setShape(1, 6, 11, 12, 13);
		Piece p13 = new Piece(i);
		p13.setShape(2, 3, 4, 6, 7);
		Piece p14 = new Piece(i);
		p14.setShape(3, 6, 7, 8, 11);
		Piece p15 = new Piece(i);
		p15.setShape(1, 6, 11, 16, 21);
		Piece p16 = new Piece(i);
		p16.setShape(1, 6, 11, 7, 12);
		Piece p17 = new Piece(i);
		p17.setShape(2, 3, 6, 7, 11);
		Piece p18 = new Piece(i);
		p18.setShape(1, 2, 6, 11, 12);
		Piece p19 = new Piece(i);
		p19.setShape(2, 3, 6, 7, 12);
		Piece p20 = new Piece(i);
		p20.setShape(2, 6, 7, 8, 12);
		Piece p21 = new Piece(i);
		p21.setShape(2, 6, 7, 8, 9);
	}

	//draw and maybe tick?
	while (window.isOpen())
	{
		window.clear();

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				tile.setPosition((i * size) + 20, (j * size) + 20);
				switch (board[i][j])
				{
				case 1:
					tile.setFillColor(sf::Color::Red);
					break;
				case 2:
					tile.setFillColor(sf::Color::Blue);
					break;
				case 3:
					tile.setFillColor(sf::Color::Green);
					break;
				case 4:
					tile.setFillColor(sf::Color::Yellow);
					break;
				default:
					tile.setFillColor(sf::Color::White);
					break;
				}
				window.draw(tile);
			}
		}

		//displays each player's turn
		text.setPosition(420, 890);
		playerNum.setPosition(430, 890);
		textEnd.setPosition(432, 890);
		//display each piece still available to the player at hand
		for (int i = 0; i < 21; i++)
		{
			int tempArray[5][5] = piecesArray.getGeo();
			if (!(piecesArray[i].getPlayed))
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						tileSmall.setPosition((j * 20) + (20 * i), (k * 20) + 600);
						switch (tempArray[i][j])
						{
						case 1:
							tileSmall.setFillColor(sf::Color::Red);
							break;
						case 2:
							tileSmall.setFillColor(sf::Color::Blue);
							break;
						case 3:
							tileSmall.setFillColor(sf::Color::Green);
							break;
						case 4:
							tileSmall.setFillColor(sf::Color::Yellow);
							break;
						default:
							tileSmall.setFillColor(sf::Color::Black);
							break;
						}
						if (PieceArray[i].getSelected)
						{
							tileSmall.setOutlineThickness(4);
						}
						window.draw(tile);
					}
				}
				//draw each piece
			}
			//print each piece for the player(scaled?)
		}
		window.draw(text);
		window.draw(playerNum);
		window.draw(textEnd);
		window.display();
	}




	return 0;
}