#ifndef EXERCISE3_DIFFERENTBASENUMBERSOPERATIONS_H
#define EXERCISE3_DIFFERENTBASENUMBERSOPERATIONS_H

#include <Exercise0Base.h>
#include <string>

#include "../../DifferentNumberBaseOpertaion/include/Adder.h"


class Exercise3_DifferentBaseNumbersOperations : public Exercise0Base
{
    public:
        Exercise3_DifferentBaseNumbersOperations();
        void ReadInput();
        void Execute();
        void Output();
        int stringToNumber(std::string Source);
        virtual ~Exercise3_DifferentBaseNumbersOperations();

    protected:

    private:
        Adder *ObjPtr;
        std::string FirstOperand;
        std::string SecondOperand;

};

#endif // EXERCISE3_DIFFERENTBASENUMBERSOPERATIONS_H
