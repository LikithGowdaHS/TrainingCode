#include <iostream>
#include <vector>

using namespace std;

//Checks For Palindrome
bool isPalindrome(int Number)
{
    int checkNumber = 0;
    int Backup = Number;
    int reminder = 0;
    while(Number)
    {
        reminder = Number % 10;
        checkNumber = (checkNumber * 10) + reminder;
        Number = Number / 10;
    }
    if(Backup == checkNumber)
    {
        return true;
    }
    return false;
}

//Returns the number of Digits in the Number
int getNumberOfDigits(int NumberSource)
{
    int CountOfDigits=0;
    while(NumberSource)
    {
        NumberSource = NumberSource / 10;
        CountOfDigits++;
    }
    return CountOfDigits;
}

//Returns each Digit from the Number
int getEachDigit(int NumberSource)
{
    return (NumberSource % 10);
}

//Increments the Number with Modulus 10 and increments the Next digit also for Carry
bool IncrementTillTen(vector<int> &Source, int position)
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
int MergeToNumber(vector<int> Source, int NumberOfDigits)
{
    int Lenght = NumberOfDigits;
    int Multiplier = 1;

    while(Lenght-1)
    {
        Multiplier = Multiplier * 10;
        Lenght--;
    }

    vector<int>::iterator it = Source.begin();
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
int NextPalindrom(int NumberSource , int NumberOfDigits)
{
    vector<int> DigitArray;

    if(DigitArray.empty())
    {
        //Stores the Each digit to the Vector
        vector<int>::iterator head = DigitArray.begin();
        int Mid = NumberOfDigits/2;
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
        int Number = MergeToNumber(DigitArray,NumberOfDigits);
        return Number;
    }

}

int main()
{
    cout << "Enter the Number" << endl;

    int CurrentNumber;
    cin >> CurrentNumber;

    if(isPalindrome(CurrentNumber))
    {
            CurrentNumber++;
    }

    int NumberOfDigits;

    //Next 100 Palindrome
    for(int i=0 ; i<100 ; i++)
    {
        NumberOfDigits = getNumberOfDigits(CurrentNumber);

        int NextPalindromeNumber = NextPalindrom(CurrentNumber,NumberOfDigits);
        CurrentNumber = 0;
        CurrentNumber = NextPalindromeNumber;
        cout << CurrentNumber << endl;
        CurrentNumber++;
    }
    return 0;
}
