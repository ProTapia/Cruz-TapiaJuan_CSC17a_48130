//Juan Cruz-Tapia
//December 12th, 2014
//Final

//Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip> 
#include <fstream>

//Classes 
#include "Prob1Random.h"
#include "Prob2Sort.h"
#include "SavingsAccount.h"
#include "Employee.h"
#include "Prob3TableInherited.h"

using namespace std;

//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();   //Problem 1
void problem2();   //Problem 2
void problem3();   //Problem 3
void problem4();   //Problem 4
void problem5();   //Problem 5


//Begin Execution Here!!!
int main(int argv,char *argc[])
{
    //seeding srand
    srand (time(0));
    
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;   //Problem 1
        case 2:    problem2();break;   //Problem 2
        case 3:    problem3();break;   //Problem 3
        case 4:    problem4();break;   //Problem 4
        case 5:    problem5();break;   //Problem 5
        default:   def(inN);}
    }while(inN>=1&&inN<=5);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"\nMenu for Fial"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type anything else to exit \n"<<endl;}

int getN(){
        int inN;
        cin>>inN;
        return inN;}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Problem 1
void problem1()
{
    char n=5;
    char rndseq[]={16,34,57,79,144};
    int ntimes=100000;
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
    	cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

//Problem 2
void problem2()
{
    cout<<"The start of Problem 2, the sorting problem"<<endl << endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<16;j++)
	{
            cout<<zc[i*16+j];
	}
    }
    delete []zc;
    cout<<endl;
}

//Problem 3
void problem3()
{
    cout<<"Entering problem number 3"<<endl;
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
	{
            cout<<naugT[i*cols+j]<<" ";
	}
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
        for(int j=0;j<=cols;j++)
	{
            cout<<augT[i*(cols+1)+j]<<" ";
	}
        cout<<endl;
    }
}

//Problem 4
void problem4()
{
    SavingsAccount mine(-300);

    for(int i=1;i<=10;i++)
    {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    mine.toString();
    cout<<"Balance after 7 years given 10% interest = " 
        <<mine.Total((float)(0.10),7)<<endl;
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7) 
        <<" Recursive Calculation "<<endl;
}

//Problem 5
void problem5()
{
    Employee Mark("Mark","Boss",215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(20.0),
        Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(40.0),
   	Mark.setHoursWorked(25));
    Mark.toString();
    Mark.CalculatePay(Mark.setHourlyRate(60.0),
    	Mark.setHoursWorked(25));
    Mark.toString();

    Employee Mary("Mary","VP",50.0);
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
    	Mary.setHoursWorked(40));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
    	Mary.setHoursWorked(50));
    Mary.toString();
    Mary.CalculatePay(Mary.setHourlyRate(50.0),
    	Mary.setHoursWorked(60));
    Mary.toString();
}   

