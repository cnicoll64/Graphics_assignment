#include "menu.h"

//initilizes Game menue, does not allow for user interface though
menu::menu() {

	//initializes window and sets window Icon
	window = new sf::RenderWindow (sf::VideoMode(Window_Width,Window_Height), "Blokus", sf::Style::Default);
	(*window).setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);

	//loads Game images from project directory- if reasources can't be loaded check if all files from assets folder are in project directory
	if (!GameHeader.loadFromFile("GameImage.png"));

	if (!GameRules.loadFromFile("GameRules.png"));

	if (!PVP.loadFromFile("PlayerVPlayer.png"));

	if (!Three.loadFromFile("ThreePlayer.png"));

	if (!Four.loadFromFile("FourPlayers.png"));

	if (!font.loadFromFile("Righteous-Regular.ttf"));

	if (!returned.loadFromFile("Return.png"));

	GameHeader.setSmooth(true);
	GameHeader.setRepeated(false);

	GameRules.setSmooth(true);
	GameRules.setRepeated(false);

	PVP.setSmooth(true);
	PVP.setRepeated(false);

	Three.setSmooth(true);
	Three.setRepeated(false);

	Four.setSmooth(true);
	Four.setRepeated(false);

	//set texture to sprite
	GameLogo.setTexture(GameHeader);
	Rules.setTexture(GameRules);
	One_One.setTexture(PVP);
	Three_s.setTexture(Three);
	Four_s.setTexture(Four);
	Title.setFont(font);
	body.setFont(font);
	returned_s.setTexture(returned);

	menu_background = new sf::RectangleShape(sf::Vector2f(Rules.getGlobalBounds().width + 20, (Rules.getGlobalBounds().height + 10) * 4 + 10));
	(*menu_background).setFillColor(sf::Color(31, 19, 0, 250));

	GameLogo.scale(sf::Vector2f(0.9f, 0.9f));

	//temp values for positioning Game Logo
	int x = (Window_Width - GameLogo.getGlobalBounds().width)/2;
	int y = -50;

	GameLogo.setPosition(sf::Vector2f(x,y));

	x = (Window_Width - menu_background->getGlobalBounds().width) / 2;

	y = 240;

	menu_background->setPosition(sf::Vector2f(x, y));

	x = (Window_Width - Rules.getGlobalBounds().width) / 2; //centers sprite
	y = 250;

	Rules.setPosition(sf::Vector2f(x, y));

	y += One_One.getGlobalBounds().height + 10;

	One_One.setPosition(sf::Vector2f(x, y));

	y += Three_s.getGlobalBounds().height + 10;

	Three_s.setPosition(sf::Vector2f(x, y));

	y += Four_s.getGlobalBounds().height + 10;

	Four_s.setPosition(sf::Vector2f(x, y));

	//draws window

	refresh();

}



//allows the user to choose what game option they want
int menu::chooseGame()
{

	//for now, later place in user input section
	while ((*window).isOpen()) {

		sf::Event *event = new sf::Event;

		while ((*window).pollEvent(*event)) {

			if (event->type == sf::Event::Closed) {
				(*window).close();
				return 0;
			}

			if (highlightTexture(One_One)) {

				if (event->mouseButton.button == sf::Mouse::Left && event->type == sf::Event::MouseButtonPressed) {
					window->clear();
					window->close();
					return 2;
				}
			}

			if (highlightTexture(Three_s)) {
				if (event->mouseButton.button == sf::Mouse::Left && event->type == sf::Event::MouseButtonPressed) {
					window->clear();
					window->close();
					return 3;
				}
			}

			if (highlightTexture(Four_s)) {
				if (event->mouseButton.button == sf::Mouse::Left && event->type == sf::Event::MouseButtonPressed) {
					window->clear();
					window->close();
					return 4;
				}
			}

			if (highlightTexture(Rules)) {

				if (event->mouseButton.button == sf::Mouse::Left && event->type == sf::Event::MouseButtonPressed) {

					//branch to rules menue
					printRules();

				}
			}


			refresh();
		}	
	}
}

//renders options menu
void menu::refresh()
{

	(*window).clear(sf::Color::Color(214, 214, 214, 255));

	(*window).draw(GameLogo);

	(*window).draw(*menu_background);

	(*window).draw(Rules);

	(*window).draw(One_One);

	(*window).draw(Three_s);

	(*window).draw(Four_s);

	(*window).display();
}

//displays window with rules for user on how to play blokus
void menu::printRules()
{
	bool flag = true;
	Title.setString("How to Play Blokus");
	Title.setCharacterSize(40);
	Title.setFillColor(sf::Color::Black);
	Title.setStyle(sf::Text::Underlined);

	Title.setPosition(sf::Vector2f( (Window_Width - Title.getGlobalBounds().width) / 2, 25));

	
	//string courtesy of www.ultraboardgames.com/blokus/game-rules.php
	string message = "\tBlokus is a multi player game that involes squares with different colors. The game ends when all players are blocked\nfrom laying down any more of their pieces.";

	message.append(" This also includes any players who may have placed all of their pieces on the board.\n");

	message.append("The first piece played by each player must cover a corner square. ");

	message.append("Each new piece must touch at least\n one other piece of the same color, but only at the corners. Pieces of the same color cannot be in contact along an edge.");

	message.append("\nScores are tallied, and the player with the highest score is the winner. ");

	message.append("Each player then counts the number of unit squares in \nhis / her remaining pieces(1 unit square = -1 point). ");

	message.append("A player earns + 15 points if all his / her pieces have been placed on the board \nplus 5 additional bonus points if the last piece placed on the board was the smallest piece(one square).");
	
	body.setString(message);

	body.setCharacterSize(20);
	body.setLineSpacing(1.5);
	body.setFillColor(sf::Color::Black);

	body.setPosition(sf::Vector2f((Window_Width - body.getGlobalBounds().width) / 2, 200));
	returned_s.setPosition(sf::Vector2f((Window_Width - returned_s.getGlobalBounds().width) / 2, 600));

	while ((*window).isOpen() && flag) {

		sf::Event event;
		

		while ((*window).pollEvent(event) && flag) {

			if (event.type == sf::Event::Closed) {
				(*window).close();
			}

			if (highlightTexture(returned_s)) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					flag = false;
					
				}
			}

			(*window).clear(sf::Color::Color(214, 214, 214, 255));

			window->draw(Title);
			window->draw(body);
			window->draw(returned_s);
			window->display();
		}
	}
}

//returns 1 or 0: if user mouse is over game menu option, then it highlights that option and returns 1 else returns 0
bool menu::highlightTexture(sf::Sprite& input)
{

	if ((sf::Mouse::getPosition(*window).x >= input.getPosition().x && sf::Mouse::getPosition(*window).x <= (input.getGlobalBounds().width + input.getPosition().x))
		&& (sf::Mouse::getPosition(*window).y >= input.getPosition().y && sf::Mouse::getPosition(*window).y <= (input.getPosition().y + input.getGlobalBounds().height))) {

		input.setColor(sf::Color(51, 51, 51, 255));

		return 1;
	}
	else {
		input.setColor(sf::Color(255, 255, 255, 255));

		return 0;
	}

}
