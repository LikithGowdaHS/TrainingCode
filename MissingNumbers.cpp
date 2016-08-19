#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool isPresent(int sourceArray[],int length,int value){
    for(int i=0;i<length;i++){
        if(sourceArray[i] == value){
            return true;
        }
    }
    return false;
}

int getCount(int sourceArray[],int length,int value){
    int countValue=0;
    for(int i=0 ; i < length ; i++){
        if(sourceArray[i]==value){
            countValue++;
        }
    }
    return countValue;
}

int main()
{
    int arrasizeA;
    cin >> arrasizeA;

    set<int> uniqueSet;
    set<int>::iterator nxt;
    std::pair<set<int>::iterator,bool> ret;

    int arrayOfNumbersA[arrasizeA];
    for(int i=0;i<arrasizeA;i++){
        cin >> arrayOfNumbersA[i];
        uniqueSet.insert(arrayOfNumbersA[i]);
    }

    /*ret = uniqueSet.insert(20);
    if (ret.second==false) nxt=ret.first;*/

    int arrasizeB;
    cin >> arrasizeB;

    int arrayOfNumbersB[arrasizeB];
    for(int i=0;i<arrasizeB;i++){
        cin >> arrayOfNumbersB[i];
        uniqueSet.insert(arrayOfNumbersB[i]);
    }
    for(nxt=uniqueSet.begin(); nxt!=uniqueSet.end(); ++nxt){
            int countOne=0;
            int countTwo=0;
        if(isPresent(arrayOfNumbersA,arrasizeA,*nxt)){
            countOne = getCount(arrayOfNumbersA,arrasizeA,*nxt);
            countTwo = getCount(arrayOfNumbersB,arrasizeB,*nxt);
            if(countOne==countTwo){
                uniqueSet.erase(nxt);
            }
        }
    }

    for (nxt=uniqueSet.begin(); nxt!=uniqueSet.end(); ++nxt)
    std::cout << *nxt << ' ' ;
    return 0;
}
