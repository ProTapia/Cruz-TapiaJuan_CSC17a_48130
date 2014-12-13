/* 
 * File:   Prob3Table.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 12, 2014, 6:06 PM
 */

#ifndef PROB3TABLE_H
#define	PROB3TABLE_H

#include <iostream>
#include <fstream>

using namespace std;

template<class T>
class Prob3Table 
{
        protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void);                     //Calculate all the sums
	public:
		Prob3Table(char *,int,int);               //Constructor then Destructor
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

template <class T>
Prob3Table<T>::Prob3Table(char *file, int r, int c)
{
    rows = r;
    cols = c;
    grandTotal = 0;
    
    int count = 0;
    table = new T[r*c];
    T temp;
    fstream infile(file, ios_base::in);
    while (infile >> temp)
    {
        table[count] = temp;
        count++;
    }
    infile.close();
    
    calcTable();
    
}

template <class T>
void Prob3Table<T>::calcTable()
{
    int countSum = 0;
    int countEl = 0;
    rowSum = new T[rows];
    while(countSum < rows)
    {
        rowSum[countSum] = table[countEl+0]+table[countEl+1]+table[countEl+2]+table[countEl+3]+table[countEl+4]+table[countEl+5];
        grandTotal += rowSum[countSum];
        countSum++;
        countEl += cols;
    }
    
    countSum = 0;
    countEl = 0;
    colSum = new T[cols];
    while(countSum < cols)
    {
        colSum[countSum] = table[countEl+0]+table[countEl+6]+table[countEl+12]+table[countEl+18]+table[countEl+24];
        countSum++;
        countEl++;;
    }
    
    /*cout << endl << endl;
    for(int i = 0; i< rows; i++)
    {
        cout << rowSum[i] << endl;
    }
    cout << endl << endl;
    
    for(int i = 0; i< cols; i++)
    {
        cout << colSum[i] << endl;
    }
    
    cout << endl << endl << grandTotal << endl << endl;*/
}
#endif	/* PROB3TABLE_H */

