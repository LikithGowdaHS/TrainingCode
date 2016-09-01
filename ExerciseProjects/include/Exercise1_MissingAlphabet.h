#ifndef EXERCISE1_MISSINGALPHABET_H
#define EXERCISE1_MISSINGALPHABET_H

#include <Exercise0Base.h>
#include <string>
#define NUMBEROFALPHABETS 26

class Exercise1_MissingAlphabet : public Exercise0Base
{
    public:
        Exercise1_MissingAlphabet();
        virtual ~Exercise1_MissingAlphabet();
        void getLowerCase();
        int CheckForAllCharacters(int PositionOfArray);
        void ReadingFromConsole();
        void ReadingFromFile();
        void ReadInput();
        bool LoggingEachAlpa();
        void getMissingAlpha();
        void Execute();
        void Output();

    protected:

    private:
        std::string SourceString;
        bool ReferenceArray[NUMBEROFALPHABETS];
        char MissingAlphabet;
        bool CheckForAllAlphaPresent;
};

#endif // EXERCISE1_MISSINGALPHABET_H
