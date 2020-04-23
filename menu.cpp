#include "menu.h"


menu::menu() {

	sf::RenderWindow window(sf::VideoMode(1366, 768), "Blokus", sf::Style::Default);
	window.setIcon(gimp_image.width, gimp_image.height, gimp_image.pixel_data);

	sf::Texture GameHeader;

	//loads Game image from project directory
	if (!GameHeader.loadFromFile("GameImage.png"))
	{
		// error...
	}

	GameHeader.setSmooth(true);
	GameHeader.setRepeated(false);

	sf::Sprite sprite;
	sprite.setTexture(GameHeader);

	sprite.scale(sf::Vector2f(0.5f, 0.5f));
	sprite.setPosition(sf::Vector2f(500.f, 50.f));



	

	
		
	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}
		window.clear(sf::Color::Color(214,214,214,255));


		window.draw(sprite);


		window.display();
	}

}