
#include "Scoreboard.h"

/*
	// Test will run in while looop for game
	// This will be put in main
	Scoreboard scoretest;
	Player test(Green);

	scoretest.Scoreboard_update(1, test);
	scoretest.Scoreboard_display();

*/


// Scoreboard constructor
Scoreboard::Scoreboard() 
{
	score_red = 0;
	score_green = 0;
	score_yellow = 0;
	score_blue = 0;
}


// Every round a player plays, 1pt is added (i.e. added_points = 0 or 1)
void Scoreboard::Scoreboard_update(int added_points, Player current) 
{
	// If it is the red player add points 
	if (current.getColor() == Red)
	{
		score_red = score_red + added_points; // Adds 1 point for each round played 

		if (score_red == 21) //If each round the player played, additional 15 points added
		{
			score_red = score_red + 15;
		}

		//// 21 points means the player played each round since 1pt added each round
		//if (current.getShape(current.) == 0 && score_red >= 21) //If last piece played is single, additional 15 points added
		//{
		//	score_red = score_red + 20;
		//}
	}

	// If it is the blue player add points 
	if (current.getColor() == Blue)
	{
		score_blue = score_blue + added_points; // Adds 1 point for each round played 

		if (score_blue == 21) //If each round the player played, additional 15 points added
		{
			score_blue = score_blue + 15;
		}

		//// 21 points means the player played each round since 1pt added each round
		//if (current.getShape == 0 && score_blue >= 21) //If last piece played is single, additional 15 points added
		//{
		//	score_blue = score_blue + 20;
		//}
	}

	// If it is the yellow player add points 
	if (current.getColor() == Yellow)
	{
		score_yellow = score_yellow + added_points; // Adds 1 point for each round played 

		if (score_yellow == 21) //If each round the player played, additional 15 points added
		{
			score_yellow = score_yellow + 15;
		}

		// 21 points means the player played each round since 1pt added each round
		//if (current.getShape == 0 && score_yellow >= 21) //If last piece played is single, additional 15 points added
		//{
		//	score_yellow = score_yellow + 20;
		//}
	}

	// If it is the green player add points 
	if (current.getColor() == Green)
	{
		score_green = score_green + added_points; // Adds 1 point for each round played 

		if (score_green == 21) //If each round the player played, additional 15 points added
		{
			score_green = score_green + 15;
		}

		// 21 points means the player played each round since 1pt added each round
		//if (current.getShape == 0 && score_green >= 21) //If last piece played is single, additional 15 points added
		//{
		//	score_green = score_green + 20;
		//}
	}


}

void Scoreboard::Scoreboard_display()
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

	//to change to string
	string messageR = to_string(score_red);
	string messageB = to_string(score_blue);
	string messageG = to_string(score_green);
	string messageY = to_string(score_yellow);

	// For red points
	sf::Text red("", gameFont);
	red.setString(messageR);
	red.setCharacterSize(35);
	red.setFillColor(sf::Color::Red);
	red.setPosition(350, 150);

	// For blue points
	sf::Text blue("", gameFont);
	blue.setString(messageB);
	blue.setCharacterSize(35);
	blue.setFillColor(sf::Color::Blue);
	blue.setPosition(350, 250);

	// For yellow points
	sf::Text yellow("", gameFont);
	yellow.setString(messageY);
	yellow.setCharacterSize(35);
	yellow.setFillColor(sf::Color::Yellow);
	yellow.setPosition(350, 350);

	// For green points
	sf::Text green("", gameFont);
	green.setString(messageG);
	green.setCharacterSize(35);
	green.setFillColor(sf::Color::Green);
	green.setPosition(350, 450);


	// For score board players
	text.setString("Blokus Scoreboad: ");
	text.setCharacterSize(35);
	text.setFillColor(sf::Color::Red);
	text.setPosition(50, 50);

	text1.setString("Red's Score: ");
	text1.setCharacterSize(35);
	text1.setFillColor(sf::Color::Black);
	text1.setPosition(50, 150);

	text2.setString("Blue's Score: ");
	text2.setCharacterSize(35);
	text2.setFillColor(sf::Color::Black);
	text2.setPosition(50, 250);

	text3.setString("Yellows's Score: ");
	text3.setCharacterSize(35);
	text3.setFillColor(sf::Color::Black);
	text3.setPosition(50, 350);

	text4.setString("Green's Score: ");
	text4.setCharacterSize(35);
	text4.setFillColor(sf::Color::Black);
	text4.setPosition(50, 450);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		window.draw(board);
		window.draw(text);
		window.draw(text1);
		window.draw(red);
		window.draw(text2);
		window.draw(blue);
		window.draw(text3);
		window.draw(yellow);
		window.draw(text4);
		window.draw(green);
		window.display();
	}


    

}


// Getter for the red player score
int Scoreboard::getScoreRed()
{
    return score_red;
}

// Getter for the yellow player score
int Scoreboard::getScoreYellow()
{
	return score_yellow;
}

// Getter for the green player score
int Scoreboard::getScoreGreen()
{
	return score_green;
}

// Getter for the blue player score
int Scoreboard::getScoreBlue()
{
	return score_blue;
}


