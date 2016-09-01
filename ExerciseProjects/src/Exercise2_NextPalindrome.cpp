#include "Exercise2_NextPalindrome.h"

#include <vector>
#include <iostream>

Exercise2_NextPalindrome::Exercise2_NextPalindrome()
{
    //ctor
}

Exercise2_NextPalindrome::~Exercise2_NextPalindrome()
{
    //dtor
}

//Checks For Palindrome
bool Exercise2_NextPalindrome::isPalindrome()
{
    int checkNumber = 0;
    int Backup = CurrentNumber;
    int reminder = 0;
    while(Backup)
    {
        reminder = Backup % 10;
        checkNumber = (checkNumber * 10) + reminder;
        Backup = Backup / 10;
    }
    if(CurrentNumber == checkNumber)
    {
        return true;
    }
    return false;
}

//Returns the number of Digits in the Number
void Exercise2_NextPalindrome::getNumberOfDigits(int NumberSource)
{
    int CountOfDigits=0;
    while(NumberSource)
    {
        NumberSource = NumberSource / 10;
        CountOfDigits++;
    }
    NumberOfDigits = CountOfDigits;
}

//Returns each Digit from the Number
int Exercise2_NextPalindrome::getEachDigit(int NumberSource)
{
    return (NumberSource % 10);
}

//Increments the Number with Modulus 10 and increments the Next digit also for Carry
bool Exercise2_NextPalindrome::IncrementTillTen(std::vector<int> &Source, int position)
{
    if(Source[position]==9)
    {
        Source[position]=0;
        IncrementTillTen(Source,position-1);
    }
    else
    {
        Source[position]++;
    }
    return true;
}

//Merges the Digits back to the Whole Number
int Exercise2_NextPalindrome::MergeToNumber(std::vector<int> Source)
{
    int Lenght = NumberOfDigits;
    int Multiplier = 1;

    while(Lenght-1)
    {
        Multiplier = Multiplier * 10;
        Lenght--;
    }

    std::vector<int>::iterator it = Source.begin();
    int MergedNumber = *it * Multiplier;
    Multiplier = Multiplier / 10;
    for(it = Source.begin()+1 ; it != Source.end(); it++)
    {
        MergedNumber = MergedNumber + (*it * Multiplier);
        Multiplier = Multiplier / 10;
    }
    return MergedNumber;
}

//Returns the Next Palindrome Number
void Exercise2_NextPalindrome::NextPalindrome()
{
    std::vector<int> DigitArray;

    if(DigitArray.empty())
    {
        //Stores the Each digit to the Vector
        std::vector<int>::iterator head = DigitArray.begin();
        int Mid = NumberOfDigits/2;
        int NumberSource = CurrentNumber;
        while(NumberSource)
        {
            DigitArray.insert(DigitArray.begin(),getEachDigit(NumberSource));
            NumberSource = NumberSource / 10;
        }

        int indexFront = 0;
        int indexBack = NumberOfDigits-1 ;

        //checks extreme digits and calculate the palindrome
        while( indexBack > indexFront )
        {

            if(DigitArray[indexFront] == DigitArray[indexBack])
            {
                indexFront++;
                indexBack--;

            }
            else
            {

                if(DigitArray[indexFront] > DigitArray[indexBack])
                {
                    int diff = DigitArray[indexFront] - DigitArray[indexBack];
                    DigitArray[indexBack] = DigitArray[indexBack] + diff;
                }
                else
                {
                    if(DigitArray[indexBack] < 9)
                    {
                        DigitArray[indexBack]++;
                    }
                    else
                    {
                        DigitArray[indexBack] = 0;
                        IncrementTillTen(DigitArray,indexBack-1);
                    }
                }
            }
        }
        int Number = MergeToNumber(DigitArray);
        CurrentNumber = Number;
    }
}

//Execution of the Process
void Exercise2_NextPalindrome::Execute()
{
    ReadInput();

    if(isPalindrome())
    {
        CurrentNumber++;
    }
    for(int i=0 ; i<100 ; i++)
    {
        getNumberOfDigits(CurrentNumber);

        NextPalindrome();

        Output();

        CurrentNumber++;
    }

}

//Reading the Input
void Exercise2_NextPalindrome::ReadInput()
{
    std::cout << "Enter the Number" << std::endl;
    std::cin >> CurrentNumber;
}

//Output of the program
void Exercise2_NextPalindrome::Output()
{
    std::cout << CurrentNumber << std::endl;
}
