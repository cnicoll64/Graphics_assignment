

#ifndef BLOKUS_SCOREBOARD_H
#define BLOKUS_SCOREBOARD_H


#include "std.h"
#include "std.h"
#include "Player.h"

using namespace std;


class Scoreboard  /*:public ### will probably need at some point to link together*/ {

public:

    Scoreboard();
    void Scoreboard_update(int scored_points, Player);
    void Scoreboard_display();
    int getScoreRed();
    int getScoreBlue();
    int getScoreGreen();
    int getScoreYellow();


protected:

    int score_red;
    int score_green;
    int score_yellow;
    int score_blue;

};





#endif 