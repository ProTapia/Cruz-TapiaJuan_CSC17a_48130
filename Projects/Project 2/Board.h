/* 
 * File:   Board.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 5, 2014, 2:18 PM
 */

#ifndef BOARD_H
#define	BOARD_H

class Board 
{
    private:
        int rows;     //The number of rows in the board
        int columns;  //The number of columns in the board
        int ships;    //The number of ships in the board
    public:
        //Constructor
        Board();              //Default constructor
        Board(int,int,int);   //Constructor using input
        
        //Exceptions
        class InvalidInput{};
        
        //Mutators
        void setRows(int);
        void setColumns(int);
        void setShips(int);
        
        //Accessors
        int getRows() const;
        int getColumns() const;
        int getShips() const;

};

#endif	/* BOARD_H */