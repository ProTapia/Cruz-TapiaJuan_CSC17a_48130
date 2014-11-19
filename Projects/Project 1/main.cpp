//Juan Cruz-Tapia
//October 26th, 2014
//Project 1

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h> 

using namespace std;

//Structure
struct Board
{
    int rows;     //The number of rows in the board
    int columns;  //The number of columns in the board
    int ships;    //The number of ships in the board
};

struct Players
{
    char playerBoard;  //Array with all the player tokens
    char enemyBoard;   //Array with all the enemy tokens
};

//Function prototypes

//Function that prints the intro message
void intro();
//Function that prints the initial board
void printBoard(Board);
//Function that gets the ships position in the board
Players **getInput(Board);
//Function where the main program takes place
void battle(Board, Players**);

int main(int argc, char** argv) 
{
    Board game;       //Structure that holds the board dimensions
    Players **boards; //Structure that composes the players boards
    
    //Calling the intro function
    intro();
    
    //Getting input to make the board
    cout << "\nHow many rows do you want the board to be? ";
    cin >> game.rows;
    cout << "How many columns do you want the board to be? ";
    cin >> game.columns;
    cout << "How many ships do you want to use in the game? ";
    cin >> game.ships;
    
    //Calls the function that prints the board
    printBoard(game);
    
   //Resizing array
    boards = new Players*[game.rows];
    for(int i = 0; i < game.rows; ++i)
        boards[i] = new Players[game.columns];
    
    //Function that gets the player data
    boards = getInput(game);
    
    //Calling the battle function
    battle(game, boards);
   
    
    cout << "\n\nThanks for playing my game" << endl;
    
    return 0;
}

//Function that prints the empty board
void printBoard(Board a)
{
    char test = ' ';
    
    cout << "\n   YOUR BOARD" << endl;
    for(int i = 0; i < a.columns; i++)
    {
        cout << "     " << i+1;
    }
    cout << endl;
    for(int i = 0; i < a.rows; i++)
    {
        cout << "  ";
        for(int j = 0; j < a.columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
        cout << i+1 << " ";
        for(int j = 0; j < a.columns; j++)
        {
            cout << "|  " << test << "  ";
        }
        cout << "|" << endl;
    }
    cout << "  ";
    for(int j = 0; j < a.columns; j++)
    {
        cout << "|-----";
    }
    cout << "|" << endl;
    
}
Players **getInput(Board b)
{
    Players **arr;     //Declaring dynamic array
    
    arr = new Players*[b.rows];
    for(int i = 0; i < b.rows; ++i)
        arr[i] = new Players[b.columns];
    
    int tempRow = 0;        //Local int for the row
    int tempColumn = 0;     //Local int for the column
    bool validLoc = true;   //Bool to check for valid input
    
    srand(time(0));
    
    //Setting all the array spaces to ' '
    for(int i = 0; i < b.rows; i++)
    {
        for(int j = 0; j < b.columns; j++)
        {
            arr[i][j].playerBoard = ' ';
            arr[i][j].enemyBoard = ' ';
        }
    }
    
    //Requesting locations for players ships
    cout << "\nPlace your "<< b.ships << " ships in the board" << endl;
    
    for(int i = 0; i < b.ships; i++)
    {
        do
        {
            cout << "\nShip " << i+1 << endl;
            cout << "Row: ";
            cin >> tempRow;
            while(tempRow <= 0 ||tempRow > b.rows)
            {
                cout << "\nInvalid input!" << endl;
                cout << "Row: ";
                cin >> tempRow;
            }
            cout << "Column: ";
            cin >> tempColumn;
            while(tempColumn <= 0 ||tempColumn > b.columns)
            {
                cout << "\nInvalid input!" << endl;
                cout << "Row: ";
                cin >> tempColumn;
            }
    
            //Checking if the position is valid
            if(arr[tempRow-1][tempColumn-1].playerBoard == 'O')
            {
                validLoc = false;
                cout << "\nYou already have a ship there!" << endl;
            }
            else
            {
                arr[tempRow-1][tempColumn-1].playerBoard = 'O';
            }
        }while(validLoc == false);
    }
    
    //Enemy randomly slects its ships position
    for(int i = 0; i < b.ships; i++)
    {
        do
        {
            tempRow = (rand() % b.rows);
            tempColumn = (rand() % b.columns);
            
            if(arr[tempRow][tempColumn].enemyBoard == 'O')
            {
                validLoc = false;
            }
            else
            {
                arr[tempRow][tempColumn].enemyBoard = 'O';
            }
        }while(validLoc == false);
    }
    
    //Returning array with ships position
    return arr;
}

//Function where all the calculations happen
void battle(Board g, Players **b)
{
    int row = 0;     //Player rows
    int column = 0;  //Player columns
    
    int enRow = 0;     //Enemy rows
    int enColumn = 0;  //Enemy columns
    
    int playerPoints = 0;  //Counter for every ship destroyed by the player
    int enemyPoints = 0;   //Counter for every ship destroyed by the enemy
    char blindBoard[g.rows][g.columns];  //Blind board for the enemy
    
     //Setting blindBoard array with empty spaces
    for(int i = 0; i < g.rows; i++)
    {
        for(int j = 0; j < g.columns; j++)
        {
            blindBoard[i][j] = ' ';
        }
    }
    
    //Loop to make the moves
    while(playerPoints <= g.ships || enemyPoints <= g.ships)
    {
        cout << "\n   YOUR BOARD" << endl;
        for(int i = 0; i < g.columns; i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < g.rows; i++)
        {
            cout << "  ";
            for(int j = 0; j < g.columns; j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < g.columns; j++)
            {
                cout << "|  " << b[i][j].playerBoard << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < g.columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl << endl;
    
        cout << "   ENEMY BOARD" << endl;
        for(int i = 0; i < g.columns; i++)
        {
            cout << "     " << i+1;
        }
        cout << endl;
        for(int i = 0; i < g.rows; i++)
        {
            cout << "  ";
            for(int j = 0; j < g.columns; j++)
            {
                cout << "|-----";
            }
            cout << "|" << endl;
            cout << i+1 << " ";
            for(int j = 0; j < g.columns; j++)
            {
                cout << "|  " << blindBoard[i][j] << "  ";
            }
            cout << "|" << endl;
        }
        cout << "  ";
        for(int j = 0; j < g.columns; j++)
        {
            cout << "|-----";
        }
        cout << "|" << endl;
    
        //Checking for winner
        if(playerPoints == g.ships)
        {
            cout << "\nCONGRATULATIONS YOU WON THE BATTLE!";
            break;
        }
       else if(enemyPoints == g.ships)
        {
            cout << "\nGAME OVER\nThe enemy defeated you...";
            break;
        }
    
        //Getting coordinates to attack
        cout << "\nWhat are the coordinates to launch an attack ?" << endl;
        cout << "Row: ";
        cin >> row;
        while(row <= 0 ||row > g.rows)
        {
            cout << "\nInvalid input!" << endl;
           cout << "Row: ";
            cin >> row;
        }
        cout << "Column: ";
        cin >> column; 
        
       //Validating player moves
       while(column <= 0 || column > g.columns)
        {
            cout << "\nInvalid input!" << endl;
            cout << "Column: ";
            cin >> column;
        }
    
        if(b[row-1][column-1].enemyBoard == ' ')
        {
            b[row-1][column-1].enemyBoard = 'X';
            blindBoard[row-1][column-1] = 'X';
            cout << "\nYou missed!";
        }
        else if(b[row-1][column-1].enemyBoard == 'O')
        {
            b[row-1][column-1].enemyBoard = '+';
            blindBoard[row-1][column-1] = '+';
            cout << "\nYou hit one of the enemy ships!";
            playerPoints++;
        }
        else if(b[row-1][column-1].enemyBoard == 'X' || 
                b[row-1][column-1].enemyBoard == '+')
        {
            cout << "\nYou already attacked that spot! You wasted a turn...";
        }
        
        //Validating enemy moves
        enRow = (rand() % g.rows);
        enColumn = (rand() % g.columns);
            
            
        if(b[enRow][enColumn].playerBoard == 'O')
        {
            b[enRow][enColumn].playerBoard = '+';
            cout << "\nOh no! The enemy hit you!";
            enemyPoints++;
        }
        else if(b[enRow][enColumn].playerBoard == ' ')
        {
            b[enRow][enColumn].playerBoard = 'X';
        }
        else if(b[enRow][enColumn].enemyBoard == 'X' || 
                b[enRow][enColumn].enemyBoard == '+')
        {
            cout << "\nThe enemy missed";
        }
    }
}
void intro()
{
    cout <<"\n\n                                      |__" << endl;
    cout <<"                                      |\\/" << endl;
    cout <<"                                      ---" << endl;
    cout <<"                                     / | [" << endl;
    cout <<"                              !      | |||" << endl;
    cout <<"                            _/|     _/|-++'" << endl;
    cout <<"                        +  +--|    |--|--|_ |-" << endl;
    cout <<"                     { /|__|  |/\\__|  |--- |||__/" << endl;
    cout <<"                    +---------------___[}-_===_.'____                 /\\" << endl;
    cout <<"                ____`-' ||___-{]_| _[}-  |     |_[___\\==--            \\/   _" << endl;
    cout <<" __..._____--==/___]_|__|_____________________________[___\\==--____,------' .7" << endl;
    cout <<"|                                                                     BB-61/" << endl;
    cout <<" \\_________________________________________________________________________|" << endl;
    cout << endl << endl;
    cout << right << setw(50) << "Welcome to BATTLESHIP!" << endl ;
    cout << endl << "This is a 2 player naval battle game. \nGuess where your opponent's ships are and destroy them\n"; 
    cout << "before your opponent destroys yours!" << endl;
}