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

int MergeToNumber(vector<int> &Source, int NumberOfDigits)
{
    /*vector<int>::iterator position = Source.end();
    cout << *position;*/
    //int Lenght = Source.size();
    int Multiplier = 1;
    int MergedNumber = 1;
    //for(position = Source.end() ; position != Source.begin() ; position--)
    for(int i=NumberOfDigits-1; i>=0 ; i--)
    {
        MergedNumber = (MergedNumber*Multiplier) + Source[i];
        cout << Source[i];
        Multiplier = Multiplier * 10;
    }
    return MergedNumber;
}



int NextPalindrom(int NumberSource , int NumberOfDigits)
{
    vector<int> DigitArray;
    DigitArray.clear();
    if(DigitArray.empty())
    {
        vector<int>::iterator head = DigitArray.begin();
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
    int Number = MergeToNumber(DigitArray,NumberOfDigits);
    //cout << Number;
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

    //for(int i=0 ; i<10 ; i++)
    //{
        int NumberOfDigits = getNumberOfDigits(CurrentNumber);

        int NextPalindromeNumber = NextPalindrom(CurrentNumber,NumberOfDigits);
        CurrentNumber = 0;
        CurrentNumber = NextPalindromeNumber;
        cout << CurrentNumber << "Hello"  << endl;
        CurrentNumber++;
    //}
    return 0;
}
