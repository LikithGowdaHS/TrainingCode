#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    int countCuts=n;
    while(countCuts>0){
        int min=9999;
        for(int i=0;i < n;i++){
            
            if(arr[i]<min && arr[i]>0)
                min=arr[i];
        }
        cout << countCuts<<endl;
        for(int i=0;i<n;i++){
                arr[i]= arr[i]-min;
        }
        for(int i=0;i<n;i++)
            if(arr[i]==0){
                countCuts--;
        }
    }
    return 0;
}
