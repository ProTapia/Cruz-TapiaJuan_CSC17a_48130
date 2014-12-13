/* 
 * File:   Prob1Random.cpp
 * Author: Juan Cruz Tapia
 * 
 * Created on December 10, 2014, 9:38 AM
 */

#include <cstdlib>

#include "Prob1Random.h"

using namespace std;
//Constructor
Prob1Random::Prob1Random(const char n,const char *s)
{
    nset = n;
    
    int size = (int)nset; 
    
    set = new char[size];
    for(int i = 0; i<size; i++)
    {
        set[i] = s[i];
    }
    freq = new int[size];
    for(int i = 0; i<size; i++)
    {
        freq[i]=0;
    }
    numRand = 0;
}

Prob1Random::~Prob1Random(void)
{
    delete [] set;
    delete [] freq;
}

//Returns a random number from the set
char Prob1Random::randFromSet(void)
{
    int size = (int)nset; 
    int r = (rand() % size);
    
    freq[r] = freq[r]+1;
    numRand = numRand+1;
    
    return set[r];
}

//Returns the frequency histogram
int *Prob1Random::getFreq(void) const
{
    return freq;
}

//Returns the set used
char *Prob1Random::getSet(void) const
{
    return set;
}

//Gets the number of times randFromSet has been called
int Prob1Random::getNumRand(void) const
{
    return numRand;
}