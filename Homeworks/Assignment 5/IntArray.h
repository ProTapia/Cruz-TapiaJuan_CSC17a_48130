/* 
 * File:   IntArray.h
 * Author: Juan Cruz Tapia
 *
 * Created on November 30, 2014, 5:23 PM
 */

#ifndef INTARRAY_H
#define	INTARRAY_H

class IntArray 
{
    private:
        int *aptr;                     // Pointer to the array
        int arraySize;                 // Holds the array size
    public:
        IntArray(int);                 // Constructor
        IntArray(const IntArray &);    // Copy constructor
        ~IntArray();                   // Destructor
   
        class subscriptError{};        // Exception
        
        int size() const               // Returns the array size
        { return arraySize; }

        int &operator[](const int &);  // Overloaded [] operator
};

#endif	/* INTARRAY_H */

