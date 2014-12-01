/* 
 * File:   MilTime.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 28, 2014, 5:17 PM
 */

#ifndef MILTIME_H
#define	MILTIME_H

#include "Time.h"

class MilTime : public Time
{
    private:
        int milHours;
        int milSeconds;
    public:
        //Default constructor
        MilTime() : Time()
        {
            milHours = 0;
            milSeconds = 0;
        }
        
        //Constructor with user input
        MilTime(int h, int s)
        {
            setTime(h, s);
        }
        
        //Exceptions
        class BadHour{};
        class BadSeconds{};
        
        //Accessors
        int getMilHours() const { return milHours; }
        int getMilSeconds() const { return milSeconds; }
        
        //Function to calculate military time
        void setTime(int, int);
};

#endif	/* MILTIME_H */

