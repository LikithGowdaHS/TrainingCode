#include "OctaAdder.h"
#include <iostream>
#include <cmath>
#include <stdlib.h>

using namespace std;

OctaAdder::OctaAdder()
{
    OctaOperand1 = 0;
    OctaOperand2 = 0;
    //ctor
}

OctaAdder::OctaAdder(int op1, int op2)
{
    OctaOperand1 = op1;
    OctaOperand2 = op2;

    cout << "Enter 1--> Add the numbers \t 2--> Subtract the numbers" << endl;
    int choice;
    cin >> choice;

    switch(choice)
    {
        case 1: add();
                break;
        case 2: sub();
                break;
    }
}

OctaAdder::~OctaAdder()
{
    //dtor
}

void OctaAdder::add()
{
    int numberone = octal_decimal(OctaOperand1);
    int numberTwo = octal_decimal(OctaOperand2);

    int Result = numberone + numberTwo;

    Result = decimal_octal(Result);

    cout << Result;

}

int OctaAdder::decimal_octal(int n) /* Function to convert decimal to octal */
{
    int rem, i=1, octal=0;
    while (n!=0)
    {
        rem=n%8;
        n/=8;
        octal+=rem*i;
        i*=10;
    }
    return octal;
}

int OctaAdder::octal_decimal(int n) /* Function to convert octal to decimal */
{
    int decimal=0, i=0, rem;
    while (n!=0)
    {
        rem = n%10;
        n/=10;
        decimal += rem*pow(8,i);
        ++i;
    }
    return decimal;
}

void OctaAdder::sub()
{
    int numberone = octal_decimal(OctaOperand1);
    int numberTwo = octal_decimal(OctaOperand2);

    int Result = numberone - numberTwo;

    Result = decimal_octal(Result);

    cout << Result;
}

void OctaAdder::ReadOperands()
{
    cout << "Enter the First Operand" << endl;
    cin >> oct >> OctaOperand1;
    cout << "Enter the Second Operand" << endl;
    cin >> oct >> OctaOperand2;
}
