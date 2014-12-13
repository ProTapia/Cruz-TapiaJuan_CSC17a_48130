/* 
 * File:   SavingsAccount.h
 * Author: Juan Cruz Tapia
 *
 * Created on December 10, 2014, 11:24 PM
 */

#ifndef SAVINGSACCOUNT_H
#define	SAVINGSACCOUNT_H

class SavingsAccount 
{
    private:
	float Withdraw(float);               //Utility Procedure
	float Deposit(float);                //Utility Procedure
	float Balance;                       //Property
	int   FreqWithDraw;                  //Property
	int   FreqDeposit;                   //Property
    public:
	SavingsAccount(float);               //Constructor
	void  Transaction(float);            //Procedure
        float Total(float=0,int=0);	     //Savings Procedure
	float TotalRecursive(float=0,int=0);
	void  toString();                    //Output Properties
};

#endif	/* SAVINGSACCOUNT_H */

