//Juan Cruz-Tapia
//October 24th, 2014
//Midterm

//Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Structure for problem 1
struct AccInfo
{
    int accNum;       //Five digit account number
    int initialBal;   //Balance at the beginning of the month
    int checks;       //Checks written by the customer during the month
    int deposits;     //Deposits credited to the customer during the month 
};
//Structure for problem 2
struct Employee
{
    string name;     //Name of the employee
    int hours;       //Hours worked by the employee
    float ratePay;   //Rate paid to the employee
};
//Structure for problem 3
struct statsResult
{
    float avg;    //Average in the array of numbers
    float median; //Median in the array of numbers
    int *mode;    //array containing the modes
    int nModes;   //number of modes in the array
    int maxFreq;  //max frequency of modes
};

//Problems Prototypes
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();

//Function prototype for problem 1
int digitCount(int);
//Functions prototype for problem 3
void sort(int[], int);
statsResult *avgMedMode(int*,int);
void printStat(statsResult);

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1()
{
    //Declaring variables
    AccInfo customer;           //Structure variable to get input
    customer.accNum = 0;        //Five digit account number
    customer.initialBal = 0;    //Balance at the beginning of the month
    customer.checks = 0;        //Checks written by the customer
    customer.deposits = 0;      //Deposits credited to the customer
    
    int checkNum = 0;           //Number of checks written by the customer
    int checkAmnt = 0;          //Amount for each check written by the customer
    int deposNum = 0;           //Number of deposits credited to the customer
    int deposAmnt = 0;          //Amount for each deposit made by the customer
    int total;                  //Balance of the customer after all input
    
    //Requesting user input
    cout << "\nEnter the 5 digit account number: ";
    cin >> customer.accNum;
    //Calling function to validate user input
    while(digitCount(customer.accNum) != 5)
    {
        cout << "Account number can only be 5 digit long!";
        cout << "\nEnter the 5 digit account number: ";
        cin >> customer.accNum;
    }
    cout << "Enter balance at the beginning of the month: ";
    cin >> customer.initialBal;
    cout << "Enter the amount of checks written this month: ";
    cin >> checkNum;
    for(int i = 0; i < checkNum; i++)
    {
        cout << "Enter the amount for check " << (i+1) << ": "; 
        cin >> checkAmnt;
        customer.checks += checkAmnt;
    }
    cout << "Enter the total amount of all deposits made this month: ";
    cin >> deposNum;
    for(int i = 0; i < deposNum; i++)
    {
        cout << "Enter the amount for deposit " << (i+1) << ": ";
        cin >> deposAmnt;
        customer.deposits += deposAmnt;
    }
    
    //Calculating final balance of the customer
    total = customer.initialBal + customer.deposits - customer.checks;
    
    //Printing balance
    cout << "\nThe ending balance for account " << customer.accNum << " is: ";
    if(total < 0)
    {
        cout << total - 12 << endl;
        cout << "A 12 fee has been applied for overdrawing!" << endl << endl;
    }
    else cout << total << endl << endl;;
}

void problem2()
{
    //Declaring variables
    int empNum = 0;        //Number of employees the user wants to input
    int empCount = 0;      //Counter that counts the number of employees input
   
    //Requesting a number of employees to size the arrays
    cout << "\nHow many employees you want to input? ";
    cin >> empNum;
    
    Employee info[empNum];     //Structure array for the employees
    float grossPay[empNum];    //Array for the gross pay of each employee
    
    //Loop to request input and calculate the gross pay
    for(int i = 0; i < empNum; i++)
    {
        cin.ignore();
        cout << "Enter the name of employee " << i+1 << " : ";
        getline(cin, info[i].name);
        cout << "Enter the hours worked for employee " << i+1 << " : ";
        cin >> info[i].hours;
        //Input validation to exit the loop
        if(info[i].hours < 0)
        {
            cout << "Stopping." << endl; 
            break;
        }
        cout << "Enter the rate paid to employee " << i+1 << " : ";
        cin >> info[i].ratePay;
        //Input validation to exit the loop
        if(info[i].ratePay < 0)
        {
            cout << "Stopping." << endl; 
            break;
        }
        
        //Calculating the gross pay
        if(info[i].hours <= 20) 
            grossPay[i] = info[i].ratePay;
        else if(info[i].hours > 20 && info[i].hours < 40) 
            grossPay[i] = info[i].ratePay * 2;
        else if(info[i].hours >= 40) 
            grossPay[i] = info[i].ratePay * 3;
        
        //Counting the number of employees before exit the loop
        empCount++;
    }
    cout << endl;
    
    //Printing the gross pay of each employee
    for(int i = 0; i < empCount; i++)
    {
        cout << info[i].name << " gross pay is: " << grossPay[i] << endl;
    }
    cout << endl;
}

void problem3()
{
    statsResult print;   //Structure variable
    int numArr = 0;      //Size of the array of numbers
    
    //Getting the size for the array
    cout << "\nHow many numbers do you wish to put in the array? ";
    cin >> numArr;
    
    int arr[numArr];   //Declaring the array
    cout << endl;
    //Getting the numbers from user
    for(int i = 0; i < numArr; i++)
    {
        cout << (i+1) << ".- Enter number: ";
        cin >> arr[i];
    }
    
    //Sort the array
    sort(arr, numArr);
    
    //Calculating the average, median and mode of the array
    print = *avgMedMode(arr, numArr);
    
    //Calling a function to print the results
    printStat(print);
    
    cout << endl;
}

void problem4()
{
    int inNumber = 0;     //0-7 four digit number the user wants to encrypt
    int num1 = 0;         //First digit in the number
    int num2 = 0;         //Second digit in the number
    int num3 = 0;         //Third digit in the number
    int num4 = 0;         //Fourth digit in the number
    int outNumber = 0;    //Encrypted number
    
    //Loop to only get valid inputs
    do
    {
        //Requesting the input
        cout << "\nEnter a 4 digit number between 0-7: ";
        cin >> inNumber;
            
        //Divides the number into individual numbers
        num1 = inNumber%10000/1000;
        num2 = inNumber%1000/100;
        num3 = inNumber%100/10; 
        num4 = inNumber%10; 
    }while(inNumber < 1000 || inNumber > 9999 || num1 < 0 || num1 > 7 || 
           num2 < 0 || num2 > 7 || num3 < 0 || num3 > 7 || num4 < 0 || 
           num4 > 7);
   
    //First encryption
    num1 = (num1 +3) % 8; 
    num2 = (num2 +3) % 8; 
    num3 = (num3 +3) % 8; 
    num4 = (num4 +3) % 8; 
    
    //Second encryption
    outNumber = (num2 * 1000) + (num1 * 100) + (num4 * 10) + num3;
   
    //Printing the encrypted number
    cout << "\nThe encrypted number is: " << outNumber << endl << endl;
}

void problem5()
{
    //Printing my results
    cout << "\nA byte variable would only be able to calculate up to 3!";
    cout << endl;
    cout << "\nThe largest factorial a short can hold is 7";
    cout << "\nThe largest factorial a unsigned short can hold is 8";
    cout << "\nThe largest factorial a signed short can hold is 7";
    cout << endl;
    cout << "\nThe largest factorial a int can hold is 12";
    cout << "\nThe largest factorial a unsigned int can hold is 12";
    cout << "\nThe largest factorial a signed int can hold is 12";
    cout << endl;
    cout << "\nThe largest factorial a long can hold is 20";
    cout << "\nThe largest factorial a unsigned long can hold is 20";
    cout << "\nThe largest factorial a signed long can hold is 20";
    cout << endl;
    cout << "\nThe largest factorial a float can hold is 34";
    cout << endl;
    cout << "\nThe largest factorial a double can hold is 170";
    cout << "\nThe largest factorial a long double can hold is 1754(?)";
    cout << endl << endl;
}

void problem6()
{
    //Printing my results
    cout << "\nDecimal: 2.125";
    cout << "\nBinary: 10.001";
    cout << "\nOctal: 2.1";
    cout << "\nHex: 2.2";
    cout << endl;
    cout << "\nDecimal: 0.06640625";
    cout << "\nBinary: 0.00010001";
    cout << "\nOctal: 0.042";
    cout << "\nHex: 0.11";
    cout << endl;
    cout << "\nFloat: 46666601";
    cout << "\nDecimal: 1181115905";
    cout << endl;
    cout << "\nFloat: 46666602";
    cout << "\nDecimal: 1181115906";
    cout << endl;
    cout << "\nFloat: B9999AFE";
    cout << "\nDecimal: 3113851646";
    cout << endl << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

//Function for problem 1
//Function to count the digits inside the integer 
int digitCount(int a)
{
    //Declaring variables
    int count = 0;  //Number counter
    
    //Loop to count digits
    while(a > 0)
    {
        a /= 10; 
        count++;
    }
    
    return count;
}
//Function for problem 3
//Function that calculates the average, media and mode of an array of numbers
statsResult *avgMedMode(int *array, int size)
{
    //Temporary structure to get the average, media and mode
    statsResult *temp;
    
    temp = new statsResult;
    
    //Getting the average
    float sum = 0; //Local variable for the sum of all numbers
    for (int i = 0; i < size; ++i)
    {
    	sum += array[i];
    }
    temp->avg = sum/size;
    
    //Getting the media
    float media = 0;   //Local variable for the media
    if(size % 2 == 0)
    {
	media = (array[size / 2] + array[(size / 2) - 1]) / 2.0;
	temp->median = media;
    }
    else
    {
	media = array[(size + 1) / 2 - 1];
	temp->median = media;
    }
    
    //Getting the mode
    int *arr;              // Temporary dynamic array
    int numberModes = 0;   // Accumulator for the modes
    int maxFreq = 0;       // Accumulator for the frequency
    int mode = 0;          // Temporary storage of a mode

    arr = new int[numberModes];

    // First loop to calculate the maximum frequency of numbers
    for(int i = 0; i < size; i++)
    {
	int freq = 1;  // Temporary frequency storage
	while(array[i] == array[i + 1])
	{
            mode = array[i];
            freq++;
            i++;

            if(freq > maxFreq)
            {
		maxFreq = freq;
            }
	}
    }
    // Second loop to get the modes
    for(int i = 0; i < size; i++)
    {
	int freq = 1;

	while(array[i] == array[i + 1])
	{
            mode = array[i];
            freq++;
            i++;
        }
	if(freq == maxFreq)
	{
            numberModes++;

            arr[numberModes-1] = mode;
	}
    }
    //Storing the information into the structure variable
    temp->mode = arr;
    temp->maxFreq = maxFreq;
    temp->nModes = numberModes;
    
    //Clearing the temporary memory
    delete [] arr;
    //Return the data
    return temp;
}
//Function that prints the results calculated in the *avgMedMode function
void printStat(statsResult a)
{
    cout << "\nThe average in the array is: " << a.avg << endl;
    cout << "The median in the array is: " << a.median << endl;
    cout << "The modes in the array are: ";
    for(int i = 0; i < a.nModes; i++) cout << a.mode[i] << " "; 
    cout << "\nThe number of modes in the array is: " << a.nModes << endl;
    cout << "The max frequency of modes in the array is: " << a.maxFreq 
         << endl;
}
//Function that sorts the array the user input
void sort(int array[], int size) 
{ 
    bool swap;  
    int temp; 

    do 
    { 
	swap = false; 
        for (int count = 0; count < (size - 1); count++) 
        { 
            if (array[count] > array[count + 1]) 
            { 
		temp = array[count]; 
                array[count] = array[count + 1]; 
                array[count + 1] = temp; 
                swap = true; 
            } 
        } 
    } while (swap);
}
