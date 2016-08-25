#ifndef BINAYADDER_H
#define BINAYADDER_H

#include <Adder.h>
#include <string>


class BinayAdder : public Adder
{
    public:
        BinayAdder();
        BinayAdder(std::string op1, std::string op2);
        virtual ~BinayAdder();
        void add();
        std::string addtosub(int c, int Length);
        void sub();
        void ReadOperands();
        int MakeEqualLenghts();

    protected:

    private:
        std::string BinaryOperand1;
        std::string BinaryOperand2;

};

#endif // BINAYADDER_H
