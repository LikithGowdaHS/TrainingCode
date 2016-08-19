#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

bool isRedundent(vector<int>& arr, int value){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==value){
            return true;
        }
    }
    return false;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sizeOfSet;
    cin >> sizeOfSet;
    int divisor;
    cin >> divisor;
    int SetOfNumbers[sizeOfSet];
    vector<int> subset(sizeOfSet);
    for(int i=0;i<sizeOfSet;i++){
        cin >> SetOfNumbers[i];
    }
    int countnumber=0;
    for(int i=0;i<sizeOfSet;i++){
        int value = 0;
        for(int j=i+1; j<sizeOfSet;j++){
                value=SetOfNumbers[i]+SetOfNumbers[j];
            if(value%divisor!=0){
                if(!isRedundent(subset, SetOfNumbers[i])){
                            subset.insert(subset.end(),SetOfNumbers[i]);
                             if(!isRedundent(subset, SetOfNumbers[j])){
                                    subset.insert(subset.end(),SetOfNumbers[j]);
                             }
                        }
                }
        }
    }
    cout << subset.size();

    return 0;
}


