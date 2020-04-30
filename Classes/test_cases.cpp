
// Test ccases that could be implemented 

int Test = 0; // if Test == 1 program failed... if Test == 0 program passed test cases


// Test 1: If player chooses location outside 900 X 900 board size
if (player x_location > 900 || player y_location > 900)
{
	Test = 1;
    return;
}


// Test 2: To make sure code only runs when window is open
while (window.isOpen()) 
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }

}


// Test case 3: If font for game doesnt load from file
if (!gameFont.loadFromFile("Righteous-Regular.ttf"))
{
    Test = 1;
    return;
}


// Test case 4: If we are doing music? Talked about last meeting 
if (!gameMusic.loadFromFile("music"))
{
    Test = 1;
    return;
}


// Test case 5: 