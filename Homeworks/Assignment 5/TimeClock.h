/* 
 * File:   TimeClock.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 28, 2014, 7:01 PM
 */

#ifndef TIMECLOCK_H
#define	TIMECLOCK_H

#include "MilTime.h"

class TimeClock : public MilTime
{
    public:
        //Constructor
        TimeClock(int start, int end)
        {
            calcTimeElapsed(start, end);
        }
        
        //Function to calculate the time elapsed
        void calcTimeElapsed(int, int);
};

#endif	/* TIMECLOCK_H */

