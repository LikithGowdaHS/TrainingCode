#ifndef OCTAADDER_H
#define OCTAADDER_H

#include <Adder.h>


class OctaAdder : public Adder
{
    public:
        OctaAdder();
        virtual ~OctaAdder();
        void add();
        void sub();
        void ReadOperands();
        int decimal_octal(int n);
        int octal_decimal(int n);

    protected:

    private:
        int OctaOperand1;
        int OctaOperand2;
};

#endif // OCTAADDER_H
