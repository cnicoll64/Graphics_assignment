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
	rotation = new sf::Text;

	text->setCharacterSize(15);
	text->setString("");

	rotation->setCharacterSize(13);
	rotation->setFont(*gameFont);
	rotation->setFillColor(sf::Color::Black);

	placebtn = new sf::Texture;
	endbtn = new sf::Texture;
	CW = new sf::Texture;
	CCW = new sf::Texture;
	One_T = new sf::Texture;
	Two_T = new sf::Texture;
	Three_T = new sf::Texture;
	Three_Line_T = new sf::Texture;
	Four_Line_T = new sf::Texture;
	Four_Square_T = new sf::Texture;
	Four_L_T = new sf::Texture;
	Four_T_T = new sf::Texture;
	Four_Z_T = new sf::Texture;
	Five_Straight_T = new sf::Texture;
	Five_L_T = new sf::Texture;
	Five_S_T = new sf::Texture;
	Five_T_T = new sf::Texture;
	Five_T_Peg_T = new sf::Texture;
	Five_Z_T = new sf::Texture;
	Five_Square_Peg_T = new sf::Texture;
	Five_Cross_Long_T = new sf::Texture;
	Five_C_T = new sf::Texture;
	Five_Bat_T = new sf::Texture;
	Five_Plus_T = new sf::Texture;
	Five_Corner_T = new sf::Texture;
	EndTurn = new sf::Sprite;
	Place_Shape = new sf::Sprite;
	ROT_CW = new sf::Sprite;
	ROT_CCW = new sf::Sprite;
	One = new sf::Sprite;
	Two = new sf::Sprite;
	Three = new sf::Sprite;
	Three_Line = new sf::Sprite;
	Four_Line = new sf::Sprite;
	Four_Square = new sf::Sprite;
	Four_L = new sf::Sprite;
	Four_T = new sf::Sprite;
	Four_Z = new sf::Sprite;
	Five_Straight = new sf::Sprite;
	Five_L = new sf::Sprite;
	Five_S = new sf::Sprite;
	Five_T = new sf::Sprite;
	Five_T_Peg = new sf::Sprite;
	Five_Z = new sf::Sprite;
	Five_Square_Peg = new sf::Sprite;
	Five_Cross_Long = new sf::Sprite;
	Five_C = new sf::Sprite;
	Five_Bat = new sf::Sprite;
	Five_Plus = new sf::Sprite;
	Five_Corner = new sf::Sprite;

	//init sprites for place menu
	if (!(placebtn->loadFromFile("Place.png")));
	if (!(endbtn->loadFromFile("EndTurn.png")));
	if (!(CW->loadFromFile("CW.png")));
	if (!(CCW->loadFromFile("CCW.png")));
	if (!(One_T->loadFromFile("One.png")));
	if (!(Two_T->loadFromFile("Two.png")));
	if (!(Three_T->loadFromFile("Three.png")));
	if (!(Three_Line_T->loadFromFile("Three_Line.png")));
	if (!(Four_Line_T->loadFromFile("Four_Line.png")));
	if (!(Four_Square_T->loadFromFile("Four_Square.png")));
	if (!(Four_L_T->loadFromFile("Four_L.png")));
	if (!(Four_T_T->loadFromFile("Four_T.png")));
	if (!(Four_Z_T->loadFromFile("Four_Z.png")));
	if (!(Five_Straight_T->loadFromFile("Five_Straight.png")));
	if (!(Five_L_T->loadFromFile("Five_L.png")));
	if (!(Five_S_T->loadFromFile("Five_S.png")));
	if (!(Five_T_T->loadFromFile("Five_T.png")));
	if (!(Five_T_Peg_T->loadFromFile("Five_T_Peg.png")));
	if (!(Five_Z_T->loadFromFile("Five_Z.png")));
	if (!(Five_Square_Peg_T->loadFromFile("Five_Square_peg.png")));
	if (!(Five_Cross_Long_T->loadFromFile("Five_Cross_Long.png")));
	if (!(Five_C_T->loadFromFile("Five_C.png")));
	if (!(Five_Bat_T->loadFromFile("Five_Bat.png")));
	if (!(Five_Plus_T->loadFromFile("Five_Plus.png")));
	if (!(Five_Corner_T->loadFromFile("Five_Corner.png")));

	EndTurn->setTexture(*endbtn);
	Place_Shape->setTexture(*placebtn);
	ROT_CW->setTexture(*CW);
	ROT_CCW->setTexture(*CCW);
	//One->setTexture(*One_T);
	spriteArray[0].setTexture(*One_T);
	//Two->setTexture(*Two_T);
	spriteArray[1].setTexture(*Two_T);
	//Three->setTexture(*Three_T);
	spriteArray[2].setTexture(*Three_T);
	//Three_Line->setTexture(*Three_Line_T);
	spriteArray[3].setTexture(*Three_Line_T);
	//Four_Line->setTexture(*Four_Line_T);
	spriteArray[4].setTexture(*Four_Line_T);
	//Four_Square->setTexture(*Four_Square_T);
	spriteArray[5].setTexture(*Four_Square_T);
	//Four_L->setTexture(*Four_L_T);
	spriteArray[6].setTexture(*Four_L_T);
	//Four_T->setTexture(*Four_T_T);
	spriteArray[7].setTexture(*Four_T_T);
	//Four_Z->setTexture(*Four_Z_T);
	spriteArray[8].setTexture(*Four_Z_T);
	//Five_Straight->setTexture(*Five_Straight_T);
	spriteArray[9].setTexture(*Five_Straight_T);
	//Five_L->setTexture(*Five_L_T);
	spriteArray[10].setTexture(*Five_L_T);
	//Five_S->setTexture(*Five_S_T);
	spriteArray[11].setTexture(*Five_S_T);
	//Five_T->setTexture(*Five_T_T);
	spriteArray[12].setTexture(*Five_T_T);
	//Five_T_Peg->setTexture(*Five_T_Peg_T);
	spriteArray[13].setTexture(*Five_T_Peg_T);
	//Five_Z->setTexture(*Five_Z_T);
	spriteArray[14].setTexture(*Five_Z_T);
	//Five_Square_Peg->setTexture(*Five_Square_Peg_T);
	spriteArray[15].setTexture(*Five_Square_Peg_T);
	//Five_Cross_Long->setTexture(*Five_Cross_Long_T);
	spriteArray[16].setTexture(*Five_Cross_Long_T);
	//Five_C->setTexture(*Five_C_T);
	spriteArray[17].setTexture(*Five_C_T);
	//Five_Bat->setTexture(*Five_Bat_T);
	spriteArray[18].setTexture(*Five_Bat_T);
	//Five_Plus->setTexture(*Five_Plus_T);
	spriteArray[19].setTexture(*Five_Plus_T);
	//Five_Corner->setTexture(*Five_Corner_T);
	spriteArray[20].setTexture(*Five_Corner_T);

	square = nullptr;

}

void Blokus::printGrid()
{
	//initial size
	int x = (Window_Width - 25 * 20) / 2;
	int y = 100;

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


void Blokus::placeShape(Player& input, shape currentpeice)
{
	bool flag = true;
	string x = " ", y = " ";
	string title;

	sf::String userInput_x, userInput_y;
	sf::Text UserText_x, UserText_y;


	//sets window title
	if (input.getColor() == Blue) {
		title = "Blue Shape Placer";
	} 
	else if (input.getColor() == Red) {
		title = "Red Shape Placer";
	} 
	else if (input.getColor() == Yellow) {
		title = "Yellow Shape Placer";
	}
	else if (input.getColor() == Green) {
		title = "Green Shape Placer";
	}
	
	sf::RenderWindow window(sf::VideoMode(500, 700), title);
	window.setPosition(sf::Vector2i(10, 50));

	//sets instructions
	sf::Text Title, Input_X, Input_Y;
	Title.setFont(*gameFont);
	Title.setFillColor(sf::Color::Black);
	Title.setString("Please Enter the X and Y coordinates for your shape");
	Title.setCharacterSize(18);
	Title.setPosition(sf::Vector2f((500 - Title.getGlobalBounds().width) / 2, 50));

	Input_X.setFont(*gameFont);
	Input_X.setFillColor(sf::Color::Black);
	Input_X.setString("Please Enter the X Coordinate:");
	Input_X.setCharacterSize(10);
	Input_X.setPosition(sf::Vector2f(20, 350));
	Input_X.setStyle(sf::Text::Underlined);
	
	Input_Y.setFont(*gameFont);
	Input_Y.setFillColor(sf::Color::Black);
	Input_Y.setString("Please Enter the Y Coordinate:");
	Input_Y.setCharacterSize(10);
	Input_Y.setPosition(sf::Vector2f(500-170, 350));
	Input_Y.setStyle(sf::Text::Underlined);

	Input_Y.setFont(*gameFont);
	Input_Y.setFillColor(sf::Color::Black);
	Input_Y.setString("Please Enter the Y Coordinate:");
	Input_Y.setCharacterSize(10);
	Input_Y.setPosition(sf::Vector2f(500 - 170, 350));
	Input_Y.setStyle(sf::Text::Underlined);

	UserText_x.setFont(*gameFont);
	UserText_x.setFillColor(sf::Color::Black);
	UserText_x.setCharacterSize(20);
	UserText_x.setPosition(sf::Vector2f(20, 400));

	UserText_y.setFont(*gameFont);
	UserText_y.setCharacterSize(20);
	UserText_y.setPosition(sf::Vector2f(500 - 170, 400));
	

	sf::RectangleShape field1, field2;

	field1.setSize(sf::Vector2f(150, 50));
	field2.setSize(sf::Vector2f(150, 50));

	field1.setFillColor(sf::Color::White);
	field2.setFillColor(sf::Color::White);

	field1.setPosition(sf::Vector2f(20, 400));
	field2.setPosition(sf::Vector2f(500 - 170, 400));

	ROT_CW->setPosition(sf::Vector2f(500-115, 200));
	ROT_CCW->setPosition(sf::Vector2f(40, 200));

	
	EndTurn->setPosition(sf::Vector2f((500 - EndTurn->getGlobalBounds().width) / 2, 650));

	while (window.isOpen() && flag) {

		sf::Event* event = new sf::Event;

		while (window.pollEvent(*event)) {

			UserText_y.setFillColor(sf::Color::Black);
			UserText_x.setFillColor(sf::Color::Black);

			if (event->type == sf::Event::Closed) {
				window.close();

			}

			UserText_x.setString(x);
			UserText_y.setString(y);

			//gets coordinates via text
			if (HighlighTextField(field1, window)) {
				
				UserText_x.setFillColor(sf::Color::White);

				if (event->type == sf::Event::TextEntered) {
					userInput_x += event->text.unicode;
					UserText_x.setString(userInput_x);
					x = userInput_x.toAnsiString();

					//allows user to delete things in text block
					if (event->text.unicode == '\b') {
						userInput_x = " ";
						x = userInput_x.toAnsiString();
					}
				}
			}
			else if (HighlighTextField(field2, window)) {

				UserText_y.setFillColor(sf::Color::White);

				if (event->type == sf::Event::TextEntered) {
					userInput_y += event->text.unicode;
					UserText_y.setString(userInput_x);
					y = userInput_y.toAnsiString();

					//allows user to delete in text block
					if (event->text.unicode == '\b') {
						userInput_y = " ";
						y = userInput_y.toAnsiString();
					}
				}
			}

			
			//rotate functions here
			rotation->setPosition(sf::Vector2f((500 - rotation->getGlobalBounds().width) / 2, 150));
			
			if (input.getShape(currentpeice).getOrientation() == 0) {
				rotation->setString("Current Orientation: North");
			}
			else if (input.getShape(currentpeice).getOrientation() == 1) {
				rotation->setString("Current Orientation: East");
			}
			else if (input.getShape(currentpeice).getOrientation() == 2) {
				rotation->setString("Current Orientation: South");
			}
			else if (input.getShape(currentpeice).getOrientation() == 3) {
				rotation->setString("Current Orientation: West");
			}

			if (highlightTexture(*ROT_CCW, window)) {
				if (event->type == sf::Event::MouseButtonPressed) {

					input.setShapeRotation(currentpeice, false);
				}

			}

			if (highlightTexture(*ROT_CW, window)) {
				if (event->type == sf::Event::MouseButtonPressed) {

					input.setShapeRotation(currentpeice, true);
				}

			}
			
			window.clear(sf::Color::Color(214, 214, 214, 255));

			//prevents some non integer inputs
			if (isNum(x) && isNum(y)) {

				//checks if peice works, if so places shape
				if (GameBoard->validate(stoi(x) +1, stoi(y)+1, input, currentpeice)) {

					Place_Shape->setPosition(sf::Vector2f((500 - Place_Shape->getGlobalBounds().width) / 2, 550));
					window.draw(*Place_Shape);

					if (highlightTexture(*Place_Shape, window)) {

						if (event->mouseButton.button == sf::Mouse::Left) {

							flag = false;

							//add peice validation
							GameBoard->placePiece(stoi(x) + 1, stoi(y) + 1, input, currentpeice);


						}
					}
				}
			}

			//allows end turn for user
			if (highlightTexture(*EndTurn, window)) {
				if (event->mouseButton.button == sf::Mouse::Left) {

					input.discardPiece(currentpeice); //discards selected peice
					flag = false;
				}

			}

			//displays text and graphics stuff
			window.draw(Title);
			window.draw(*rotation);
			window.draw(field1);
			window.draw(field2);
			window.draw(Input_X);
			window.draw(Input_Y);
			window.draw(UserText_x);
			window.draw(UserText_y);
			window.draw(*EndTurn);
			window.draw(*ROT_CCW);
			window.draw(*ROT_CW);
			
			window.display();
		}
	}

}

//returns 1 or 0: if user mouse is over game menu option, then it highlights that option and returns 1 else returns 0
bool Blokus::highlightTexture(sf::Sprite& input, sf::RenderWindow &window)
{

	if ((sf::Mouse::getPosition(window).x >= input.getPosition().x && sf::Mouse::getPosition(window).x <= (input.getGlobalBounds().width + input.getPosition().x))
		&& (sf::Mouse::getPosition(window).y >= input.getPosition().y && sf::Mouse::getPosition(window).y <= (input.getPosition().y + input.getGlobalBounds().height))) {

		input.setColor(sf::Color(51, 51, 51, 255));

		return 1;
	}
	else {
		input.setColor(sf::Color(255, 255, 255, 255));

		return 0;
	}

}

shape Blokus::drawPieces(Player& p, sf::Sprite spriteArr[21], sf::RenderWindow& window)
{
	for (int i = 0; i < 21; i++)
	{
		BlokusShape temp = p.getShape(i);
		//int tempArray[5][5] = piecesArray.getGeo(); <- fix me
		if (temp.getStatus())
		{
			spriteArr[i].setPosition(sf::Vector2f(5 + (spriteArray[i].getGlobalBounds().width * i) + 20, Window_Height- 100));
			if (highlightTexture(spriteArr[i], window)) {

				placeShape(*player1, p.getShape(i).getType());
					
			}

			GameWindow->draw(spriteArr[i]);

			//draw each piece
		}
		//print each piece for the player(scaled?)
	}
	
	return FourL;
}


//highlights text input boxes when moused over
bool Blokus::HighlighTextField(sf::RectangleShape &input, sf::RenderWindow &window)
{
	if ((sf::Mouse::getPosition(window).x >= input.getPosition().x && sf::Mouse::getPosition(window).x <= (input.getGlobalBounds().width + input.getPosition().x))
		&& (sf::Mouse::getPosition(window).y >= input.getPosition().y && sf::Mouse::getPosition(window).y <= (input.getPosition().y + input.getGlobalBounds().height))) {

		input.setFillColor(sf::Color(51, 51, 51, 255));

		return 1;
	}
	else {
		input.setFillColor(sf::Color::White);

		return 0;
	}
}

//test condition for user input
bool Blokus::isNum(string& input)
{
	bool result = true;

	for (int i = 0; i < input.length(); i++) {
		if (!isdigit(input.at(i))) {
			result = false;
		}
	}
	return result;
}

//TwoPlayer definitons here

TwoPlayer_Game::TwoPlayer_Game()
{
	
	while (GameWindow->isOpen()) {
	
		sf::Event* event = new sf::Event;

		while (GameWindow->pollEvent(*event)) {

			if (event->type == sf::Event::Closed) {
				GameWindow->close();

			}

			GameWindow->clear(sf::Color::Color(214, 214, 214, 255));

			printGrid();

			drawPieces(*player1, spriteArray, *GameWindow);

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
