#include <iostream>
#include "BinayAdder.h"
#include "OctaAdder.h"

using namespace std;

int main()
{
    cout << "Enter 1-->Binary \t 2-->Octa decimal \t 3-->Hexa decimal" <<endl;
    int choicebase;
    cin >> choicebase;

    BinayAdder *BinOjb = new BinayAdder();
    OctaAdder *OctOjb = new OctaAdder();

    switch(choicebase)
    {
        case 1: BinOjb->ReadOperands();
                BinOjb->~BinayAdder();
                return 0;
        case 2: OctOjb->ReadOperands();
                return 0;
        //case 3: break;
    }
    return 0;
}
