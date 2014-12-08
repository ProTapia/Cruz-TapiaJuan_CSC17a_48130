/* 
 * File:   Players.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 5, 2014, 2:48 PM
 */

#ifndef PLAYERS_H
#define	PLAYERS_H

#include "Board.h"

class Players : public Board
{
    private:
        char **playerBoard;  //Array with all the player tokens
        char **enemyBoard;   //Array with all the enemy tokens
    public:
        Players(){}
        Players(int r, int c, int s):Board(r, c, s){}
        
        ~Players()
        {
            delete [] playerBoard;
            delete [] enemyBoard;
        }
        
        char **getPlayer();
        char **getEnemy();
};

#endif	/* PLAYERS_H */