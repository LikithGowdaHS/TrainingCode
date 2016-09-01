#include "Exercise3_DifferentBaseNumbersOperations.h"

#include "../../DifferentNumberBaseOpertaion/include/BinayAdder.h"
#include "../../DifferentNumberBaseOpertaion/include/HexAdder.h"
#include "../../DifferentNumberBaseOpertaion/include/OctaAdder.h"

#include <iostream>

Exercise3_DifferentBaseNumbersOperations::Exercise3_DifferentBaseNumbersOperations()
{
    //ctor
}

Exercise3_DifferentBaseNumbersOperations::~Exercise3_DifferentBaseNumbersOperations()
{
    //dtor
}

//Conversion from String to Number
int Exercise3_DifferentBaseNumbersOperations::stringToNumber(std::string Source)
{
    int Number = 0;

    int StringLength = Source.length();
    int Mulitplier = 1;
    for(int i = 0; i<StringLength ; i++)
    {
        Number = Number + ((Source[i] - '0') * Mulitplier);
        Mulitplier = Mulitplier * 10;
    }
    return Number;
}

//Reads the Input
void Exercise3_DifferentBaseNumbersOperations::ReadInput()
{
    std::cout << "Enter the First Operand" << std::endl;
    std::cin >> FirstOperand;

    std::cout << "Enter the Second Operand" << std::endl;
    std::cin >> SecondOperand;
}

//Execution of the Process
void Exercise3_DifferentBaseNumbersOperations::Execute()
{
    std::cout << "Enter 1-->Binary \t 2-->Octa decimal \t 3-->Hexa decimal" << std::endl;
    int choicebase;
    std::cin >> choicebase;

    ReadInput();

    int op1=0;
    int op2=0;

    switch(choicebase)
    {
        case 1: ObjPtr = new BinayAdder(FirstOperand, FirstOperand);
                break;
        case 2: op1 = stringToNumber(FirstOperand);
                op2 = stringToNumber(SecondOperand);
                ObjPtr = new OctaAdder(op1 , op2);
                break;
        case 3: ObjPtr = new HexAdder(FirstOperand, SecondOperand);
                break;
    }
}

void Exercise3_DifferentBaseNumbersOperations::Output()
{

}
