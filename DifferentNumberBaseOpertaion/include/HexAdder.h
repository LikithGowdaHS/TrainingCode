#ifndef HEXADDER_H
#define HEXADDER_H

#include <Adder.h>
#include <string>
#include <iomanip>

class HexAdder : public Adder
{
    public:
        HexAdder();
        HexAdder(std::string op1,std::string op2);
        void add();
        void sub();
        std::string decimal_Hexa(long n);
        long Hexa_decimal(std::string);
        virtual ~HexAdder();

    protected:

    private:
        std::string HexOperand1;
        std::string HexOperand2;
};

#endif // HEXADDER_H
