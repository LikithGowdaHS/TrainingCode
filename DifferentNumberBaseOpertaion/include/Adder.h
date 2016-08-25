#ifndef ADDER_H
#define ADDER_H

class Adder
{
    public:
        Adder();
        ~Adder();
        virtual void add()=0;
        virtual void sub()=0;
        void ReadOperands();

    protected:
        char OperandOne[100];
        char OperandTwo[100];

    private:

};

#endif // ADDER_H
