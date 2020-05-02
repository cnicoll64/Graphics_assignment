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
int main() {
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

}

	//////////////////////////////////////////////////////////////////////////////////////end menu code



	