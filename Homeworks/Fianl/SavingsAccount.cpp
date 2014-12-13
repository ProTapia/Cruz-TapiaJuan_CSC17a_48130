/* 
 * File:   SavingsAccount.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on December 10, 2014, 11:24 PM
 */

#include <iostream>

#include "SavingsAccount.h"

using namespace std;

SavingsAccount::SavingsAccount(float b)
{
    if(b < 0) 
    { 
        cout << "\nWithDraw not Allowed" << endl;
        Balance = 0;
    }
    else 
    { 
        Balance = b;
    }
    
    FreqWithDraw = 0;
    FreqDeposit = 0;
}

void  SavingsAccount::Transaction(float t)
{
    if(t > 0)
    {
        Balance += t;
        FreqDeposit++;
    }
    else if(t < 0)
    {
        if(t < Balance * -1)
        {
            cout << "WithDraw not Allowed" << endl;
        }
        else
        {
            Balance += t;
            FreqWithDraw++;
        }
    }
}

float SavingsAccount::Total(float savint,int time)
{
    float total = Balance;
    
    for(int i=0; i < time; i++)
    {
        total = total*(1+savint);
    }
    
    return total;
}

float SavingsAccount::TotalRecursive(float savint,int time)
{
    float total = Balance;
    float interest = 0.0;
    
    for(int i=0; i < time; i++)
    {
        interest = total * savint;
        total += interest;
    }
    
    return total; 
}

void  SavingsAccount::toString()
{
    cout << "\nBalance = " << Balance << endl;
    cout << "WithDraws = " << FreqWithDraw << endl;
    cout << "Deposits = " << FreqDeposit << endl;
}