#include "BinayAdder.h"
#include <iostream>
#include <bitset>
#include <limits>

using namespace std;

BinayAdder::BinayAdder()
{
    BinaryOperand1 = "0";
    BinaryOperand2 = "0";

    ReadOperands();

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

    //ctor
}

BinayAdder::~BinayAdder()
{
    //dtor
}

int BinayAdder::MakeEqualLenghts()
{
    int OperandOneLength = BinaryOperand1.length();
    int OperandTwoLength = BinaryOperand2.length();

    if (OperandOneLength < OperandTwoLength)
    {
        for (int i = 0 ; i < OperandTwoLength - OperandOneLength ; i++)
            BinaryOperand1 = '0' + BinaryOperand1;
        return OperandTwoLength;
    }
    else if (OperandOneLength > OperandTwoLength)
    {
        for (int i = 0 ; i < OperandOneLength - OperandTwoLength ; i++)
            BinaryOperand2 = '0' + BinaryOperand2;
    }
    return OperandOneLength;
}

void BinayAdder::add()
{
    string Result;

    int LengthOfBinNumbers = MakeEqualLenghts();

    int carry = 0;  // Initialize carry

    // Add all bits one by one
    for (int i = LengthOfBinNumbers-1 ; i >= 0 ; i--)
    {
        int firstBit = BinaryOperand1.at(i) - '0';
        int secondBit = BinaryOperand2.at(i) - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        Result = (char)sum + Result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    if (carry)
        Result = '1' + Result;
    cout << Result;
}

void BinayAdder::sub()
{
    string Result;

    int LengthOfBinNumbers = MakeEqualLenghts();

    int borrow = 0;  // Initialize borrow

    int flag=0;

    for(int i=0 ; i< LengthOfBinNumbers; i++)
    {
        if(BinaryOperand2[i] == '1')
        {
            BinaryOperand2[i] = '0';
        }
        else
        {
            BinaryOperand2[i] = '1';
        }
    }

    Result.append(addtosub(0, LengthOfBinNumbers));

    cout << Result;

}

string BinayAdder::addtosub(int c,int Length)
{
    string Result;
    int carry = c;  // Initialize carry

    // Add all bits one by one
    for (int i = Length-1 ; i >= 0 ; i--)
    {
        int firstBit = BinaryOperand1.at(i) - '0';
        int secondBit = BinaryOperand2.at(i) - '0';

        // boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';

        Result = (char)sum + Result;

        // boolean expression for 3-bit addition
        carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
    }

    // if overflow, then add a leading 1
    string Result1;
    if (carry)
      {
          for(int i = Length-1 ; i>=0 ; i--)
          {
            int firstBit = Result.at(i) - '0';
            int secondBit = carry;
            carry = 0;

        // boolean expression for sum of 3 bits
            int sum = (firstBit ^ secondBit ^ carry)+'0';

            Result1 = (char)sum + Result1;

        // boolean expression for 3-bit addition
            carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
          }
      }
    return Result1;
}

void BinayAdder::ReadOperands()
{
    cout << "Enter the First Operand" << endl;
    cin >> BinaryOperand1;
    cout << "Enter the Second Operand" << endl;
    cin >> BinaryOperand2;
}
