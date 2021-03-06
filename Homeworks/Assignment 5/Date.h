/* 
 * File:   Date.h
 * Author: Juan Cruz-Tapia
 *
 * Created on November 17, 2014, 7:25 PM
 */

#ifndef DATE_H
#define	DATE_H

class Date
{
    private:
        int month;   // Holds month 
        int day;     // Holds day
        int year;    // Holds year
    public:
        Date();              // Constructor to initialize values
        
        //Exceptions
        class InvalidDay{};     //Exception for invalid day input
        class InvalidMonth{};   //Exception for invalid month input
            
        //Mutators
        void setMonth(int); //Sets the month
        void setDay(int);   //Sets the day
        void setYear(int);  //Sets the year
        
        //Accessors
        void allNumbers();   // Date in "mm/dd/yyyy" format
        void monthFirst();   // Date in "month day, year" format
        void dayFirst();     // Date in "day month year" format 
        
};

#endif	/* DATE_H */

