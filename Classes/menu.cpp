#include "menu.h"

//initilizes Game menue, does not allow for user interface though
menu::menu() {

	//initializes window and sets window Icon
	window = new sf::RenderWindow (sf::VideoMode(Window_Width,Window_Height), "Blokus", sf::Style::Default);
	(*window).setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);

	//loads Game images from project directory
	if (!GameHeader.loadFromFile("GameImage.png"));

	if (!GameRules.loadFromFile("GameRules.png"));

	if (!PVP.loadFromFile("PlayerVPlayer.png"));

	if (!Three.loadFromFile("ThreePlayer.png"));

	if (!Four.loadFromFile("FourPlayers.png"));

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

		sf::Event event;

		while ((*window).pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				(*window).close();
			}

			if (highlightTexture(Rules)) {
				
				if (event.mouseButton.button == sf::Mouse::Left){
					
					//branch to rules menue

				}
			}

			if (highlightTexture(One_One)) {

				if (event.mouseButton.button == sf::Mouse::Left) {
					window->clear();
					window->close();
					return 2;
				}
			}

			if (highlightTexture(Three_s)) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					window->clear();
					window->close();
					return 3;
				}
			}

			if (highlightTexture(Four_s)) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					window->clear();
					window->close();
					return 4;
				}
			}


			refresh();
		}

		
		
	}
}

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

void menu::printRules()
{
}

//returns 1 or 0: if user mouse is over game menu option, then it highlights that option and returns 1 else returns 0
bool menu::highlightTexture(sf::Sprite& input)
{

	if ((sf::Mouse::getPosition(*window).x >= input.getPosition().x && sf::Mouse::getPosition(*window).x <= (input.getGlobalBounds().width + input.getPosition().x))
		&& (sf::Mouse::getPosition(*window).y >= input.getPosition().y && sf::Mouse::getPosition(*window).y <= (input.getPosition().y + input.getGlobalBounds().height))) {

		input.setColor(sf::Color(255, 255, 255, 200));

		return 1;
	}
	else {
		input.setColor(sf::Color(255, 255, 255, 255));

		return 0;
	}

}
