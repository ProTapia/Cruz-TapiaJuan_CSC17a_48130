/* 
 * File:   Board.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on December 5, 2014, 2:18 PM
 */

#include "Board.h"

Board::Board()
{
    rows = 0;
    columns = 0;
    ships = 0;
}
Board::Board(int r,int c,int s)
{
    rows = r;
    columns = c;
    
    //Exception validation
    if(s < (r*c))
    {
        ships = s;
    }
    else
        throw InvalidInput();
}
        
//Mutators
void Board::setRows(int r)
{
    rows = r;
}
void Board::setColumns(int c)
{
    columns = c;
}
void Board::setShips(int s)
{
    //Exception validation
    if( s < (rows * columns))
    {
        ships = s;
    }
    else
        throw InvalidInput();
}
        
//Accessors
int Board::getRows() const{ return rows;}
int Board::getColumns() const { return columns;}
int Board::getShips() const { return ships;}