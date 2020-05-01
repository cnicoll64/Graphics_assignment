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
	void setPlayerText(Player p)
	{
		string playerColor = to_string(p.getColor());
		sf::Text textFront("", gameFont);
		text.setString(playerColor);
		text.setCharacterSize(15);
		sf::Text textEnd("", gameFont);
		playerNum.setString("Player's turn");
		text.setCharacterSize(15);
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
	sf::Sprite spriteArray[21];

		sf::Sprite p1(sf::Texture::LoadFromFile("Assets/One"));
		spriteArr[1] = p1;
		sf::Sprite p2(sf::Texture::LoadFromFile("Assets/Two"));
		spriteArr[2] = p2;
		sf::Sprite p3(sf::Texture::LoadFromFile("Assets/Three"));
		spriteArr[3] = p3;
		sf::Sprite p4(sf::Texture::LoadFromFile("Assets/Three_Line"));
		spriteArr[4] = p4;
		sf::Sprite p5(sf::Texture::LoadFromFile("Assets/Four_Line"));
		spriteArr[5] = p5;
		sf::Sprite p6(sf::Texture::LoadFromFile("Assets/Four_Square"));
		spriteArr[6] = p6;
		sf::Sprite p7(sf::Texture::LoadFromFile("Assets/Four_L"));
		spriteArr[7] = p7;
		sf::Sprite p8(sf::Texture::LoadFromFile("Assets/Four_T"));
		spriteArr[8] = p8;
		sf::Sprite p9(sf::Texture::LoadFromFile("Assets/Four_Z"));
		spriteArr[9] = p9;
		sf::Sprite p10(sf::Texture::LoadFromFile("Assets/Five_Straight"));
		spriteArr[10] = p10;
		sf::Sprite p11(sf::Texture::LoadFromFile("Assets/Five_L"));
		spriteArr[11] = p11;
		sf::Sprite p12(sf::Texture::LoadFromFile("Assets/Five_S"));
		spriteArr[12] = p12;
		sf::Sprite p13(sf::Texture::LoadFromFile("Assets/Five_T"));
		spriteArr[13] = p13;
		sf::Sprite p14(sf::Texture::LoadFromFile("Assets/Five_T_Peg"));
		spriteArr[14] = p14;
		sf::Sprite p15(sf::Texture::LoadFromFile("Assets/Five_Z"));
		spriteArr[15] = p15;
		sf::Sprite p16(sf::Texture::LoadFromFile("Assets/Five_Square_peg"));
		spriteArr[16] = p16;
		sf::Sprite p17(sf::Texture::LoadFromFile("Assets/Five_Cross_Long"));
		spriteArr[17] = p17;
		sf::Sprite p18(sf::Texture::LoadFromFile("Assets/Five_C"));
		spriteArr[18] = p18;
		sf::Sprite p19(sf::Texture::LoadFromFile("Assets/Five_Bat"));
		spriteArr[19] = p19;
		sf::Sprite p20(sf::Texture::LoadFromFile("Assets/Five_Plus"));
		spriteArr[20] = p20;
		sf::Sprite p21(sf::Texture::LoadFromFile("Assets/Five_Corner"));
		spriteArr[21] = p21;

	//draw and maybe tick?
	void drawBoard(Board* gameBoard)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				tile.setPosition((i * size) + 20, (j * size) + 20);
				Tile* temp = gameBoard->getGameTile(i, j);
				switch (temp->getPlayerColor())
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
				}
				window.draw(tile);
			}
		}
	}

	void drawPieces(BlokusShape piecesArray[21], Player p, sf::Sprite spriteArr[21])
	{
		for (int i = 0; i < 21; i++)
		{
			//int tempArray[5][5] = piecesArray.getGeo(); <- fix me
			if (!(piecesArray[i].placed()))
			{
				for (int j = 0; j < 5; j++)
				{
					for (int k = 0; k < 5; k++)
					{
						spriteArr[i].setPosition((j * 20) + (20 * i), (k * 20) + 600);
						/*switch (p.getColor())
						{
						case sf::Color::Red:
							tileSmall.setFillColor(sf::Color::Red);
							break;
						case sf::Color:Blue:
							tileSmall.setFillColor(sf::Color::Blue);
							break;
						case sf::Color::Green:
							tileSmall.setFillColor(sf::Color::Green);
							break;
						case sf::Color::Yellow:
							tileSmall.setFillColor(sf::Color::Yellow);
							break;
						default:
							tileSmall.setFillColor(sf::Color::Black);
							break;
						}
						if (PiecesArray[i].getSelected)
						{
							tileSmall.setOutlineThickness(4);
						}*/
						window.draw(tile);
					}
				}
				//draw each piece
			}
			//print each piece for the player(scaled?)
		}
	}

	while (window.isOpen())
	{
		window.clear();

		drawBoard(Board* gameBoard);
		drawPieces(BlokusShape piecesArray[21], Player p, spriteArray[]);
		
		
		//displays each player's turn
		text.setPosition(420, 890);
		playerNum.setPosition(430, 890);
		textEnd.setPosition(432, 890);
		//display each piece still available to the player at hand
		
		window.draw(text);
		window.draw(playerNum);
		window.draw(textEnd);
		window.display();
	}
	