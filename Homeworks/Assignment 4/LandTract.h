/* 
 * File:   LandTract.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 18, 2014, 10:44 PM
 */

#ifndef LANDTRACT_H
#define	LANDTRACT_H
#include "FeetInches.h"
#include <iomanip>
#include <iostream>

class LandTract {
    private:
        FeetInches length;   //Object that holds the length
        FeetInches width;    //Object that holds the width
        FeetInches area;     //Object that holds the area
    public:
        void getLength(int, int);   //Mutator to declare the object length
        void getWidth(int, int);    //Mutator to delcare the object width
        void printArea();           //Accessor to print the area
};

#endif	/* LANDTRACT_H */

