#include "HexAdder.h"
#include <iostream>
#include <cmath>

HexAdder::HexAdder()
{
    //ctor
}

HexAdder::HexAdder(std::string op1,std::string op2)
{
    HexOperand1 = op1;
    HexOperand2 = op2;

    std::cout << "Enter 1--> Add the numbers \t 2--> Subtract the numbers" << std::endl;
    int choice;
    std::cin >> choice;

    switch(choice)
    {
        case 1: add();
                break;
        case 2: sub();
                break;
    }
}

HexAdder::~HexAdder()
{
    //dtor
}

void HexAdder::add()
{
    long numberone = Hexa_decimal(HexOperand1);
    long numberTwo = Hexa_decimal(HexOperand2);

    long R = numberone + numberTwo;

    std::string Result = decimal_Hexa(R);

    std::cout << Result;
}

void HexAdder::sub()
{
    long numberone = Hexa_decimal(HexOperand1);
    long numberTwo = Hexa_decimal(HexOperand2);

    long R = numberone - numberTwo;

    std::string Result = decimal_Hexa(R);

    std::cout << Result;
}

std::string HexAdder::decimal_Hexa(long n)
{
    int rem =0;
    std::string s = "";
    while (n>0)
    {
        rem=n%16;
        if (rem>9)
        {
            switch (rem)
            {
                case 10: s = "A" + s; break;
                case 11: s = "B" + s; break;
                case 12: s = "C" + s; break;
                case 13: s = "D" + s; break;
                case 14: s = "E" + s; break;
                case 15: s = "F" + s; break;
            }
        }
        else
            s = char(rem + 48) + s; // x + 48 is the ascii code for x digit (if 0 <= x <= 9)
        n=n/16;
    }
    if(s == "") //if the number was 0, the string will remain empty
        return "0";
    else
        return s;
}

long HexAdder::Hexa_decimal(std::string Number)
{
    unsigned long result = 0;
    for (int i=0; i<Number.length(); i++)
    {
        if (Number[i]>='0' && Number[i]<='9')
        {
            result += (Number[i]-48)*pow(16,Number.length()-i-1);
        }
        else if (Number[i]>='A' && Number[i]<='F')
        {
            result += (Number[i]-55)*pow(16,Number.length( )-i-1);
        }
    }
    return result;
}
