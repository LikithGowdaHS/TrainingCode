#ifndef ADDER_H
#define ADDER_H

template <class T>
class Adder
{
    public:
        Adder();
        ~Adder();
        virtual void add()=0;
        virtual void sub()=0;
        void ReadOperands();

    protected:
        T OperandOne;
        T OperandTwo;

    private:

};

#endif // ADDER_H
