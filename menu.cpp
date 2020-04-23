#include "menu.h"

menu::menu() {
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Blokus");
		
	while (window.isOpen()) {

		sf::Event event;

		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				window.close();
			}

		}

		window.clear(sf::Color::Color(214,214,214,255));

		window.display();
	}

}