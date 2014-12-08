/* 
 * File:   CheckWinner.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on December 7, 2014, 8:26 PM
 */

#include <iostream>
#include "CheckWinner.h"

using namespace std;

void CheckWinner::getResult()
{
    cout<<"\nGAME OVER!" << endl;
    
    if(plPoints > enPoints)
    {
        cout<<"\nYOU WIN!!" << endl;
        cout<<"You sunk " << enPoints << " enemy ships" << endl;
        cout<<"The enemy only sunk " << plPoints << " of your ships" << endl;
    }
    if(plPoints < enPoints)
    {
        cout<<"\nYOU LOSE!!" << endl;
        cout<<"You sunk " << enPoints << " enemy ships" << endl;
        cout<<"The enemy only sunk " << plPoints << " of your ships" << endl;
    }  
}
