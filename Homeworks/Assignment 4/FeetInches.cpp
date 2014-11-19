/* 
 * File:   FeetInches.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on November 18, 2014, 8:17 PM
 */

#include <cstdlib> // Needed for abs()  
#include "FeetInches.h"

//Mutator function to better format feet and inches
void FeetInches::simplify() 
{ 
    if (inches >= 12) 
    { 
        feet += (inches / 12); 
        inches = inches % 12; 
    } 
    else if (inches < 0) 
    { 
        feet -= ((abs(inches) / 12) + 1); 
        inches = 12 - (abs(inches) % 12); 
    } 
}

//Overload multiplication operator
FeetInches FeetInches::operator * (const FeetInches &right) 
{ 
    FeetInches temp; 

    temp.inches = inches * right.inches; 
    temp.feet = feet * right.feet; 
    temp.simplify(); 
    return temp; 
}

//Overload >= operator
bool FeetInches::operator >= (const FeetInches &right)
{
    bool status;
    
    if(feet == right.feet && inches == right.inches)
        status = true;
    else if (feet > right.feet)
        status = true;
    else if (feet == right.feet && inches > right.inches)
        status = true;
    else
        status = false;
    
    return status;
}

//Overload <= operator
bool FeetInches::operator <=(const FeetInches &right)
{
    bool status;

    if(feet == right.feet && inches == right.inches)
        status = true;
    else if (feet < right.feet)
        status = true;
    else if (feet == right.feet && inches < right.inches)
        status = true;
    else
        status = false;

    return status;
}

//Overload != operator
bool FeetInches::operator != (const FeetInches &right)
{
    bool status;

    if (feet != right.feet && inches != right.inches)
        status = true;
    else
        status = false;
 
    return status;
}
/*
FeetInches FeetInches::operator + (const FeetInches &right) 
{ 
    FeetInches temp; 

    temp.inches = inches + right.inches; 
    temp.feet = feet + right.feet; 
    temp.simplify(); 
    return temp; 
} 

//Overload binary operator
FeetInches FeetInches::operator - (const FeetInches &right) 
{ 
    FeetInches temp; 

    temp.inches = inches - right.inches; 
    temp.feet = feet - right.feet; 
    temp.simplify(); 
    return temp; 
} 
 */