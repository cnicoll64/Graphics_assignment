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
	EndTurn = new sf::Sprite;
	Place_Shape = new sf::Sprite;
	ROT_CW = new sf::Sprite;
	ROT_CCW = new sf::Sprite;

	//init sprites for place menu
	if (!(placebtn->loadFromFile("Place.png")));
	if (!(endbtn->loadFromFile("EndTurn.png")));
	if (!(CW->loadFromFile("CW.png")));
	if (!(CCW->loadFromFile("CCW.png")));


	EndTurn->setTexture(*endbtn);
	Place_Shape->setTexture(*placebtn);
	ROT_CW->setTexture(*CW);
	ROT_CCW->setTexture(*CCW);

	square = nullptr;

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
				}
			}
			else if (HighlighTextField(field2, window)) {

				UserText_y.setFillColor(sf::Color::White);

				if (event->type == sf::Event::TextEntered) {
					userInput_y += event->text.unicode;
					UserText_y.setString(userInput_x);
					y = userInput_y.toAnsiString();
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
