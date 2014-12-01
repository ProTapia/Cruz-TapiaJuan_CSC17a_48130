/* 
 * File:   Date.cpp
 * Author: Juan Cruz-Tapia
 * 
 * Created on November 17, 2014, 7:35 PM
 */
//Libraries
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constructor to initialize values
Date::Date()
{
    month = 0;  //Declaring month to 0
    day = 0;    //Declaring day to 0
    year = 0;   //Declaring year to 0
}

// Mutators
void Date::setMonth(int m)
{
    if (m >= 1 && m <= 12)
        month = m;
    else
        throw InvalidMonth();
}
void Date::setDay(int d)
{
    if (d >= 1 && d <= 31)
        day = d;
    else
        throw InvalidDay();
}
void Date::setYear(int y) { year = y; }  

// Date in "mm/dd/yyyy" format
void Date::allNumbers()
{
    cout << month << "/" << day << "/" << year << endl;
}

// Date in "month day, year" format
void Date::monthFirst()
{
    //Declaring string array holding all the months
    string letMonth[12] = {"January", "February", "March", "April", "May", 
                           "June", "July", "August", "September", "October",
                           "November", "December"}; 
    
    //Printing output in corresponding format
    cout << letMonth[month-1] << " " << day << ", "<< year << endl;
    
    
}
        
// Date in "day month year" format 
void Date::dayFirst()
{
    //Declaring string array holding all the months
    string letMonth[12] = {"January", "February", "March", "April", "May", 
                           "June", "July", "August", "September", "October",
                           "November", "December"}; 
    
    //Printing output in corresponding format
    cout << day << " " << letMonth[month-1] << " " << year << endl;
}

