#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
   
    string s;
    cin>>s;
    
    int countchar[26]= {0};
     
    int flag = 0;
    // Assign Flag a value of 0 or 1 depending on whether or not you find what you are looking for, in the given string 
    int stringLength = s.length();
    
    
    for(int i=0 ; i<stringLength; i++){
        countchar[s[i]-'a']++;
    }
    
    for(int i=0;i<26;i++){
        if(countchar[i]%2!=0){
            flag++;
        }
    }
    
    if(flag>1)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;
}
