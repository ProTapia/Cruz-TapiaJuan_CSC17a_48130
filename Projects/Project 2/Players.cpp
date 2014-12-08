/* 
 * File:   Players.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on December 5, 2014, 2:48 PM
 */

#include <iostream>
#include <stdlib.h> 
#include "Players.h"

using namespace std;

//Request user input and stores in an array
char **Players::getPlayer()
{
    //Getting input form the Board object
    int rows = getRows();
    int columns = getColumns();
    int ships = getShips();
    
    //Resize pointer array
    playerBoard = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        playerBoard[i] = new char[columns];
    }
        
    int tempRow = 0;        //Local int for the row
    int tempColumn = 0;     //Local int for the column
    bool validLoc = true;   //Bool to check for valid input
    
    
    
    //Setting all the array spaces to ' '
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            playerBoard[i][j] = ' ';
        }
    }
    
    //Requesting locations for players ships
    cout << "\nPlace your "<< ships << " ships in the board" << endl;
    
    for(int i = 0; i < ships; i++)
    {
        do
        {
            cout << "\nShip " << i+1 << endl;
            cout << "Row: ";
            cin >> tempRow;
            while(tempRow <= 0 ||tempRow > rows)
            {
                cout << "\nInvalid input!" << endl;
                cout << "Row: ";
                cin >> tempRow;
            }
            cout << "Column: ";
            cin >> tempColumn;
            while(tempColumn <= 0 ||tempColumn > columns)
            {
                cout << "\nInvalid input!" << endl;
                cout << "Column: ";
                cin >> tempColumn;
            }
    
            //Checking if the position is valid
            if(playerBoard[tempRow-1][tempColumn-1] == 'O')
            {
                validLoc = false;
                cout << "\nYou already have a ship there!" << endl;
            }
            else
            {
                playerBoard[tempRow-1][tempColumn-1] = 'O';
            }
        }while(validLoc == false);
    }
  
    return playerBoard;
}

//Generates random input and stores in an array
char **Players::getEnemy()
{
    //Getting input form the Board object
    int rows = getRows();
    int columns = getColumns();
    int ships = getShips();
    
    //Resize pointer array
    enemyBoard = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        enemyBoard[i] = new char[columns];
    }
    
    //Setting all the array spaces to ' '
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            enemyBoard[i][j] = ' ';
        }
    }
    
    int tempRow = 0;        //Local int for the row
    int tempColumn = 0;     //Local int for the column
    bool validLoc = true;   //Bool to check for valid input
        
        
     //Enemy randomly slects its ships position
    for(int i = 0; i < ships; i++)
    {
        do
        {
            tempRow = (rand() % rows);
            tempColumn = (rand() % columns);
            
            if(enemyBoard[tempRow][tempColumn] == 'O')
            {
                validLoc = false;
            }
            else
            {
                enemyBoard[tempRow][tempColumn] = 'O';
            }
        }while(validLoc == false);
    }
    
    return enemyBoard;
}