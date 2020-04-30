
#include "Scoreboard.h"

// Scoreboard constructor
Scoreboard::Scoreboard() /*:public player?*/
{
    score = 0;
}


// Every round a player plays, 1pt is added (i.e. added_points = 0 or 1)
void Scoreboard::Scoreboard_update(int added_points) 
{
    int total_played_blocks = 1;  //Will need to track amount of blocks played to score correctly this is for test

    score = score + added_points;

    if (total_played_blocks == 21) //If each round the player played, additional 15 points added
    {
        score = score + 15;
    }

}

void Scoreboard::Scoreboard_display(int scored_points)
{
	int score = 14;

	sf::RenderWindow window(sf::VideoMode(500, 700), "Blokus Scoreboard");
	window.setPosition(sf::Vector2i(10, 50));

	//Create Board
	sf::RectangleShape board(sf::Vector2f(400, 600));
	board.setFillColor(sf::Color::White);
	board.setOutlineColor(sf::Color::Red);
	board.setOutlineThickness(10);
	board.setPosition(25, 25);
	////Create Font
	sf::Font gameFont;
	gameFont.loadFromFile("Righteous-Regular.ttf");
	//Create Title
	sf::Text text("", gameFont);
	sf::Text text1("", gameFont);
	sf::Text text2("", gameFont);
	sf::Text text3("", gameFont);
	sf::Text text4("", gameFont);

	text.setString("Blokus Scoreboad: ");
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::Red);
	text.setPosition(50, 50);

	text1.setString("Player 1's Score: ");
	text1.setCharacterSize(35);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition(50, 150);

	text2.setString("Player 2's Score: ");
	text2.setCharacterSize(35);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(50, 250);

	text3.setString("Player 3's Score: ");
	text3.setCharacterSize(35);
	text3.setFillColor(sf::Color::Black);
	text3.setPosition(50, 350);

	text4.setString("Player 4's Score: ");
	text4.setCharacterSize(35);
	text4.setFillColor(sf::Color::Black);
	text4.setPosition(50, 450);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.draw(board);
		window.draw(text);
		window.draw(text1);
		window.draw(text2);
		window.draw(text3);
		window.draw(text4);
		window.display();

	}


    

}


// Getter for the scoreboard
int Scoreboard::getScore()
{

    return score;

}



/*
    sf::RectangleShape Single(sf::Vector2f(50, 50));
    Single.setFillColor(sf::Color::Green);
    Single.setOutlineColor(sf::Color::Black);
    Single.setOutlineThickness(10);
    Single.setPosition(50, 100);
*/
