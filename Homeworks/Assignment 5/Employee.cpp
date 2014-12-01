/* 
 * File:   Employee.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on November 28, 2014, 11:20 AM
 */

#include "Employee.h"

//Default constructor
Employee::Employee()
{
    empName = " ";
    empId = 0;
    empHire = " ";
}

//Constructor with inputs
Employee::Employee(string name,int id,string hire)
{
    empName = name;
    empId = id;
    empHire = hire;
}
             
//Accessors
string Employee::getName() const { return empName;}
int Employee::getId() const { return empId;}
string Employee::getHire() const { return empHire;}