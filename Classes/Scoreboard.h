

#ifndef BLOKUS_SCOREBOARD_H
#define BLOKUS_SCOREBOARD_H


#include "std.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

using namespace std;


class Scoreboard  /*:public ### will probably need at some point to link together*/ {

public:

    Scoreboard();
    void Scoreboard_update(int scored_points);
    void Scoreboard_display(int scored_points);
    int getScore();


protected:

    int score;

};





#endif 