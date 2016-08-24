#include <iostream>
#include <vector>

using namespace std;

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

int getEachDigit(int NumberSource)
{
    return (NumberSource % 10);
}

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

int NextPalindrom(int NumberSource , int NumberOfDigits)
{
    vector<int> DigitArray;
    int Mid = NumberOfDigits/2;
    while(NumberSource)
    {
        DigitArray.insert(DigitArray.begin(),getEachDigit(NumberSource));
        NumberSource = NumberSource / 10;
    }

    int indexFront = 0;
    int indexBack = NumberOfDigits-1 ;

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
    for(vector<int>::iterator iterateFront = DigitArray.begin() ; iterateFront != DigitArray.end() ; iterateFront++)
    {
        cout << *iterateFront;
    }
    return 0;
}

int main()
{
    cout << "Enter the Number" << endl;

    int CurrentNumber;
    cin >> CurrentNumber;

    int NumberOfDigits = getNumberOfDigits(CurrentNumber);

    if(isPalindrome(CurrentNumber))
    {
        CurrentNumber++;
    }

    NextPalindrom(CurrentNumber,NumberOfDigits);

    return 0;
}
