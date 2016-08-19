#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int wrappersToChocolates(int wrappers, int m){
    int count = wrappers/m;
    return count;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        
        int numberOfChocolates = n/c;
        int tempCount = numberOfChocolates;
        int tempChocolate;
        while (tempCount>=m){
            tempChocolate = 0;
            tempChocolate = wrappersToChocolates(tempCount, m);
            tempCount = tempCount%m;
            tempCount = tempCount + tempChocolate;
            numberOfChocolates = numberOfChocolates+tempChocolate;
        }
        cout << numberOfChocolates << endl;
        
    }
    return 0;
}
