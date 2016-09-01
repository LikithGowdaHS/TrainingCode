#include <iostream>

#include "Exercise0Base.h"
#include "Exercise1_MissingAlphabet.h"
#include "Exercise2_NextPalindrome.h"
#include "Exercise3_DifferentBaseNumbersOperations.h"
#include "Exercise4_CopyFileStructure.h"

using namespace std;

int main()
{
    cout << "Enter \n 1---> Missing Alphabet in the String  \t\t 2---> Next Hundred Palindrome Numbers " << endl;
    cout << " 3---> Different Base Numbers Operations  \t 4---> File Structure Copying" << endl;
    int choice;
    cin >> choice;

    Exercise0Base *BasicPointer;
    switch(choice)
    {
        case 1: BasicPointer = new Exercise1_MissingAlphabet();
                BasicPointer->Execute();
                break;
        case 2: BasicPointer = new Exercise2_NextPalindrome();
                BasicPointer->Execute();
                break;
        case 3: BasicPointer = new Exercise3_DifferentBaseNumbersOperations();
                BasicPointer->Execute();
                break;
        case 4: BasicPointer = new Exercise4_CopyFileStructure();
                BasicPointer->Execute();
                break;
    }
    delete BasicPointer;
    return 0;
}
