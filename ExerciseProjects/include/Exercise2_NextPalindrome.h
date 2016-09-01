#ifndef EXERCISE2_NEXTPALINDROME_H
#define EXERCISE2_NEXTPALINDROME_H

#include <Exercise0Base.h>
#include <vector>


class Exercise2_NextPalindrome : public Exercise0Base
{
    public:
        Exercise2_NextPalindrome();
        bool isPalindrome();
        void getNumberOfDigits(int NumberSource);
        int getEachDigit(int NumberSource);
        bool IncrementTillTen(std::vector<int> &Source , int position);
        int MergeToNumber(std::vector<int> Source);
        void NextPalindrome();
        void ReadInput();
        void Execute();
        void Output();
        virtual ~Exercise2_NextPalindrome();

    protected:

    private:
        int CurrentNumber;
        int NumberOfDigits;
};

#endif // EXERCISE2_NEXTPALINDROME_H
