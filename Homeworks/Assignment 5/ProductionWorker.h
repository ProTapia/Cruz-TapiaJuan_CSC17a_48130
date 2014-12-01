/* 
 * File:   ProductionWorker.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 28, 2014, 11:21 AM
 */

#ifndef PRODUCTIONWORKER_H
#define	PRODUCTIONWORKER_H

//Libraries
#include "Employee.h"
#include <string>

using namespace std;

class ProductionWorker : public Employee 
{
    private:
        int empShift;       //Holds the employee shift
        float empPayRate;   //Holds the employee hourly pay rate
    public:
        //Default Constructor
        ProductionWorker() : Employee()
        { 
            empShift = 0;
            empPayRate = 0.0;
        }
        //Constructor with user inputs
        ProductionWorker(string n, int i, string h, int s, float p) : Employee(n, i, h)
        {
            empShift = s;
            empPayRate = p;
        }
        
        //Accessors
        int getShift() const { return empShift; }
        float getPayRate() const { return empPayRate; } 
};

#endif	/* PRODUCTIONWORKER_H */

