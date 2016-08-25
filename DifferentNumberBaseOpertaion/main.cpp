#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "BinayAdder.h"
#include "OctaAdder.h"
#include "HexAdder.h"

using namespace std;

int stringtoNumber(string source)
{
    int Number = 0;

    int StringLength = source.length();
    int Mulitplier = 1;
    for(int i = 0; i<StringLength ; i++)
    {
        Number = Number + ((source[i] - '0') * Mulitplier);
        Mulitplier = Mulitplier * 10;
    }
    return Number;
}

int main()
{
    cout << "Enter 1-->Binary \t 2-->Octa decimal \t 3-->Hexa decimal" <<endl;
    int choicebase;
    cin >> choicebase;

    cout << "Enter the First Operand" << endl;
    string FirstOperand;
    cin >> FirstOperand;

    cout << "Enter the Second Operand" << endl;
    string SecondOperand;
    cin >> SecondOperand;

    int op1=0;
    int op2=0;

    BinayAdder *BinOjb;
    OctaAdder *OctOjb;
    HexAdder *HexObj;


    switch(choicebase)
    {
        case 1: BinOjb = new BinayAdder(FirstOperand, FirstOperand);
                return 0;
        case 2: op1 = stringtoNumber(FirstOperand);
                op2 = stringtoNumber(SecondOperand);
                OctOjb = new OctaAdder(op1 , op2);
                return 0;
        case 3: HexObj = new HexAdder(FirstOperand, SecondOperand);
                break;
    }
    return 0;
}
