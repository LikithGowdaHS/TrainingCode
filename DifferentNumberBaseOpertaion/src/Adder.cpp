#include "Adder.h"
#include <iostream>

using namespace std;
Adder<T>::Adder()
{
    //ctor
}


Adder::~Adder()
{
    //dtor
}


void Adder::ReadOperands()
{
    cout << "Enter the First Operand" << endl;
    cin >> OperandOne;
    cout << "Enter the Second Operand" << endl;
    cin >> OperandTwo;

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
