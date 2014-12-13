/* 
 * File:   Prob3TableInherited.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 12, 2014, 6:07 PM
 */

#ifndef PROB3TABLEINHERITED_H
#define	PROB3TABLEINHERITED_H

#include <iostream>
#include <fstream>
#include "Prob3Table.h"

using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
        protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *,int,int);          //Constructor
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

template <class T>
Prob3TableInherited<T>::Prob3TableInherited(char *file, int r, int c) :
                        Prob3Table<T>(file, r, c)
{
    const T *tempTable = this->getTable();
    const T *tempRowSum = this->getRowSum();
    const T *tempColSum = this->getColSum();
    T tempTotal = this->getGrandTotal(); 
    int rowCount = c;
 
    augTable = new T[(r+1)*(c+1)];
    for(int i = 0; i < r; i++)
    {
	for(int j = 0;j < c; j++)
	{
            augTable[i*(c+1)+j] = tempTable[i*c+j];
	}
	augTable[rowCount+i] = tempRowSum[i];
        rowCount += c;
    }
    for(int i = 0; i < c; i++)
    {
        augTable[35+i] = tempColSum[i];
    }
    augTable[41] = tempTotal;
}

#endif	/* PROB3TABLEINHERITED_H */

