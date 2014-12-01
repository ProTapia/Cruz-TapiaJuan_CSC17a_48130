/* 
 * File:   ShiftSupervisor.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 28, 2014, 1:07 PM
 */

#ifndef SHIFTSUPERVISOR_H
#define	SHIFTSUPERVISOR_H

//Libraries
#include "Employee.h"
#include <string>

using namespace std;

class ShiftSupervisor : public Employee
{
    private:
        float empSalary;   //Holds the employee annual salary
        float empBonus;    //Holds the employee bonus for the year
    public:
        //Default Constructor
        ShiftSupervisor() : Employee()
        { 
            empSalary = 0.0;
            empBonus = 0.0;
        }
        //Constructor with user inputs
        ShiftSupervisor(string n, int i, string h, float s, float b) : Employee(n, i, h)
        {
            empSalary = s;
            empBonus = b;
        }
        
        //Accessors
        float getSalary() const { return empSalary; }
        float getBonus() const { return empBonus; }
};

#endif	/* SHIFTSUPERVISOR_H */

