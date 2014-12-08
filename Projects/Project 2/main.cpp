//Juan Cruz-Tapia
//December 9th, 2014
//Project 2

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h> 
#include <fstream>

//Classes
#include "Players.h"
#include "CheckWinner.h"

//Function prototypes

//Function that prints the the intro on the game
void intro();
//Function that prints the board
void printBoard(Players);
//Function that takes the input and prints the player board
void playerBoard(int, int, char**);
//Function that takes the input and prints the enemy board
void enemyBoard(int, int, char**);
//Function that checks for a winner
bool checkWin(int, int, int);

using namespace std;

int main(int argc, char** argv) 
{
    srand(time(0));
    
    int row = 0;            //Holds the user input for the rows
    int column = 0;         //Holds the user input for the columns
    int ship = 0;           //Holds user input for the number of ships
    char **player;          //Pointer array to hold the player board
    char **enemy;           //Pointer array to hold the enemy board
    int plRow = 0;          //Player rows
    int plColumn = 0;       //Player columns
    int enRow = 0;          //Enemy rows
    int enColumn = 0;       //Enemy columns
    int playerPoints = 0;   //Counter for every ship destroyed by the player
    int enemyPoints = 0;    //Counter for every ship destroyed by the enemy
    
    //Calling the intro function
    intro();

    //Getting input to make the board
    cout << "\nHow many rows do you want the board to be? ";
    cin >> row;
    cout << "How many columns do you want the board to be? ";
    cin >> column;
    cout << "How many ships do you want to use in the game? ";
    cin >> ship;
    
    //Initializing class object
    Players battle;
    
    //Declaring class object with exceptions
    try
    {
        battle.setRows(row);
        battle.setColumns(column);
        battle.setShips(ship);
    }
    catch(Board::InvalidInput)
    {
        cout << "\nInvalid Input!\nYou have too many ships!" << endl;
        cout << "How many ships do you want to use in the game? ";
        cin >> ship;
        battle.setShips(ship);
    }
    
    //Calls the function that prints the reference board
    printBoard(battle);
    
    //Initializing the blind board for the enemy to hide the real board
    char blindBoard[battle.getRows()][battle.getColumns()];  
    
    //Resizing the pointer array to hold the player board
    player = new char*[battle.getRows()];
    for(int i = 0; i < battle.getRows(); ++i)
    {
        player[i] = new char[battle.getColumns()];
    }
    //Calling the getPlayer function from the class Player and store the value
    //into the player pointer array
    player = battle.getPlayer();
    
    //Resizing the pointer array to hold the enemy board
    enemy = new char*[battle.getRows()];
    for(int i = 0; i < battle.getRows(); ++i)
    {
        enemy[i] = new char[battle.getColumns()];
    }
    //Calling the getPlayer function from the class Player and store the value
    //into the enemy pointer array
    enemy = battle.getEnemy();
    
    //Setting blindBoard array with empty spaces
    for(int i = 0; i < battle.getRows(); i++)
    {
        for(int j = 0; j < battle.getColumns(); j++)
        {
            blindBoard[i][j] = ' ';
        }
    }
    
    //Loop to make the moves
    while(playerPoints <= battle.getShips() || enemyPoints <= battle.getShips())
    {
        //playerBoard(battle.getRows(), battle.getColumns(), player);
        
        //Printing the player board
        cout << "\n   YOUR BOARD" << endl;
        for(int i = 0; i < battle.getColumns(); i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < battle.getRows(); i++)
        {
            cout << "  ";
            for(int j = 0; j < battle.getColumns(); j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < battle.getColumns(); j++)
            {
                cout << "|  " << player[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < battle.getColumns(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl << endl;
    
        //enemyBoard(battle.getRows(), battle.getColumns(), enemy);
        
        //Printing the enemy board
        cout << "   ENEMY BOARD" << endl;
        for(int i = 0; i < battle.getColumns(); i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < battle.getRows(); i++)
        {
            cout << "  ";
            for(int j = 0; j < battle.getColumns(); j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < battle.getColumns(); j++)
            {
                cout << "|  " << blindBoard[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < battle.getColumns(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
    
        //Checking for winner by calling the checkWin function
        if(checkWin(playerPoints, enemyPoints, battle.getShips()) == true)
        {
            break;
        }
    
        //Getting coordinates to attack
        cout << "\nWhat are the coordinates to launch an attack ?" << endl;
        cout << "Row: ";
        cin >> plRow;
        while(plRow <= 0 ||plRow > battle.getRows())
        {
            cout << "\nInvalid input!" << endl;
           cout << "Row: ";
            cin >> plRow;
        }
        cout << "Column: ";
        cin >> plColumn; 
        while(plColumn <= 0 || plColumn > battle.getColumns())
        {
            cout << "\nInvalid input!" << endl;
            cout << "Column: ";
            cin >> plColumn;
        }
        
       //Validating player moves
        if( enemy[plRow-1][plColumn-1] == ' ')
        {
            enemy[plRow-1][plColumn-1] = 'X';
            blindBoard[plRow-1][plColumn-1] = 'X';
            cout << "\nYou missed!";
        }
        else if( enemy[plRow-1][plColumn-1] == 'O')
        {
            enemy[plRow-1][plColumn-1] = '#';
            blindBoard[plRow-1][plColumn-1] = '#';
            cout << "\nYou hit one of the enemy ships!";
            playerPoints++;
        }
        else if( enemy[plRow-1][plColumn-1] == 'X' || 
                enemy[plRow-1][plColumn-1] == '#')
        {
            cout << "\nYou already attacked that spot! You wasted a turn...";
        }
        
        //Getting randomly generated input for the enemy moves
        enRow = (rand() % battle.getRows());
        enColumn = (rand() % battle.getColumns());
            
        //Validating enemy moves
        if( player[enRow][enColumn] == 'O')
        {
            player[enRow][enColumn] = '#';
            cout << "\nOh no! The enemy hit you!";
            enemyPoints++;
        }
        else if( player[enRow][enColumn] == ' ')
        {
            player[enRow][enColumn] = 'X';
        }
        else if(enemy[enRow][enColumn] == 'X' || 
                enemy[enRow][enColumn] == '#')
        {
            cout << "\nThe enemy missed";
        }
    }
    
    cout << "\nThanks for playing!" << endl;
   
    //Template 
    //CheckWinner result(playerPoints, enemyPoints);
    //result.getResult();
    
    //Delete player pointer arrays
    for (int i = 0; i < battle.getColumns(); i++)
    {
        delete[] player[i];
    }
    delete [] player;
    //Delete enemy pointer arrays
    for (int i = 0; i < battle.getColumns(); i++)
    {
        delete[] enemy[i];
    }
    delete [] enemy;
    
    return 0;
}

//Intro function reads and prints the intro from a binary file
void intro()
{
  string line;
  ifstream intro ("intro.bin");
  
  if (intro.is_open())
  {
    while ( getline (intro,line) )
    {
      cout << line << '\n';
    }
    intro.close();
  }
  else cout << "Unable to open file";
}

//Prints reference board so the player can place his ships
void printBoard(Players a)
{
    char intro = ' ';
    
    cout << "\n     THE BOARD" << endl;
    for(int i = 0; i < a.getColumns(); i++)
    {
        cout << "     " << i+1;
    }
    cout << endl;
    for(int i = 0; i < a.getRows(); i++)
    {
        cout << "  ";
        for(int j = 0; j < a.getColumns(); j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
        cout << i+1 << " ";
        for(int j = 0; j < a.getColumns(); j++)
        {
            cout << "|  " << intro << "  ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for(int j = 0; j < a.getColumns(); j++)
    {
        cout << "|-----";
    }
    cout << "|" << endl;
    
}

//Function that checks for a winner
bool checkWin(int player, int enemy, int ships)
{
    bool winner = false;
    
        if(player == ships)
        {
            cout << "\nCONGRATULATIONS YOU WON THE BATTLE!" << endl;
            winner = true;
        }
        if(enemy == ships)
        {
            cout << "\nGAME OVER\nThe enemy defeated you..." << endl;
            winner = true;
        }
    
    return winner;
}

/*void playerBoard(int rows, int columns, char **player)
{
    char **arr;
    
    arr = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        arr[i] = new char[columns];
    }
    
    arr = player;
    
    
    cout << "\n   YOUR BOARD" << endl;
    for(int i = 0; i < columns; i++)
    {
        cout << "     " << i+1;
    }
        cout << endl;
        for(int i = 0; i < rows; i++)
        {
            cout << "  ";
            for(int j = 0; j < columns; j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < columns; j++)
            {
                cout << "|  " << arr[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl << endl;
        
    for (int i = 0; i < columns; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
}*/

/*void enemyBoard(int rows, int columns, char **enemy)
{
    
    char **arr;
    
    arr = new char*[rows];
    for(int i = 0; i < rows; ++i)
    {
        arr[i] = new char[columns];
    }
    
    arr = enemy;
    
    cout << "   ENEMY BOARD" << endl;
        for(int i = 0; i < columns; i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < rows; i++)
        {
            cout << "  ";
            for(int j = 0; j < columns; j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < columns; j++)
            {
                cout << "|  " << arr[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
        
    for (int i = 0; i < columns; i++)
    {
        delete[] arr[i];
    }
    delete [] arr;
}*/

